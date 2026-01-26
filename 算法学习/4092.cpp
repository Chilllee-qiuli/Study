#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int n, q;
int tag[maxn];
int dth[maxn];
int cnt[maxn];
int f[maxn];

vector<int> g[maxn];

struct node{
    int op;
    int num;
    int ans;
}qu[maxn];

void dfs(int u, int fa, int tg){
    dth[u] = dth[fa] + 1;
    f[u] = fa;
    if(tag[u] != u) tag[u] = tg;
    for(auto v : g[u]){
        if(v == fa) continue;
        dfs(v, u, tag[u]);
    }
}

int find(int x){
    if(x == tag[x]) return x;
    else return tag[x] = find(tag[x]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        //tag[i] = 1;
    }
    //tag[n] = 1;
    tag[1] = 1;
    cnt[1] = 1;
    
    for(int i = 1; i <= q; i++){
        char op;
        int id;
        cin >> op >> id;
        if(op == 'C'){
            qu[i].op = 1;
            qu[i].num = id;
            tag[id] = id;
            cnt[id]++;
        }
        else {
            qu[i].op = 2;
            qu[i].num = id;
        }
    }

    dfs(1, 0, 1);


    for(int i = q; i; i--){
        if(qu[i].op == 2) qu[i].ans = find(qu[i].num);
        else if(cnt[qu[i].num] > 1) cnt[qu[i].num]--;
        else {
            cnt[qu[i].num] = 0;
            tag[qu[i].num] = tag[f[tag[qu[i].num]]];
        }
    }

    for(int i = 1; i <= q; i++)
    if(qu[i].op == 2) cout << qu[i].ans << endl;



	return 0;
}
