#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 50010;
const ll inf = 0x3f3f3f3f3f3f3f3f;
int n, k;
ll a[maxn];

int main(){
    //freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    while(k--){
        ll q;
        cin >> q;
        ll ans1 = -inf, ans2 = -inf;
        int l = 1, r = n;
        while(l < r){ 
            ll sum = a[l] + a[r];
            if(sum == q){
                if(a[l] > ans1){
                    ans1 = a[l];
                    ans2 = a[r];
                }
                l++;
            }
            else if(sum < q) l++;
            else r--;
        }

        if(ans1 != -inf)
        cout << ans1 << " " << ans2 << endl;
        else 
        cout << 0 << endl;
    }

	return 0;
}