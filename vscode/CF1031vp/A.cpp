#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int k, a, b, x, y;

int main(){
    freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        ll ans = 0;
        cin >> k >> a >> b >> x >> y;
        if(x > y){
            swap(a, b);
            swap(x, y);
        }
        if(k >= a){
            ans += (k - a)/x + 1;
            k -= ans * x;
        }
        if(k >= b){
            ans += (k - b)/y + 1;
        }
        cout << ans << endl;
    }   

	return 0;
}
