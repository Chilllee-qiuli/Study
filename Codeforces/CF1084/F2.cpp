#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int t;
int n, m;
ll dp[maxn];

struct particle{
    int x, y;
    friend bool operator < (particle a, particle b){
        return a.x > b.x; // big
    }

}p[maxn];

priority_queue<particle> qu;


void solve_one(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> p[i].x >> p[i].y;

    for(int i = 0; i <= n; i++) dp[i] = 0;
    

    sort(p + 1, p + 1 + n, [](const particle&a, const particle&b){
        return a.y == b.y ? a.x > b.x : a.y > b.y;
    });

    int top = 1;
    ll now = 0;
    for(int i = n; i ; i--){
        if(p[top].y >= i - 1) {
            qu.push(p[top]);
            now += p[top].x;
        }
        while(qu.size() >= i + 2){ // ? i + 1?
            now -= qu.top().x;
            qu.pop();
        }
        dp[i] = now;
    }

    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        cout << max(dp[0], dp[y ] + x) << " ";
    }
    cout << endl;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--) solve_one();

	return 0;
}
