#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxm = 1e6 + 10;
const int mod = 998244353;

struct matrix{
    ll a[15][15];
    matrix(){memset(a, 0, sizeof(a));}
    matrix(int x){ // 单位矩阵初始化
        memset(a, 0, sizeof(a));
        for(int i = 0; i < 15; i++) a[i][i] = 1;
    }

    matrix operator*(const matrix &b) const{
        matrix res;
        for(int i = 0; i < 15; i++)
        for(int j = 0; j < 15; j++)
        for(int k = 0; k < 15; k++)
        (res.a[i][j] += a[i][k] * b.a[k][j]) %= mod;
        return res;
    }
} A, B;
struct node{
    int son[26]; // 子节点边
    int cnt; // 记录匹配数
    int fail; // fail指针
    int in; // 入度
    void init(){
        memset(son, 0, sizeof(son));
        cnt = fail = 0;
    }
}tr[9];
int tot;

void insert(string s, int& id){
    int p = 0;
    int l = s.length();
    for(int i = 0; i < l; i++){
        int c = s[i] - 'a';
        if(!tr[p].son[c]) tr[p].son[c] = ++tot;
        p = tr[p].son[c];
    }
    id = p;
}

void build(){
    queue<int> q;
    for(int i = 0; i < 26; i++)
        if(tr[0].son[i]) q.push(tr[0].son[i]);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0; i < 26; i++){
            if(tr[u].son[i]){  
                int son = tr[u].son[i];
                tr[son].fail = tr[tr[u].fail].son[i];
                q.push(tr[u].son[i]);  
            }
            else tr[u].son[i] = tr[tr[u].fail].son[i];

        }
    }
}

// 这里必须写成向量乘矩阵，矩阵乘法是立方复杂度，无法通过此题
typedef vector<ll> Vec;
Vec vec_mul(const Vec& v, const matrix& M){
    Vec r(15, 0);
    for(int i = 0; i < 15; i++) if(v[i])
        for(int j = 0; j < 15; j++)
            r[j] = (r[j] + v[i] * M.a[i][j]) % mod;
    return r;
}
const int LOG = 30;
matrix Apow[LOG + 1];

// 第二步：预处理 A 的倍增幂，然后向量快速幂
// 在 build_matrix() 之后调用
void prepare_pow(){
    Apow[0] = A;
    for(int k = 1; k <= LOG; k++) Apow[k] = Apow[k-1] * Apow[k-1];
}

Vec vec_pow(Vec v, ll L){
    for(int k = 0; k <= LOG; k++)
        if((L >> k) & 1) v = vec_mul(v, Apow[k]);
    return v;
}


matrix mqpow(matrix x, ll y){
    matrix tmp = matrix(1);
    while(y){
        if(y & 1) tmp = x * tmp;
        x = x * x;
        y >>= 1;
    }
    return tmp;
}



int end1, end2;
int n, m;
vector<int> jing;

const int NV = 10;  // trie 节点数上限
int rid[NV]; // rid[v]: 折叠后编号；终态记为 -1
int eff_n;     // 折叠后节点数 = 7
// 折叠——把终态节点(ccf)"压缩"进事件处理里，不作为独立状态保留。节点 8（cspark）同理。
// 折叠前有 9 个节点，折叠掉节点 3 和节点 8，剩 7 个节点。
void rename_nodes(){
    eff_n = 0;
    for(int v = 0; v <= tot; v++){
        if(v == end1 || v == end2) rid[v] = -1;
        else rid[v] = eff_n++;
    }
}

// idx(u, g) 把 (节点, 阶段) 二维状态打平成 0~14 的一个数。
inline int idx(int u, int g){
    if(g == 2) return 14;
    return g * eff_n + rid[u];
}
// 原本trie上，或者说自动机上应该有9个状态，我们现在压缩到7个，然后设置三个阶段
// 阶段g：0表示没出现过完整ccf；1表示已经匹配出ccf；2表示不仅匹配了ccf还匹配了cspark。

const int K = 15; // 阶段g = 0、1 各 7 个状态，加上吸收态 g = 2，一共15个状态

void build_matrix(){
     // A: 字母段, 每位 26 种字母累加
     // A的大小并不是26^2，因为我们要的是每种状态跳到每种状态的转移方案数
    // 这个和【矩阵快速幂+kmp求构造含/不含模式串的文本串方案数】题型是一脉相承的思想
    for(int u = 0; u <= tot; u++){
        if(rid[u] == -1) continue;
        for(int g = 0; g < 2; g++){ 
            
            int s = idx(u, g);
            for(int c = 0; c < 26; c++){ // 26 种跳转
                int v = tr[u].son[c], ng = g;
                if(v == end1){if(!ng) ng = 1; v = 0;}
                else if(v == end2){if(ng == 1) ng = 2; v = 0;}
                A.a[s][idx(v, ng)]++;
            }
        }
    }
    A.a[K - 1][K - 1] = 26; // A[14][14]=26 这一句对应吸收态：合法之后随便填 26 个字母都还是合法。

    // B: # 段, 任何 (u, g) 都到 (0, g)
    for(int u = 0; u <= tot; u++){
        if(rid[u] == -1) continue;
        for(int g = 0; g < 2; g++) B.a[idx(u, g)][idx(0, g)] = 1;
        // 阶段保留，状态清零
    }
    B.a[K-1][K-1] = 1;

}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        jing.push_back(x);
    }

    insert("ccf", end1);
    insert("cspark", end2);

    build();
    // 折叠状态
    rename_nodes();
    build_matrix();
     prepare_pow();

    ll ans = 0;

    Vec v(K, 0);
    v[idx(0, 0)] = 1;  // 初始：根节点，阶段 0
    
    int prev = 0;
    for(int i = 0; i < m; i++){
        int L = jing[i] - prev - 1;  // 第 i 段字母长度
        v = vec_pow(v, L);            // 乘 A^L
        v = vec_mul(v, B);            // 乘 B（过一个 #）
        prev = jing[i];
    }
    v = vec_pow(v, n - prev);         // 最后一段字母
    
    cout << v[K - 1] << '\n';         // 吸收态的方案数


	return 0;
}
