#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        ll x, y;
        cin >> x >> y;
        if(x > y) swap(x, y);
        if(x == 1) {cout << -1 << endl; continue;}
        if(y - x > 1) cout << y - x << endl;
        else cout << y + 1 << endl;
    }

	return 0;
}
