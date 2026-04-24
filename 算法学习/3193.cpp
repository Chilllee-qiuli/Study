#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, mod;

struct matrix{
    ll a[30][30];

    matrix(){memset(a, 0, sizeof(a));}

    matrix(int x){ // 单位矩阵初始化
        memset(a, 0, sizeof(a));
        for(int i = 0; i <= m - 1; i++) a[i][i] = 1;
    }

    matrix operator*(const matrix &b) const{
        matrix res;
        for(int i = 0; i <= m - 1; i++)
        for(int j = 0; j <= m - 1; j++)
        for(int k = 0; k <= m - 1; k++)
        (res.a[i][j] += a[i][k] * b.a[k][j]) %= mod;
        return res;
    }
} G, K;

matrix mqpow(matrix x, ll y){
    matrix tmp = matrix(1);
    while(y){
        if(y & 1) tmp = x * tmp;
        x = x * x;
        y >>= 1;
    }
    return tmp;
}

vector<int> prefix(string s){
    int n = s.length();
    vector<int> pi(n);
    for(int i = 1; i < n; i++){
        int j = pi[i - 1];
        while(j && s[i] != s[j]) j = pi[j - 1];
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

void pre(string s){
    int n = s.length();
    vector<int> pi = prefix(s);

    for(int i = 0; i <= m - 1; i++)
        for(char num = '0'; num <= '9'; num++){
            int j = i;
            while(j && num != s[j]) j = pi[j - 1];
            if(s[j] == num) j++;
            if(j == m) continue;  // 完整匹配了，不合法，跳过
            G.a[i][j]++; // 从i跳到j的方案数 + 1
        }
}


int main(){
    
    cin >> n >> m >> mod;
    string str;
    cin >> str;

    pre(str);

    K.a[0][0] = 9; K.a[0][1] = 1;
    G = mqpow(G, n - 1);
    K = K * G;

    ll ans = 0;
    for(int i = 0; i <= m - 1; i++) (ans += K.a[0][i]) %= mod;
    cout << ans << endl;
	return 0;
}
