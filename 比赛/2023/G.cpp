#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD=998244353;
const int maxn=1e6+7;
int g[maxn];
int rank[maxn];
int modInverse(int a, int m) {
    int t0 = 0, t1 = 1;
    int r0 = m, r1 = a;
    
    while (r1 != 0) {
        int q = r0 / r1;
        int t2 = t0 - q * t1;
        t0 = t1;
        t1 = t2;
        int r2 = r0 - q * r1;
        r0 = r1;
        r1 = r2;
    }
    
    if (r0 != 1) {
        // 逆元不存在，gcd(a, m) != 1
        return -1;
    }
    
    if (t0 < 0) {
        t0 += m;
    }
    return t0;
}
int fractionMod(int a, int b, int m) {
    if (b == 0) {
        cerr << "错误：分母为零" << endl;
        return -1;
    }
    
    int inv = modInverse(b, m);
    if (inv == -1) {
        cerr << "错误：模逆元不存在，gcd(b, m) != 1" << endl;
        return -1;
    }
    int a_mod = a % m;
    if (a_mod < 0) {
        a_mod += m;
    }
    long long product = (long long)a_mod * inv;
    int result = product % m;
    if (result < 0) {
        result += m;
    }
    return result;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        g[i]=i;
    }
    vector<pair<int,int>> op;
    vector<pair<int,int>> edge;
    for(int i=1;i<=n;i++){
        int ai,bi;
        cin>>ai>>bi;
        op.push_back({ai,bi});
    }
    for(int i=1;i<=n;i++){
        int ci,di;
        cin>>ci>>di;
        edge.push_back({ci,di});
    }
    
}