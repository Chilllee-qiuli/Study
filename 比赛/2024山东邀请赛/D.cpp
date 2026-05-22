#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p, a, b, q, c, d, m, t;

bool check(ll x){
    return a * x + b + c * x + d <= t;
}
ll fd(){ // 当前t的最多容纳购买数量
    ll l = 0, r = t;
    ll ans = 0;
    while(l <= r){
        ll mid = (l + r) >> 1;
        if(check(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while(T--){
        cin >> p >> a >> b >> q >> c >> d >> m >> t;

        if(m < p){
            cout << m << endl;
            continue;
        }

        if(!b && !d){
            cout << t / (a + c) * (q - p) + m << endl;
            continue;
        }
        while(t > 0){
            ll x = m / p;
            ll cnt = a * x + b + c * x + d;
            if(t >= cnt){
                t -= cnt;
                m += x * (q - p);
            }
            else {
                m += fd() * (q - p);
                break; 
            }
        }
        cout << m << endl;

    }

	return 0;
}
