#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double eps = 1e-7;
double h, c, t;

double work(ll x){
    x /= 2;
    return (h * x + c * x + h) /(2 * x + 1) - t;
}

bool judge(ll x){
    if(work(x) >= 0) return 1;
    return 0;
} 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >>T;
    while(T--){
        cin >> h >> c >> t;
        double midhc = (h + c) / 2;
        if(t < midhc || fabs(t - midhc) < eps) {
            cout << 2 << endl;
            continue;
        }

        ll l = 1, r = 1e9, tmp = 1;
        while(l <= r){
            ll mid = (l + r) >> 1;
            if(judge(mid)) tmp = l, l = mid + 1;
            else r = mid - 1;
        }
        
        double minn = fabs(work(tmp));
        ll ans = tmp ;
        for(int i = tmp ; i <= r + 3; i++){
            double now;
            if(i % 2 == 0) now = (h + c) / 2;
            else now = fabs(work(i));
            if(now < minn){
                ans = i;
                minn = now;
            }
        }
        cout << ans << "\n";
        //cout << work(ans) << endl;

    }


    return 0;
}