#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 1;



ll p, q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        cin >> p >> q;
        ll tmp = p * 2 + q * 4 + 1;
        int flag = 0;
        for(ll i = 3; i * i <= tmp; i += 2){
            if(tmp % i == 0){
                ll j = tmp / i;
                if(j % 2 == 1 && j - i <= p * 2){
                    flag = 1;
                    cout << (i - 1) / 2 << " " << (j - 1) / 2 << "\n";
                    break;
                }
            }
        }
        if(!flag) cout << -1 << endl;
    }

	return 0;
}