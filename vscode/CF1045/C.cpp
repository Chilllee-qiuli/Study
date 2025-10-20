#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int n;
const int maxn = 2e5 + 10;
const int inf = 1e9 + 7;
ll a[maxn];

int main(){
    freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        a[0] = a[n+1] = inf;

        ll ans = 0;
        for(int i = 1; i <= n; i+=2){
            if(a[i] > a[i+1]) {
                ans += a[i] - a[i+1];
                a[i] = a[i+1];
            }
            if(a[i] > a[i-1]){
                ans += a[i] - a[i-1];
                a[i] = a[i-1];
            }
        }

        for(int i = 2; i <= n; i+=2){
            if(i == n){
                break;
            }
            if(a[i-1] + a[i + 1] > a[i]){
                ans += a[i-1] + a[i + 1] - a[i];
                a[i + 1] = a[i] - a[i-1];
            }
        }
        
        cout << ans << endl;
    }
    

	return 0;
}
