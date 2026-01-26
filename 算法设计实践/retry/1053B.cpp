#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e4 + 10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
ll a[maxn];

int n, k; 

// 双指针
// int32范围意思就意味着一旦运算会爆int
// 切记不开longlong见祖宗


int main(){
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];

    sort(a + 1, a + 1 + n);

    while(k--){
        ll q;
        cin >> q;
        ll ans = -inf;
        int l = 1, r = n;
        while(l < r){
            ll sum = a[l] + a[r];
            if(sum == q){
                ans = max(ans, a[l]);
                l++;
                r--;
            }
            else if(sum > q) r--;
            else l++;
        }
        if(ans != -inf) cout << ans << " " << q - ans << endl;
        else cout << 0 << endl;
    }


	return 0;
}
