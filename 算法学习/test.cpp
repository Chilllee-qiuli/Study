#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pr pair<int, int> 
#define mk make_pair
#define fi first 
#define se second
int n, m, k;

const int maxn = 1e5 + 10;
pr a[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a + 1, a + 1 + n, [](pr x, pr y){
        return x.first > y.fi;
    }); // 按照每块田原本的需要时间降序

    ll tmp = 0;
    a[0].fi = a[1].fi;
    a[n + 1].fi = k;
    for(int i = 1; i <= n + 1; i++){
        tmp += a[i].se; // 记录前面所有田降低1单位的代价

        if(a[i].fi != a[i + 1].fi){
            int cur = a[i].fi;
            int nxt = max(a[i + 1].fi, k);

            ll diff = cur - nxt; // 记录当前能降低的最大差值
            ll cost = diff * tmp;

            if(m >= cost){
                m -= cost;
                if(nxt == k){
                    cout << k << endl;
                    return 0;
                }
            }
            else{
                cout << cur - m / tmp << endl;
                return 0;
            }
        }
    }
    cout << k << endl;

	return 0;
}
