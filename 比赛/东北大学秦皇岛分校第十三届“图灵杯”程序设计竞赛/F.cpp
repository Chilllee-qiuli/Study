#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 110;
int n, m;
int v[maxn];
int w[maxn][maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    ll ans = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }

    for(int i = 1; i <= m; i++)
    for(int j = 1; j <= n; j++)
    cin >> w[j][i];

    for(int i = 1; i <= n; i++) sort(w[i] + 1, w[i] + 1 + m);

    for(int i = 1; i <= n; i++)
        if(w[i][m] >= v[i]) {
            ans += w[i][m];
            ans -= v[i];
        }

    

    cout << ans << endl;
    
    

	return 0;
}
