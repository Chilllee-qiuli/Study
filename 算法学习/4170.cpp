#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 110;
string s;
int dp[maxn][maxn];
int n;


inline long long read(){
	char readch=getchar(); ll readtmp=0;
	ll readflag=1;
	while(readch<'0' || '9'<readch){if(readch=='-')readflag=-1;readch=getchar();}
	while('0'<=readch && readch<='9'){readtmp=readtmp*10+readch-'0';readch=getchar();}
	return readtmp*readflag;
}




int main(){
	cin >> s;
	n = s.length();

	s = '0' + s;

	memset(dp, 0x3f, sizeof(dp));
	for(int i=1; i<=n; i++) dp[i][i] = 1;

	for(int len=2; len <=n; len++)
	for(int l=1, r=l+len-1; r <= n; l++, r++){
		if(s[l] == s[r]) dp[l][r] = min(dp[l][r], min(dp[l][r-1], dp[l+1][r]));
		else for(int k=l; k<=r-1; k++) dp[l][r] = min(dp[l][r], dp[l][k] + dp[k+1][r]);
	}

	cout << dp[1][n] << endl;


	

	
	return 0;
}