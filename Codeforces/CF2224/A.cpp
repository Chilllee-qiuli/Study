#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int t;
ll a[maxn];
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];

        int ans = 0;

        if(a[n] > 0) ans++;
        for(int i = n - 1; i; i--){
            if(a[i + 1] > 0) a[i] += a[i + 1];
            if(a[i] > 0) ans++;
        }

        cout << ans << endl;
    }

	return 0;
}
