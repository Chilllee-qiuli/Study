#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 10010;
int n, c;
int dp[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> c;
    for(int i = 1; i <= n; i++)
{
    int w, v;
    cin >> w >> v;
    for(int j = c; j >= w; j--) 
    dp[j] = max(dp[j], dp[j - w] + v);
}
    cout << dp[c] << endl;
	return 0;
}