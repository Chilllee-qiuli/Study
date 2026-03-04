#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int n, k;
int w[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> w[i];
    }
    sort(w + 1, w + 1 + n);

    ll ans = 0;
    for(int i = 1; i <= max(0, n - k); i++) ans += w[i];

    cout << ans << endl;


	return 0;
}
