#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;
int n;
int w[maxn];
int siz[maxn];
int anc[maxn][23];
int dth[maxn];
int f[maxn];
int cnt[maxn], cnt_sum[maxn];// 用于处理两点成链的情况    cnt_sum 存储一个点的含有相同颜色的子树的大小之和
vector<int> col[maxn];
vector<int> mp[maxn];

void dfs(int u, int fa){
    siz[u]++;
    dth[u] = dth[fa] + 1;
    f[u] = fa;
    cnt[w[u]]++;
    int precnt = cnt[w[u]];
    for(auto v : mp[u]){
        if(fa == v) continue;
        dfs(v, u);
        siz[u] += siz[v];
        anc[v][0] = u;  
        if(cnt[w[u]] > precnt){
            precnt = cnt[w[u]];
            cnt_sum[u] += siz[v];
        }
    }   
}
void pre(){
    for(int j = 1; j <= 20; j++)
    for(int i = 1; i <= n; i++)
    anc[i][j] = anc[anc[i][j-1]][j-1];
}

int LCA(int x, int y){
    if(dth[x] < dth[y]) swap(x, y);
    
    for(int i = 18; i >= 0; i--)
        if(dth[anc[x][i]] >= dth[y]) x = anc[x][i];
    if(x == y) return y;
    for(int i = 18; i >= 0; i--)
        if(anc[x][i] != anc[y][i])
        x = anc[x][i], y = anc[y][i];
    return anc[x][0];
}

int main(){
    //freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> w[i];
        col[w[i]].push_back(i);
    } 
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }

    dfs(1, 0);
    pre();

    for(int i = 1; i <= n; i++){
        ll ans = 1;
        if(!col[i].size()) cout << ans * (n - 1) * n / 2 << endl; // 没有结点，任选2个
        else if(col[i].size() == 1){ 
            /* 只有一个结点，答案为三者相加：
                1. 在他父亲子树和儿子各选一个
                2. 选他和其他一个结点
                3. 他的子树之间选两个子树各选一个*/

            ll tmp = 0, sum = siz[col[i][0]] - 1; // 这里处理3.
            for(auto v : mp[col[i][0]]){
                if(v == f[col[i][0]]) continue;
                sum -= siz[v];
                tmp += 1ll * siz[v] * sum;
            }

            cout << ans * (siz[col[i][0]] - 1) * (n - siz[col[i][0]]) + n - 1 + tmp << endl;
        }
        else if(col[i].size() == 2){ 
            // 有两个的情况，先看是不是父子
             
            int u = col[i][0], v = col[i][1];
            if(dth[u] < dth[v]) swap(u, v);
            int lca = LCA(u, v);
            if(lca == v){ // 是父子，根据文末方法特殊处理
                //cout << ans * siz[u] * (n - siz[v] + 1) << endl;
                cout << ans * (n - cnt_sum[v]) * siz[u] << endl;
            }
            else {
                cout << ans * siz[u] * siz[v] << endl;
            }
        }
        else {
            // 找深度最深的两个点，不是父子关系的时候就不会是一条链
            int maxu = 0;
            for(auto u : col[i])
                if(dth[u] > dth[maxu]) maxu = u;
            
            int maxv = 0;
            for(auto v : col[i])
                if(v != maxu && LCA(maxu, v) != v && dth[v] > dth[maxv]) maxv = v;

            if(!maxv){ // 在同一条链上，根据文末方法特殊处理
                int mind = maxn, minv = 0;
                for(auto v : col[i]){
                    if(dth[v] < mind){
                        mind = dth[v];
                        minv = v;
                    }
                }
                cout << ans * siz[maxu] * (n - cnt_sum[maxv] + 1) << endl;
            }
            else {
                int flag = 1;
                int lcauv = LCA(maxu, maxv);
                for(auto x : col[i]){
                    if(x == maxu || x == maxv) continue;
                    if(dth[x] < dth[lcauv]) flag = 0;
                    if(LCA(x, maxu) != x && LCA(x, maxv) != x) flag = 0;
                    if(!flag) break;
                }
                if(!flag) cout << 0 << endl;
                else cout << ans * siz[maxu] * siz[maxv] << endl;
            }
        }
    }


	return 0;
}
/*
对于一条父子关系链的情况，不妨设最深最浅结点分别为 u，v. 我第一发漏思考了 v 除了父亲子树的结点，其非这条链所在的子树结点也能选。
这个时候比较难处理，在题解区看到一个很牛的处理方法：
记录某一种颜色在搜完子树计数数量有没有变化，就知道这个子树有没有这个颜色的结点以及有多少个了，
我先入为主的以为要开 1e6 个 1e6 大小的bitset来存储，这绝对也会爆炸啊，没想到直接计数看有没有变化就完了，以前没遇到过这个方法，记录一下。
*/