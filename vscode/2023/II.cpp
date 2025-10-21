#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
const int mod = 998244353;
int n;

string s;

ll dp[maxn][130];

bool konw(char ch){
    return ('0' <= ch && ch <= '9') || ('A' <= ch && ch <= 'Z');
}
bool small(char ch) {
    return 'a' <= ch && ch <= 'z';
}

ll cnt(int x){
    ll sum = 0;
    for(int i = 48; i <= 123; i++)
        if(small((char)i) || konw((char)i)) sum += dp[x][i];
    return sum;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    cin >> s;
    s = "0" + s + "0";
    if(konw(s[1])) dp[1][s[1]] = 1;
    else if(small(s[1])) dp[1][s[1]] = dp[1][s[1] - 32] = 1;
    else {
        for(int i = 1; i <= 123; i++)
            if(small((char)i) || konw((char)i)) dp[1][i] = 1;
    }
    
    
    for(int i = 2; i <= n+1; i++){
        ll sum = cnt(i-1);
        if(konw(s[i])) dp[i][s[i]] = (sum - dp[i-1][s[i]]) % mod;
        else if(small(s[i])) {
            dp[i][s[i]] = (sum - dp[i-1][s[i]]) % mod;
            dp[i][s[i] - 32] = (sum - dp[i-1][s[i] - 32]) % mod;
        }
        else {
            for(int j = 1; j <= 123; j++)
                if(small((char)j) || konw((char)j)){
                    dp[i][j] = (sum - dp[i-1][j]) % mod;
                }
        }
    }

    cout << dp[3]['0'] % mod << endl;



	return 0;
}