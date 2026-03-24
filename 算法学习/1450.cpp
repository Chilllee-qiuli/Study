#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxs = 1e5 + 10;

int c[5], n;
ll d[5];
ll dp[5 * maxs], s;

void pre(){
    for(int k = 1; k <= 4; k++)
    for(int i = c[k]; i < maxs; i++)
        dp[i] += dp[i - c[k]];
}
ll get(ll x){
    if(x < 0) return 0;
    return dp[x];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    for(int i = 1; i <= 4; i++) cin >> c[i];
    dp[0] = 1;
    pre();
    cin >> n;
    while(n--){
        for(int i = 1; i <= 4; i++) cin >> d[i];
        cin >> s;
        for(int i = 1; i <= 4; i++) d[i] = (d[i] + 1) * c[i];

        cout << get(s) - get(s - d[1]) - get(s - d[2]) - get(s - d[3]) - get(s - d[4]) + get(s - d[1] - d[2]) + get(s - d[1] - d[3]) + get(s - d[1] - d[4])
        + get(s - d[2] - d[3]) + get(s - d[2] - d[4]) + get(s - d[3] - d[4]) - get(s - d[1] - d[2] - d[3]) - get(s - d[1] - d[2] - d[4]) - get(s - d[1] - d[3] - d[4])
        - get(s - d[2] - d[3] - d[4]) + get(s - d[1] - d[2] - d[3] - d[4]) << endl;

    } 

	return 0;
}
