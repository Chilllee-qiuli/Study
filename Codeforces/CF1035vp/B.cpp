#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 10;
const double eps = 1e-9;
int t;
int n, px, py, qx, qy;
int a[maxn];

bool judge(int maxx, ll sum){
    ll pq = (1ll * px - qx) * (1ll * px - qx);
    if(pq - sum > eps) return 0;
    if(n == 1) return fabs(pq - sum) < eps;
    if(n == 2){
        if(px == qx && py == qy) return a[1] == a[2];
        double tmp = max({1.0 * pq, 1.0  * a[1], 1.0*a[2]});
        double sum3 = pq + a[1] + a[2];
        return sum3 - tmp - tmp > eps;
    }

    if(pq - maxx > eps) return 1;

    return sum + pq - maxx > maxx;
}


int main(){
    freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){

        int maxx = 0;
        ll sum = 0;
        cin >> n;

        cin >> px >> py >> qx >> qy;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            maxx = max(maxx, a[i]);
            sum += a[i];
        }



    }

	return 0;
}