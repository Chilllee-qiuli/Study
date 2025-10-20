#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll x;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> x;
        ll tmp = 10;
        while(tmp <= x) tmp *= 10;
        cout << tmp - x - 1 << endl;
    }

	return 0;
}
