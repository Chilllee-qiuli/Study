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

	return 0;
}
