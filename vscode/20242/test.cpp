#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    //freopen("t.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int tmp = 1, ans = 0;
    for(int i = 1; i <= 32; i++, tmp *= 2){
        int x;
        cin >> x;
        if(x == 1) ans += tmp;
        else if(x) ans -= tmp;
    }
    cout << ans << endl;
    //ll x = pow(2, 31);
    //cout << x << endl;

	return 0;
}