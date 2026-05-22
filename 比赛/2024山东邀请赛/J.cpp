#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1010;
ll b[maxn][maxn];
int n;
ll a[maxn];
int fa[maxn];

struct node{
    int x, y;
    ll cos;
    friend bool operator < (node x, node y){
        return x.cos < y.cos;
    }
};
vector<node> vc;

void pre(){
    cin >> n;
    vector<node> ().swap(vc);
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++){
        cin >> b[i][j];
        vc.push_back({i, j, b[i][j]});
    }   

    for(int i = 1; i <= n; i++) fa[i] = i;
}
int fd(int x){
    if(x == fa[x]) return x;
    return fa[x] = fd(fa[x]);
}
void merge(int x, int y){
    int fx = fd(x), fy = fd(y);
    if(fx != fy) fa[fx] = fy;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        pre();
        
        ll ans = 0;
        for(int col = 1; col <= n; col++){
            int minn = col;
            for(int i = 1; i <= n; i++) if(b[col][i] < b[col][minn]) minn = i;

            if(minn == col) ans += (a[col] - 1) * b[col][col];
            else {
                if(fd(col) == fd(minn)) ans += (a[col] - 1) * b[col][minn];
                else ans += a[col] * b[col][minn];
                merge(col, minn);
            }
        }

        sort(vc.begin(), vc.end());

        for(auto it : vc){
            int x = it.x, y = it.y;
            ll cos = it.cos;
            int fx = fd(x), fy = fd(y);
            if(fx == fy) continue;
            ans += cos;
            merge(x, y);
        }

        cout << ans << endl;

    }

	return 0;
}
