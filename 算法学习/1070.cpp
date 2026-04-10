#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1010;
int dp[maxn][maxn];
int n, m, p;
int val[maxn][maxn], buy[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> p;
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
    cin >> val[i][j];

    for(int i = 1; i <= n; i++) cin >> buy[i];

    memset(dp, -0x3f, sizeof(dp));
    cout << dp[0][0] << endl;


	return 0;
}
