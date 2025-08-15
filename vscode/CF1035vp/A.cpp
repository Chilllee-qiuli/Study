#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int a, b, x, y;


int main(){
    freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> a >> b >> x >> y;
        if(a - b > 1) cout << - 1 << endl;
        else if(a % 2 == 0 && a > b) cout << -1 << endl;
        else if(a == b + 1) cout << y << endl;
        else if(a == b) cout << 0 << endl;
        else {
            ll cost = 0;
            while(a < b){
                if(a % 2 == 0) cost += min(x, y);
                else cost += x;
                a++;
            }
            cout << cost << endl;
        }
    }


	return 0;
}
