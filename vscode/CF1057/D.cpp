#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1e16 - 1
const int maxn = 4e5 + 10;
int t;
int n;
int a[maxn];
ll f[maxn]; 
/*
结果数组可以看错是长度为2/3的子单元集合
于是动态规划状态转移方程就可以只考虑长度为2/3即可
*/

int work(int x, int y, int z){
    // 这个给三个数排序的方法非常的巧妙
    if(x > y) swap(x, y);
    if(y > z) swap(y, z);
    if(x > y) swap(x, y);
    return z - x;
}

int main(){
    //freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            a[i + n] = a[i];
        }
        ll ans = 0x3f3f3f3f3f3f3f3f;
        for(int k = 0; k <= 2; k++){ // 从哪里开始成环
            //memset(f, 0x1f, sizeof(f));
            for(int i = 0; i <= n + 2; i++) f[i] = INF;
            f[k] = 0;
            for(int i = 2 + k; i <= n + 2; i++){
                f[i] = f[i - 2] + abs(a[i] - a[i - 1]);
                if(i >= 3 + k) f[i] = min(f[i], f[i - 3] + work(a[i], a[i - 1], a[i - 2]));
            }
            ans = min(ans, f[n + k]);
        }
        cout << ans << endl;

    }


	return 0;
}
