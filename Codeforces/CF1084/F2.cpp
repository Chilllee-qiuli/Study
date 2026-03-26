#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int t;
int n, m;
ll dp[maxn];
// dp定义为，从旧粒子中选择k个，且这些粒子都满足 y >= k的最大能量和
struct particle{
    int x, y;
    friend bool operator < (particle a, particle b){
        return a.x > b.x; // small
    }
}p[maxn];

priority_queue<particle> qu;

void solve_one(){
    priority_queue<particle>().swap(qu);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> p[i].x >> p[i].y;

    for(int i = 0; i <= n; i++) dp[i] = 0;
    
    sort(p + 1, p + 1 + n, [&](const particle a, const particle b){
        return a.y == b.y ? a.x > b.x : a.y > b.y;
    });

    int l = 1;
    ll now = 0, base = 0; // base 定义为，从旧粒子里边选 s 个且这些粒子满足 y >= s - 1
    // base和dp的作用是很有区别的
    // 因为dp为了接纳商店粒子，当限制为k的时候，我们要求qu.size() <= k，从而给商店粒子腾好位置
    // 而base要求qu.size() <= k + 1;
    for(int k = n; k >= 0; k--){
        while(l <= n && p[l].y >= k){
            now += p[l].x;
            qu.push(p[l++]);
        }
        while(qu.size() > k + 1){
            now -= qu.top().x;
            qu.pop();
        }
        base = max(base, now);
        if(qu.size() == k + 1){
            now -= qu.top().x;
            qu.pop();
        }
        dp[k] = now;
    }
    // 做前缀和是因为，在买入新的商店粒子的时候，我们可以选[0, y]个旧粒子
    for(int k = 1; k <= n; k++) dp[k] = max(dp[k], dp[k - 1]);

    for(int j = 1; j <= m; j++){
        ll x, y;
        cin >> x >> y;
        if(y == 0) cout << max(x, base) << " ";
        else cout << max({dp[y] + x, base}) << " ";
    }
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--) solve_one();

	return 0;
}
