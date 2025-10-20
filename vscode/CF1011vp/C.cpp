#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;

inline bool judge(ll x, ll y, ll k){
    return (x + y + 2 * k) == ((x + k) ^ (y + k));
}

void divv(ll x){
    if(x == 0) {
        cout << 0;
        return ;
    }
    else if(x == 1){cout << 1; return ;}
    divv(x/2);
    if(x % 2 == 1) cout << 1;
    else cout << 0; 
}

int main(){
    freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        ll x, y;
        cin >> x >> y;
        divv(x); cout << endl;
        divv(y); cout << endl;
        if(x == y) {
            cout << -1 << endl;
            continue;
        }
        for(ll k = 0; k <= 1e4 ; k++){
            if(judge(x, y, k)){
                divv(k); cout << endl;
                cout << "k = " << k << endl;

                break;
            }
        }
    }

	return 0;
}
