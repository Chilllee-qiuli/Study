#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod;

struct matrix{
    ll a[2][2];

    matrix() {memset(a, 0, sizeof(a));}

    matrix(int x){ 
        memset(a, 0, sizeof(a));
        for(int i = 0; i < 2; i++) a[i][i] = 1;
    }

    matrix operator*(const matrix &b) const{
        matrix res;
        for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
        for(int k = 0; k < 2; k++)
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


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int p, q, a[2], n;
    cin >> p >> q >> a[0] >> a[1] >> n >> mod;

    K.a[0][0] = p; K.a[0][1] = q;
    K.a[1][0] = 1; K.a[1][1] = 0;

    A.a[0][0] = a[1];
    A.a[1][0] = a[0];

    if(n == 1) cout << a[0] % mod << endl;
    else if(n == 2) cout << a[1] % mod << endl;
    else {
        K = mqpow(K, n - 2);
        A = K * A;
        cout << A.a[0][0] << '\n';
    }

	return 0;
}
