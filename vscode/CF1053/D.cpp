#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
const int mod = 998244353;
int t;
int n, a[maxn];

ll Cxy(int x, int y){
    return num[x]/num[y]/
}

ll work(){
    ll now = 0;
    for(int i = 1; i <= n; i++){
        if(i * 2 == n + 1) now++;
        else now += 2;

    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        ll ans = work() % mod;
        cout << ans << endl;
    }


	return 0;
}
