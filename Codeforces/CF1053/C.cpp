#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 4e5 + 10;
ll a[maxn];
int t;
int n;
ll ans[maxn];

int main(){
   // freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1 ; i <= n * 2; i++) {
            ans[i] = 0;
            cin >> a[i];
        }
        
        for(int i = 1; i <= n * 2; i++){
            if(i & 1) ans[1] -= a[i];
            else ans[1] += a[i];
        }
        if(n == 1){
            cout << ans[1] << endl;
            continue;
        }

        ans[2] += a[n * 2] - a[1];
        //cout << "etst: " << ans[2] << endl;
        for(int i = 2; i <= n * 2 - 1; i++){
            if(i & 1) ans[2] += a[i];
            else ans[2] -= a[i];
        }
        if(n == 2){
            cout << ans[1] << " " << ans[2] << endl;
            continue;
        }

        for(int k = 3; k <= n; k++){
            int kk = k - 1;
            ans[k] = ans[k - 2] - a[kk] * 2 + a[n * 2 - kk + 1] * 2;

        }
        for(int k = 1; k <= n; k++)
        cout << ans[k] << " ";

        cout << endl;
    }

	return 0;
}