#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
const int maxn = 4e5 + 10;
#define pr pair<int, int> 
#define mk make_pair
int n, m, k;

struct edge{
    int u, v, w;
    int id;
    void add(int u, int v, int w, int id){
        this->u = u;
        this->v = v;
        this->w = w;
        this->id = id;
    }
    friend bool operator < (edge x, edge y){
        return x.w < y.w;
    };
}ed[maxn];

int fa[maxn];
int fd(int x){
    if(fa[x] == x) return x;
    return fa[x] = fd(fa[x]);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m >> k;

        for(int i = 1; i <= n; i++) fa[i] = i;
  
        for(int i = 1; i <= m; i++){
            int u, v, w;
            cin >> u >> v >> w;
            ed[i].add(u, v, w, i);
        }
        sort(ed + 1, ed + 1 + m);

        int cnt = 0;
        ll ans = 0;
        vector<int> tmp;
        for(int i = 1; i <= m; i++){
            if(cnt >= n - k - 1 && ed[i].w > 1) break;
            int fu = fd(ed[i].u), fv = fd(ed[i].v);
            if(fu == fv) continue;
            ans += ed[i].w;
            fa[fu] = fv;
            cnt++;
            tmp.push_back(ed[i].id);
        }
        vector<pr> print;
        for(int i = 1; i < n; i++){
            if(fd(i) != fd(i + 1)) {
                print.push_back(mk(i, i + 1));
                fa[fd(i)] = fa[fd(i + 1)];
            }
        }
        cout << print.size() << "\n";
        for(auto [i, j] : print) cout << i << " " << j << "\n";
        cout << ans + print.size() << endl;
        for(auto x : tmp) cout << x << " ";
        for(int i = 0; i < print.size(); i++) cout << i + m + 1 << " ";
        cout << endl;
    }

	return 0;
}
