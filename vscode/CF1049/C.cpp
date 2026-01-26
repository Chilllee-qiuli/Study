#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
int t;
int a[maxn];
int n;

int main(){
    freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        ll ans;
        if(n & 1) ans = n - 1;
        else ans = n - 2;

        ll tmp = 0;
        for(int i = 1; i <= n; i++)
        if(i & 1) tmp += a[i];
        else tmp -= a[i];

        ans += tmp;

        ll minn_even = inf, minn_odd = inf;
        for(int i = 1; i <= n; i++){
            if(i & 1){
                ans = max(ans, tmp - a[i] - a[i] + i - minn_even);
                minn_odd = min(minn_odd, 0ll + i + a[i] + a[i]);
            }
            else{
                ans = max(ans, tmp + a[i] + a[i] + i - minn_odd);
                minn_even = min(minn_even, 0ll + i - a[i] - a[i]);
            } 
        }
        

        cout << ans << endl;

    }

	return 0;
}
