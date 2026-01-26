#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
这道题很有启发意义
首先xy可以理解为中间状态，我们要将qr形成最佳配对以得到最大配对个数
由于题意自然得到 x = y * q + r，把这个式子带到 $x \le k$,得到$qy + r \le k$，要满足这个方程给qr留出最大余量，于是y取最小值r + 1
于是便得到了一个q，r，k的相关方程，$q(r + 1) + r \le k$
对于一对q，r满足这个方程就意味着这是一组可行解
于是问题转化为最大二分图匹配
用qk表示r，得到 $r = \frac{k - q}{q + 1}$，那么对于一个给定q，如果r满足这个式子，这一对qr就是可行的配对

*/
const int maxn = 2e5 + 10;
int t;
ll n, k;
ll q[maxn], r[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 1; i <= n; i++) cin >> q[i];
        for(int i = 1; i <= n; i++) cin >> r[i];

        sort (q + 1, q + 1 + n);
        sort (r + 1, r + 1 + n);

        int flagr = n;
        int ans = 0;
        while(flagr > 0 && r[flagr] >= k) flagr--;

        for(int i = 1, j = 1; i <= n && q[i] <= k && flagr; i++){
            ll rmax = (k - q[i]) / (q[i] + 1);
            while(flagr > 0 && rmax < r[flagr]) flagr--;
            if(flagr > 0 && rmax >= r[flagr]){
                flagr--;
                ans++; 
                //cout << "find: " << rmax << " " << flagr << " " << r[flagr] << endl;
            }
        }

        cout << ans << endl;
    }

	return 0;
}
