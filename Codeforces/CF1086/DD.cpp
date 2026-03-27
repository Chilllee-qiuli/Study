#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pr pair<int, int>
#define mk make_pair
#define fi first
#define se second
const int maxn = 8080;
int n;
int siz[maxn], fa[maxn];

int fd(int x){
    if(fa[x] == x) return x;
    return fa[x] = fd(fa[x]); // 要把fa[x]丢入查询
}

void merge(int x, int y){
    int fx = fd(x), fy = fd(y);
    if(fx != fy) fa[fx] = fy; // 要把x的根挂给y，不是挂x，值得警醒
}


int solve(){
    cin >> n;
    vector< bitset<maxn> > bt(n + 1);
    
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        for(int j = 1; j <= n; j++)
        if(s[j - 1] == '1') bt[i].set(j);
    }
    
    for(int i = 1; i <= n; i++) if(!bt[i][i]) return 0; // 自反性验证
    
    for(int i = 1; i <= n; i++)
    for(int j = i + 1; j <= n; j++) 
    if(bt[i][j] && bt[j][i]) return 0; // 反对称性验证
    
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
    if(bt[i][j] && (bt[j] & ~bt[i]).any()) return 0; // 传递性验证
    
    for(int i = 1; i <= n; i++) siz[i] = bt[i].count();
    vector<int> ans(n);
    iota(ans.begin(), ans.end(), 1);
    sort(ans.begin(), ans.end(), [&](int x, int y){
        return siz[x] > siz[y];
    }); //一个点能够到达的节点越多说明它在原树中越浅 !! 这是一个很巧妙的性质
    vector<pr> edges;
    for(int i = 1; i <= n; i++){
        bitset<maxn> dir = bt[i];
        dir.reset(i); 
        vector<int> nn;
        for(int j : ans){
            if(j == i) continue;
            if(bt[i][j]) nn.push_back(j); 
            // 这里找到所有 i 的可达点
            // 等会会通过处理，只保留 i 的直接连结点
        }
        for(int j : nn)
        if(dir[j]){
            edges.push_back(mk(i, j));
            dir &= ~bt[j]; //去除满足 i->j->k 的所有 i->k 的边
            // 这里写法很巧妙，而且排序完由于直接儿子肯定在前面，故正确性有所保障
        }
    }
    
    if(edges.size() != n - 1) return 0; // 验证边数，要求严格等于 n - 1
    

    // 验证联通关系，不能是森林，跑一个并查集
    for(int i = 1; i <= n; i++) fa[i] = i;
    for(auto [u, v] : edges)  merge(u, v);
    int rt = fd(1);
    for(int i = 2; i <= n; i++)
    if(fd(i) != rt) return 0;
    
    cout << "YES\n";
    for(auto [u, v] : edges) cout << u << " " << v << "\n";

    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);


    int t;
    cin >> t;
    while(t--) {
        if(!solve()) cout << "No\n";
    }

	return 0;
}