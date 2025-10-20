#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
ll T;
int n;
ll maxx;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> T;
    for(int i = 1; i <= n; i++){
        ll t;
        cin >> t;
        maxx = max(maxx, t);
    }
    cout << ceil(1.0*T/maxx) << endl;

    
    return 0;
}