#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 110;
int n, k;
struct printer{
    ll t, l, w;
    ll lun;
}pt[maxn];


bool check(ll x){
    ll cnt = 0;
    for(int i = 1; i <= n; i++){
        ll lun = pt[i].lun, l = pt[i].l;
        cnt += (x / lun) * l;
        ll y = x % lun;
        if(y >= pt[i].t * pt[i].l) cnt += l;
        else cnt += y / pt[i].t;
        if(cnt >= k) return 1;
    }
    return cnt >= k;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 1; i <= n; i++) 
        cin >> pt[i].t >> pt[i].l >> pt[i].w;

        for(int i = 1; i <= n; i++) pt[i].lun = pt[i].t * pt[i].l + pt[i].w;

        ll l = 1, r = 2e18 + 1;
        ll ans = r;
        while(l <= r){
            ll mid = (l + r) >> 1;
            if(check(mid)) ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        cout << ans << endl;
    }

	return 0;
}
