#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
const int maxn = 2e5 + 5;
int n, x, y;
int a[maxn];

ll cpt(int i){
    return 0ll + a[i] % x + 1ll * (x - y) * (a[i] / x);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> x >> y;
        ll cnt = 0, maxi = 0;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            if(cpt(i) > cpt(maxi)) maxi = i;
        }

        for(int i = 1; i <= n; i++){
            if(i != maxi) cnt += a[i] / x;
        }
        cout << cnt * y + a[maxi] << endl;


    }

	return 0;
}
