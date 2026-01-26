#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 110;
const ll mod = 998244353;

int t;
int n;
int a[maxn], b[maxn];


int main(){
    //freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++) cin >> b[i];
        ll ans = 1;
     //   if(n == 1) ans *= 2;
        for(int i = 1; i <= n; i++){
            if(a[i] == b[i]) ans = (ans * 2) % mod;
            else if(a[i] >= a[i-1] && b[i] >= b[i-1] && a[i] >= b[i-1] && b[i] >= a[i-1]){
                ans = (ans * 2) % mod;
            }
        }
        cout << ans << endl;
    }

	return 0;
}