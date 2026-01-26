#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int t;
int n;
int g[maxn];

int main(){
   // freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> g[i];
        sort(g + 1, g + 1 + n);
        ll ans = 0;
        for(int i = n; i >= 1; i -= 2){
            ans += g[i];
        }
        cout << ans << endl;
    }

	return 0;
}