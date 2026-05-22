#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
ll a[maxn];
ll f[maxn];
ll cnt[maxn];
int t;
int n;
ll cntyuan(){

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            f[i] = 0;
            cnt[i] = 0;
        }
        cnt[n + 1] = 0;
        int h = a[n], r = n;
        f[n] = 1;
        ll ans = 0;
        for(int i = n - 1; i >= 1; i--){
            ans += a[i] * (n - i);
            if(a[i] < h) {
                h = a[i];
                r = i;
                f[r] = n - i + 1;
            }
            else f[i] = -1;
        }

        for(int i = 1; i <= n; i++){
            cnt[1]++;
            cnt[a[i] + 1]--;
        }
        for(int i = 1; i <= n; i++) {
            cnt[i] += cnt[i - 1];
            ans -= cnt[i] * (cnt[i] - 1) / 2;
        }
        // cout << "äns = " << ans << endl;        
        

        ll maxx = 0;
        for(int i = 1; i <= n; i++) 
        if(f[i] != -1){
            maxx = max(maxx, cnt[a[i]] - f[i]);
            // cout << i << " " << f[i] << endl;
        }
        // cout << endl;
        
        // cout << "maxx = " << maxx << endl;
        cout << ans + maxx << endl;
    }


	return 0;
}
