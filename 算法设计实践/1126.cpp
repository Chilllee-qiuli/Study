#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxm = 1e13 + 10;
ll t;
ll income_tax(ll p, int d, int f) {
  p -= 60000 + d;

  if(p <= 0) return 0;
  if(p <= 36000) return max(0ll, ll( p * 0.03 - f));
  if(p <= 144000) return max(0ll, ll(1080 + (p - 36000) * 0.1 - f));
  if(p <= 300000) return max(0ll, ll(11880 + (p - 144000) * 0.2 -  f));
  if(p <= 420000) return max(0ll, ll(43080 + (p - 300000) * 0.25 - f));
  if(p <= 660000) return max(0ll, ll(73080 + (p - 420000) * 0.3 - f)) ;
  if(p <= 960000) return max(0ll, ll(145080 + (p - 660000) * 0.35 - f));
  return max(0ll, ll(250080 + (p - 960000) * 0.45 - f));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    ll l = 60033, r = maxm;

    ll ans = 0;
    while(l <= r){
        ll mid = (l + r) >> 1;
        if(income_tax(mid, 0, 0) <= t) ans = mid, l = mid + 1;
        else r = mid - 1;
    }

    cout << ans << endl;



	return 0;
}