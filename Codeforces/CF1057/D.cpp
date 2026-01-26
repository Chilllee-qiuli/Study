#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 4e5 + 10;
int t;
int n;
int a[maxn];
ll f[maxn];

int work(int x, int y, int z){
    // 这个给三个数排序的方法非常的巧妙
    if(x > y) swap(x, y);
    if(y > z) swap(y, z);
    if(x > y) swap(x, y);
    return z - x;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        memset(f, 0, sizeof(f));
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            a[i + n] = a[i];
        }
        ll ans = 1e18;
        f[1] = 1e18;
        for(int i = 2; i <= n + 3; i++){
            f[i] = f[i - 2] + abs(a[i] - a[i - 1]);
            if(i >= 3){
                f[i] = min(f[i], f[i - 3] + work(a[i], a[i - 1], a[i - 2]));
            }
        }
        for(int i = 0; i <= 3; i++){
            //cout << "nowans: " << ans << endl;

            //cout << "now f[i + n]: " << f[i + n] << " now[f[i]] " << f[i] << endl;
         ans = min(ans, abs(f[i + n] - f[i])); 
    }

        cout << ans << endl;

    }


	return 0;
}
