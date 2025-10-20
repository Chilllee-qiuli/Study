#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll a, b;

int main(){
    freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> a >> b;

        if(a & 1){
            if(b & 1){
                cout << a*b + 1 << endl;
                continue;
            }
            else if(b % 4 != 0) cout << -1 << endl;
            else {
                a *= b/2;
                b = 2;
                cout << a + b << endl;
            }
        }
        else {
            if(b % 2 != 0) cout << -1 << endl;
            else {
                a *= b/2;
                b = 2;
                cout << a + b << endl;
            }
        }
    }

	return 0;
}
