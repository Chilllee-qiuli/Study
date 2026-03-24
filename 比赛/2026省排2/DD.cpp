
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double eps = 1e-7;
ll h, c, t;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >>T;
    while(T--){
        cin >> h >> c >> t;
        double midhc = (h + c) / 2;
        if (2 * t <= h + c) {
            cout << 2 << '\n';
            continue;
        }

        ll k = (h - t) / (2 * t - h - c);

        ll n1 = 2 * k + 1;
        ll n2 = 2 * k + 3;

        ll d1 = llabs((k + 1) * h + k * c - t * n1);
        ll d2 = llabs((k + 2) * h + (k + 1) * c - t * n2);

        if (d1 * n2 <= d2 * n1) cout << n1 << '\n';
        else cout << n2 << '\n';



    }


    return 0;
}