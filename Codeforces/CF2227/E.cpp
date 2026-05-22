#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int a[maxn];
int f[maxn];
int t;
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            f[i] = 0;
        }
        int h = a[n], r = n;
        ll ans = 0;
        for(int i = n - 1; i >= 1; i--){
            if(a[i] >= h) {
                f[r]++;
                ans += a[i] - h;
            }
            else {
                h = a[i];
                r = i;
            }
        }
        int maxx = 0;
        for(int i = 1; i <= n; i++) maxx = max(maxx, f[i]);
        cout << ans + maxx << endl;
    }


	return 0;
}
