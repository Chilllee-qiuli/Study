#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void mmul(ll a[2][2], ll b[2][2], ll c[2][2], ll x, ll y, ll z, ll mod)
{
    // a, b是系数矩阵，c是结果矩阵
    // a的尺寸是x*y，b的尺寸是y*z，c的尺寸是x*z
    ll d[2][2];
    // 一定要把结果装到临时变量里，再复制到c
    //  不能直接赋值给c
    //  否则当a和c是同一个数组时就错了

    for (int i = 0; i < x; i++)
        for (int j = 0; j < z; j++)
        { // 枚举c_{i, j}
            d[i][j] = 0;
            for (int k = 0; k < y; k++)
                d[i][j] = (( __int128 )d[i][j] + ( __int128 )a[i][k] * b[k][j]) % mod;

        }
    for (int i = 0; i < x; i++)
        for (int j = 0; j < z; j++) // 注意是z
            c[i][j] = d[i][j];
}

void mqpow(ll X[2][2], ll y, ll mod)
{
    ll Tmp[2][2] = {
        {1, 0},
        {0, 1}, // 单位矩阵
    };
    while (y)
    { // 二进制拆分y次幂
        if (y & 1)
            mmul(X, Tmp, Tmp, 2, 2, 2, mod); // Tmp = X*Tmp
        mmul(X, X, X, 2, 2, 2, mod);
        y >>= 1;
    }
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            X[i][j] = Tmp[i][j];
}

ll m, a, c, x, n, g;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> m >> a >> c >> x >> n >> g;
    ll K[2][2] = {
        {a, 1},
        {0, 1},
    };
    ll X[2][2] = {
        {x},
        {c},
    };

    mqpow(K, n, m);
    mmul(K, X, X, 2, 2, 1, m);
    cout << X[0][0] % g << endl;

    return 0;
}
