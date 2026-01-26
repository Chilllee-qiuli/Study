#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll x;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll y;
    cin >> x >> y;
    ll tmpy = y, tmpx = x;
    int cnt = 0;
    while(tmpy){
        cnt++;
        tmpy >>= 1;
    }
    for(int i = 1; i <= cnt; i++) x *= 10;
    cout << (x + y) % (tmpx+y) << endl;

	return 0;
}
