// 参考了题解 https://www.luogu.com.cn/article/78ympazb https://www.luogu.com.cn/article/581srdly
/* 第一篇转化为邻对异或值和，由于中间点和角落与周围异或是偶数次，所以从1变0或从0变1对答案奇偶性无影响。
于是中间点和角落任取
对与边格，保留一个用作平衡奇偶性即可
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
int t;
int n, m, k;

ll work(ll x,ll y,ll m = mod){
    if(y == 1) return x;
    if(y == 0) return 1;
    ll tmp = work(x, y/2, m)%m;
    if(y % 2 == 1) return tmp * tmp %m *x %m;
    else return tmp * tmp%m;
}

int main(){
   // freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m >> k;
        int cnt_e = 0;
        int cnt_1 = 0;
        for(int i = 1; i <= k; i++){
            int x, y, c;
            cin >> x >> y >> c;
            if(x == 1 || x == n || y == 1 || y == m){
                if((x == 1 && y == 1) || (x == 1 && y == m) || (x == n && y == 1) || (x == n && y == m)){
                    int tmp;
                }else{
                    cnt_e++;
                    cnt_1 ^= c;
                }
            }
        }
        if(cnt_e == (n-2)*2 + (m-2)*2){
            if(cnt_1 & 1) cout << 0 << endl;
            else cout << work(2, 1ll*n*m - k) << endl;
        }
        else cout << work(2, 1ll*n*m - k - 1) << endl;
    }

	return 0;
}
