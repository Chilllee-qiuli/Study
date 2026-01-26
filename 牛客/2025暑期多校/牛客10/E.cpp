#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 440;
const int inf = 0x3f3f3f3f;
int t;
int n, m;
int a[maxn];
int b[maxn];

ll work_1() {
    int maxx = 0;
    for(int i = 1; i <= n; i++) maxx = max(maxx, a[i]);
    for(int i = 1; i <= n; i++) b[i] = maxx - a[i];
	ll sum = b[1];
	for(int i = 2; i <= n; i++)
	if(b[i] > b[i-1]) sum += b[i] - b[i-1];
    return sum;
}
ll work_2(int mid, int maxx){
    for(int i = 1; i <= n; i++) {
        if(a[i] <= mid) b[i] = mid - a[i];
        else b[i] = maxx - a[i];
    }
	ll sum = b[1];
	for(int i = 2; i <= n; i++) if(b[i] > b[i-1]) sum += b[i] - b[i-1];
    return sum;
}

int main(){
   // freopen("e.in", "r", stdin);
   // freopen("e1.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 1; i <= n; i++)  cin >> a[i];
        if(m == 1) {
            ll ans = work_1();
            cout << ans << endl;
        }
        else {
            int maxx = 0;
            for(int i = 1; i <= n; i++)  maxx = max(maxx, a[i]);
            ll ans = work_1();
            for(int i = 0; i <= 101; i++)
               ans = min(ans, work_2(i, maxx));
            cout << ans << endl;
        }

    }

	return 0;
}

