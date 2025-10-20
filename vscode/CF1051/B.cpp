#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int t;
int a[maxn], b[maxn];
int n, k;

int main(){
    //freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        ll cost = 0;
        cin >> n >> k;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            cost += a[i];
        }
        for(int i = 1; i <= k; i++) cin >> b[i];
        sort(b + 1, b + 1 + k);
        sort(a + 1, a + 1 + n, greater<int>());

        int l = 1;

        for(int i = 1; i <= k && l <= n; i++){
            if(l + b[i] - 1 > n) break;
            cost -= a[l + b[i] - 1];
            l += b[i];
        }
        cout << cost << endl;
    }

	return 0;
}
