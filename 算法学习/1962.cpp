#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

void mmul(ll a[2][2], ll b[2][2], ll c[2][2], ll x, ll y, ll z){
    // a, b是系数矩阵，c是结果矩阵
    // a的尺寸是x*y，b的尺寸是y*z，c的尺寸是x*z
    ll d[2][2];
    //一定要把结果装到临时变量里，再复制到c
    // 不能直接赋值给c
    // 否则当a和c是同一个数组时就错了

    for(int i = 0; i < x; i++)
    for(int j = 0; j < z; j++){ // 枚举c_{i, j}
        d[i][j] = 0;
        for(int k = 0; k < y; k++)
         (d[i][j] += a[i][k] * b[k][j]) %= mod;

    }
    for(int i = 0; i < x; i++)
    for(int j = 0; j < z; j++) // 注意是z
    c[i][j] = d[i][j];
}

void mqpow(ll X[2][2], ll y){
    ll Tmp[2][2] = {
        {1, 0}, 
        {0, 1}, // 单位矩阵
    };
    while(y){// 二进制拆分y次幂
        if(y & 1) mmul(X, Tmp, Tmp, 2, 2, 2); // Tmp = X*Tmp
        mmul(X, X, X, 2, 2, 2);
        y >>= 1;
    }
    for(int i = 0; i < 2; i++)
    for(int j = 0; j < 2; j++)
    X[i][j] = Tmp[i][j];

}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    ll n;
    cin >> n;
    if(n <= 2) {
        cout << 1 << endl;
        return 0;
    }
    ll K[2][2] = { // 构造的系数矩阵
        {1, 1}, 
        {1, 0},
    };
    ll A[2][2]={
        {1}, // 等价于{1, 0}，但A我们当作 2 * 1 矩阵来使用
        {1}
    };
    mqpow(K, n - 2);
    mmul(K, A, A, 2, 2, 1);
    cout << A[0][0]<< endl;

	return 0;
}
