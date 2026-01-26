#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int a[maxn], b[maxn];
int t;
int n;

ll cpt(int x){
    int num = lower_bound(a + 1, a + 1 + n, x) - (a + 1);
    num = n - num; // 可用剑数
    ll ed = lower_bound(b + 1, b + 1 + n, num) - b;
    if(num != b[ed]) ed--;
    return ed * x;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++) cin >> b[i];
        for(int i = 1; i <= n; i++) b[i] += b[i - 1];
        sort(a + 1, a + n + 1);
        int l = a[1], r = a[n];
        while (r - l > 3) {
        int lmid = l + (r - l) / 3;
        int rmid = r - (r - l) / 3;
        if (cpt(lmid) <= cpt(rmid)) {
            l = lmid;   
        } else {
            r = rmid;   
        }
        }
    ll ans = LLONG_MIN;
    for (int x = l; x <= r; ++x) ans = max(ans, cpt(x));
        cout << ans << endl;
    }

	return 0;
}