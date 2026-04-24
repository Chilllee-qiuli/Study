#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int maxn = 110;
int n;
ll k;

void mmul(ll a[maxn][maxn], ll b[maxn][maxn], ll c[maxn][maxn], int x, int y, int z){
    ll d[maxn][maxn];
    
    for(int i = 0; i < x; i++)
    for(int j = 0; j < z; j++){
        d[i][j] = 0;
        for(int k = 0; k < y; k++)
            (d[i][j] += a[i][k] * b[k][j]) %= mod;
    }

    for(int i = 0; i < x; i++)
    for(int j = 0; j < z; j++)
    c[i][j] = d[i][j] % mod;
}

void qpow(ll a[maxn][maxn], ll y){
    ll tmp[maxn][maxn] = {0};

    for(int i = 0; i < n; i++) 
    for(int j = 0; j < n; j++)
        if(i == j) tmp[i][j] = 1;
        // else tmp[i][j] = 0;
    
    
    while(y){
        if(y & 1) mmul(a, tmp, tmp, n, n, n); // tmp = a * tmp
        mmul(a, a, a, n, n, n);
        y >>= 1;
    }
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
    a[i][j] = tmp[i][j] % mod;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;
    ll A[maxn][maxn];
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
    cin >> A[i][j];

    qpow(A, k);

    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
    cout << A[i][j] << " \n"[j == n - 1];



	return 0;
}
