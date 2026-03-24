#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 110;
ll a[maxn];
ll n, c, k;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);


    int T;
    cin >> T;
    while(T--){
        cin >> n >> c >> k;
        for(int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + 1 + n);
        for(int i = 1; i <= n; i++){
            if(a[i] < c && k > 0){
                ll delta = c - a[i];
                if(k >= delta) a[i] = c, k -= delta;
                else a[i] += k, k = 0;
            }
            if(a[i] <= c) c += a[i];
        }
        cout << c << endl;
    }

	return 0;
}
