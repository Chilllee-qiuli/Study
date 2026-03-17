#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;

ll work(ll x,ll y,ll m){
    if(y == 1) return x;
    if(y == 0) return 1;
    ll tmp = work(x, y/2, m)%m;
    if(y % 2 == 1) return tmp * tmp %m *x %m;
    else return tmp * tmp%m;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll tmp = work(26, 6, 0x3f3f3f3f3f3f3f3f);
    cout << tmp << endl;
    // for(int i = 1; i <= 100000; i++){
    //     if(tmp * i % mod == 474661742){
    //         cout << "!!!: " << i << endl;
    //         return 0;
    //     }
    // }

    cout << (tmp * 9 - 10ll * work(26, 3, 0x3f3f3f3f3f3f3f3f) - 1) % mod << endl;

    int a = 1;
    a >>= -1;
    cout << a << endl;


	return 0;
}
