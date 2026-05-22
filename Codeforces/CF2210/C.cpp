#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
const int maxn = 2e5 + 10;
ll a[maxn], b[maxn];
int n;

ll gcd(int i, int j){
    if(i < 1 || j > n) return 1;
    return __gcd(a[i], a[j]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++) cin >> b[i];

        int ans = 0;
        for(int i = 1; i <= n; i++){
            ll gcd1 = gcd(i - 1, i), gcd2 = gcd(i, i + 1);
            ll lcm = gcd1 * gcd2 / __gcd(gcd1, gcd2);
            // cout << lcm << " ";
            if(a[i] > lcm && b[i] >= lcm) ans++;
        }
        // cout << endl;
        cout << ans << endl;
    }

	return 0;
}
