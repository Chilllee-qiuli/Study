#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int n, c, w;

ll cpt(ll l, ll r){
    return (l + r) * (r - l + 1) / 2;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> c >> w;
        if(w == 0) {
            cout << 0 << endl;
            continue;
        }
        if(w % c != 0 || cpt(1, n) < w / c){
            cout << -1 << endl;
            continue;
        }
        w /= c;
        ll sum = 0, l = 1;
        bool one = 0;
        for (ll r = 1; r <= n; ++r) {
            sum += r;
            while (sum > w && l <= r) {
                sum -= l;
                ++l;
            }
            if (sum == w) {
                one = 1;
                break;
            }
        }

        cout << (one ? 1 : 2) << '\n';
    }

	return 0;
}