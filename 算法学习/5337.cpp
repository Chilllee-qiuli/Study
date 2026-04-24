#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
ll n;
string s;
int mp[30][30];

struct matrix{
    ll a[30][30];

    matrix(){memset(a, 0, sizeof(a));}

    matrix(int x){ // 单位矩阵初始化
        memset(a, 0, sizeof(a));
        for(int i = 1; i < 27; i++) a[i][i] = 1;
    }

    matrix operator*(const matrix &b) const{
        matrix res;
        for(int i = 1; i <= 26; i++)
        for(int j = 1; j <= 26; j++)
        for(int k = 1; k <= 26; k++)
        (res.a[i][j] += a[i][k] * b.a[k][j]) %= mod;
        return res;
    }
}A, K;

matrix mqpow(matrix x, ll y){
    matrix tmp = matrix(1);
    while(y){
        if(y & 1) tmp = x * tmp;
        x = x * x;
        y >>= 1;
    }
    return tmp;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> n;
    cin >> s;
    for(int i = 1; i < s.length(); i++){
        char ch = s[i - 1];
        mp[ch - 'a' + 1][s[i] - 'a' + 1] = 1;
    }

    for(int i = 1; i <= 26; i++) K.a[1][i] = 1;

    for(int i = 1; i <= 26; i++)
    for(int j = 1; j <= 26; j++)
        if(!mp[i][j]) A.a[i][j] = 1;
        
    

    A = mqpow(A, n - 1);

    K = K * A;

    ll ans = 0;
    for(int i = 1; i <= 26; i++) (ans += K.a[1][i]) %= mod;

    cout << ans << endl;


	return 0;
}
