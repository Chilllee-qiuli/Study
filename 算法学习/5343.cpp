#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
ll n;

map<int, int> mp;
vector<int> vc;

struct matrix{
    ll a[110][110];

    matrix() {memset(a, 0, sizeof(a));}

    matrix(int x){ 
        memset(a, 0, sizeof(a));
        for(int i = 1; i <= 100; i++) a[i][i] = 1;
    }

    matrix operator*(const matrix &b) const{
        matrix res;
        for(int i = 1; i <= 100; i++)
        for(int j = 1; j <= 100; j++)
            for(int k = 1; k <= 100; k++)
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

ll f[110];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    int m;
    cin >> m;
    for(int i = 1; i <= m; i++){
        int x; cin >> x;
        mp[x] = 1;
    }
    cin >> m;
    for(int i = 1; i <= m; i++){
        int x;
        cin >> x;
        if(mp[x]) vc.push_back(x);
    }

    sort(vc.begin(), vc.end());
    vc.erase(unique(vc.begin(), vc.end()), vc.end());

    mp.clear();
    for(auto x : vc) {
        mp[x] = 1;
        f[x] = 1;
    }

    // 转移矩阵
    for(int i = 1; i <= 100; i++) if(mp[i]) A.a[1][i] = 1;
    for(int i = 2; i <= 100; i++) A.a[i][i - 1] = 1;
    

    // // 预处理一个完全背包
    // for(auto x : vc){
    //     for(int i = x; i <= 100; i++)
    //     f[i] += f[i - x];
    // }

    for(int i = 1; i <= 100; i++)
    for(int j = 1; j < i; j++)
        if(mp[i - j]) (f[i] += f[j]) %= mod;

    // 初始状态向量
    for(int i = 1; i <= 100; i++) K.a[i][1] = f[100 - i + 1] % mod;

    if(n <= 100){
        cout << f[n] << '\n';
        return 0;
    }

    A = mqpow(A, n - 100);

    K = A * K;

    cout << K.a[1][1] << "\n";


    


	return 0;
}
