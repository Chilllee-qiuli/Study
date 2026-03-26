#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 10;
int dp[maxn][4][2];

int n;
string s;
int tot = 1;

struct node{
    int l, r;
}tr[maxn];

void dfs1(int u){
    int sons = s[u] - '0';

    if(!sons) return ;
    ++tot;
    tr[u].l = tot;
    dfs1(tot);

    if(sons == 1) return ;
    ++tot;
    tr[u].r = tot; 
    dfs1(tot); 
}

void dfs2(int u){
    if(!tr[u].l){
        dp[u][1][0] = 0; // red max
        dp[u][2][0] = 1; // green max
        dp[u][3][0] = 0; // blue max

        dp[u][1][1] = 0; // red min
        dp[u][2][1] = 1; // green min
        dp[u][3][1] = 0; // blue min
    }
    else if(!tr[u].r){
        dfs2(tr[u].l);

        dp[u][1][0] = max(dp[tr[u].l][2][0], dp[tr[u].l][3][0]);
        dp[u][2][0] = max(dp[tr[u].l][1][0], dp[tr[u].l][3][0]) + 1;
        dp[u][3][0] = max(dp[tr[u].l][1][0], dp[tr[u].l][2][0]);

        dp[u][1][1] = min(dp[tr[u].l][2][1], dp[tr[u].l][3][1]);
        dp[u][2][1] = min(dp[tr[u].l][1][1], dp[tr[u].l][3][1]) + 1;
        dp[u][3][1] = min(dp[tr[u].l][1][1], dp[tr[u].l][2][1]);
    }
    else {
        int l = tr[u].l, r = tr[u].r;
        dfs2(l);
        dfs2(r);

        dp[u][1][0] = max(dp[l][2][0] + dp[r][3][0], dp[l][3][0] + dp[r][2][0]);
        dp[u][2][0] = max(dp[l][1][0] + dp[r][3][0], dp[l][3][0] + dp[r][1][0]) + 1;
        dp[u][3][0] = max(dp[l][1][0] + dp[r][2][0], dp[l][2][0] + dp[r][1][0]);

        dp[u][1][1] = min(dp[l][2][1] + dp[r][3][1], dp[l][3][1] + dp[r][2][1]);
        dp[u][2][1] = min(dp[l][1][1] + dp[r][3][1], dp[l][3][1] + dp[r][1][1]) + 1;
        dp[u][3][1] = min(dp[l][1][1] + dp[r][2][1], dp[l][2][1] + dp[r][1][1]);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> s;
    n = s.length();
    s = '#' + s;
    
    dfs1(1);

    dfs2(1);

    cout << max({dp[1][1][0], dp[1][2][0], dp[1][3][0]}) << ' ';
    cout << min({dp[1][1][1], dp[1][2][1], dp[1][3][1]}) << endl;

    return 0;
}
