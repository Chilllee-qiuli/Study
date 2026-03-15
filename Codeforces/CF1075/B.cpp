#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int n;
ll x;

ll s_o(){
    cin >> n >> x;

    ll maxx = 0;
    for(int i = 1; i <= n; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        x -= max(0ll, a * (b - 1));
        ll tmp = a * b - c;
        maxx = max(maxx, tmp);
    }
    if(x <= 0) return 0;
    if(maxx == 0) return -1;
    ll ans = x / maxx; 
    // 更好的写法： return (x + maxx - 1) / maxx;

    if(x % maxx) ans++;
    return ans;


}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T--) cout << s_o() << endl;


    return 0;
}