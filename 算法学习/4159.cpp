#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 2009;
int n, t;


struct matrix{
    ll a[99][99];

    matrix() {memset(a, 0, sizeof(a));}

    matrix(int x){ // 单位矩阵初始化
        memset(a, 0, sizeof(a));
        for(int i = 1; i <= n * 9; i++) a[i][i] = 1;
    }

    matrix operator*(const matrix &b) const{
        matrix res;
        for(int i = 1; i <= n * 9; i++)
        for(int j = 1; j <= n * 9; j++)
        for(int k = 1; k <= n * 9; k++)
        (res.a[i][j] += a[i][k] * b.a[k][j]) %= mod;
        return res;
    }
} K, A;

matrix mqpow(matrix x, ll y){
    matrix tmp = matrix(1);
    while(y){
        if(y & 1) tmp = x * tmp;
        x = x * x;
        y >>= 1;
    }
    return tmp;
}

int pos(int u, int i){ // 映射点的下标
    return u + i * n;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> t;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 8; j++) K.a[pos(i, j)][pos(i, j - 1)] = 1; // 分层图回边
        string s;
        cin >> s;
        s = "#" + s;
        for(int j = 1; j <= n; j++){
            int x = s[j] - '0';
            if(x) K.a[i][pos(j, x - 1)] = 1; // 连向对应的辅助点
        }
    }

    K = mqpow(K, t);
    A.a[1][1] = 1;
    A = A * K;

    cout << A.a[1][n] << endl;


	return 0;
}
