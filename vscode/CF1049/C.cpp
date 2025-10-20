#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;
int t;
int a[maxn];
int n;

int main(){
    freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        ll ans;
        if(n & 1) ans = n - 1;
        else ans = n - 2;
        ll minn = inf, maxx = -inf, minn_mini = 0, minn_maxi = 0, maxx_mini = 0, maxx_maxi = 0;
        
        //cout << "test " << endl;
            //cout << maxx << " " << minn << " " << maxx_mini << " " << maxx_maxi << " " << minn_mini << " " << minn_maxi << endl;
        for(int i = 1; i <= n; i++)
            if(i & 1) ans += a[i];
            else ans -= a[i];
        cout << ans << endl;

    }

	return 0;
}
