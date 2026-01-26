#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int t;
ll a[maxn], ans[maxn], d[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++) d[i] = a[i] - a[i-1];
        for(int i = 1; i <= n; i++){
            ll tmp = i - d[i];
            if(tmp == 0) ans[i] = i;
            else ans[i] = ans[tmp];
        }

        for(int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
    }

	return 0;
}
