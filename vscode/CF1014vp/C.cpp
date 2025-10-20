#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int t;
int n;
int a[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        ll ans = 0;
        int odd = 0, even = 0, maxx = 0;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            maxx = max(maxx, a[i]);
            if(a[i] & 1) {
                ans += a[i] - 1;
                a[i] = 1;
                odd++;
            }
            else {
                ans += a[i];
                even++;
                a[i] = 0;
            }
        }
        if(odd == n || even == n) cout << maxx << endl;
        else {
            cout << ans + 1 << endl;
        }
        
    }

	return 0;
}