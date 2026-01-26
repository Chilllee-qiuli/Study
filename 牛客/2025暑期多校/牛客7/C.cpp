#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
int t;
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        ll x = 0, maxx = -inf;
        ll ans = 0;
        for(int i = 1; i <= n; i++){
            cin >> x;
            ans = max(ans, maxx - x);
            maxx = max(maxx, x);
        }
        cout << ans << endl;
    }

	return 0;
}
