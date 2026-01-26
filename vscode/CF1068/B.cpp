#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
ll f_min[maxn], f_max[maxn];
ll a[maxn], b[maxn];
int t;
int n;


int main(){
   // freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int j = 1; j <= n; j++) cin >> b[j];

        for(int i = 1; i <= n; i++){
            f_min[i] = min(b[i] - f_max[i - 1], f_min[i - 1] - a[i]);
            f_max[i] = max(b[i] - f_min[i - 1], f_max[i - 1] - a[i]);
        }

        cout << f_max[n] << endl;
    }

	return 0;
}
