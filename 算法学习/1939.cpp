#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

void mmul(ll a[4][4], ll b[4][4], ll c[4][4], int x, int y, int z){
    ll d[4][4];

    for(int i = 0; i < x; i++)
    for(int j = 0; j < z; j++){
        d[i][j] = 0;
        for(int k = 0; k < y; k++)
        (d[i][j] += a[i][k] * b[k][j]) %= mod;
    }

    for(int i = 0; i < x; i++)
    for(int j = 0; j < y; j++)
    c[i][j] = d[i][j];
}

void qpow(ll x[4][4], ll y){
    ll tmp[4][4] = {0};
    
    for(int i = 0; i < 4; i++) tmp[i][i] = 1;
    
    while(y){
        if(y & 1) mmul(x, tmp, tmp, 4, 4, 4);
        mmul(x, x, x, 4, 4, 4);
        y >>= 1;
    }

    for(int i = 0; i < 4; i++)
    for(int j = 0; j < 4; j++)
    x[i][j] = tmp[i][j] % mod;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n <= 3) {
            cout << 1 << "\n";
            continue;
        }
        if(n == 4){
            cout << 2 << endl;
            continue;
        }
        ll K[4][4] = {
            {1, 0, 1, 0},
            {1, 0, 0, 0},
            {0, 1, 0, 0},
            {0, 0, 1, 0},
        };
        ll A[4][4] = {
            {2},
            {1},
            {1},
            {1}
        };
        qpow(K, n - 4);
        mmul(K, A, A, 4, 4, 4);
        cout << A[0][0] << endl;
    }

	return 0;
}
