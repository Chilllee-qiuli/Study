#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll l, r;
int t;

ll solve(ll x){
    ll tmp = 0;
    while(x){
        tmp = max(tmp, x % 10);
        x /= 10;
    }
    return tmp;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        int l2, r2;
        cin >> l >> r >> l2 >> r2;
        l += l2; r += r2;
        if(r - l + 1 >= 10) cout << 9 << endl;
        else{
            ll ans = 0;
            for(; l <= r; l++) ans = max(ans, solve(l));
            
            cout << ans << endl;
        }
    }

	return 0;
}
