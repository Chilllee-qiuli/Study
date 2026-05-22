#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
const int maxn = 3030;
const int maxm = 3030;
int n, m;
// 本题我们正难则反，先算没有易感序列的概率
ll P[maxn][4];
ll f[maxn][maxm];
// f_{i, j} 表示对于前i个字符，匹配到易感序列第j位时，还没有出现过完整易感序列的概率
int to[maxn][4];

string cmp = "ATGC";
vector<int> prefix(string s){
    vector<int> pi(n);
    int l = s.length();
    for(int i = 1; i < l; i++){
        int j = pi[i - 1];
        while(j && s[i] != s[j]) j = pi[j - 1];
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }

    // 预处理每个易感序列的失配状态
    for(int j = 0; j < m; j++){
        for(int c = 0; c < 4; c++){
            int nj = j;
            while(nj && cmp[c] != s[nj]) nj = pi[nj - 1];
            if(s[nj] == cmp[c]) nj++;
            to[j][c] = nj;
        }
    }
    return pi;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> n >> m;
    string s;
    cin >> s;

    for(int i = 1; i <= n; i++)
    for(int j = 0; j < 4; j++) cin >> P[i][j];
    
    vector<int> pi = prefix(s);
    f[0][0] = 1;

    // DP
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < m; j++){
            if(!f[i - 1][j]) continue; // 概率为 0，提前剪枝
            for(int c = 0; c < 4; c++){ // 枚举当前位放的碱基
                int nj = to[j][c];
                if(nj == m) continue; // 完整匹配了，此人易感，丢弃
                (f[i][nj] += f[i - 1][j] * P[i][c]) %= mod;
            }
        }
    }

    ll not_inf = 0;
    for(int j = 0; j < m; j++) (not_inf += f[n][j]) %= mod;
    cout << (1 - not_inf + mod) % mod << '\n';

	return 0;
}
