#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod;
const int maxn = 33;

struct matrix{
    ll a[maxn][maxn];

    matrix() {memset(a, 0, sizeof(a));}

    matrix(int x){ 
        memset(a, 0, sizeof(a));
        for(int i = 0; i < maxn; i++) a[i][i] = 1;
    }

    matrix operator*(const matrix &b) const{
        matrix res;
        for(int i = 0; i < maxn; i++)
        for(int j = 0; j < maxn; j++)
            for(int k = 0; k < maxn; k++)
            (res.a[i][j] += a[i][k] * b.a[k][j]) %= mod;
        return res;
    }
}A;

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

    int m , n;
    cin >> n >> m;
    mod = 2017;
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        A.a[u][v] = 1;
        A.a[v][u] = 1;
    }
    
    for(int i = 0; i <= n; i++) {
        A.a[i][0] = 1; // 自爆指向0，单向边
        A.a[i][i] = 1; // 自环
    }

    int t;
    cin >> t;

    A = mqpow(A, t);

    int ans = 0;
    for(int i = 0; i <= n; i++) (ans += A.a[1][i]) %= mod;

    cout << ans << endl;

    

	return 0;
}
