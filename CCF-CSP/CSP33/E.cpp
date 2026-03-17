#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 10;
const int maxm = 2e6 + 10;
int n, m;
int dth[maxn];
int cnt[maxn];
ll sum[maxn];
int Fa[maxn];
vector<int> g[maxn];
ll sj[maxn];
bool vis[maxn];

struct Work{
    int op;
    int x;
}wk[maxm];



void pre();
void work();
void workB(); // 菊花图
void workC();
void workD(); // 没有文件访问操作。
void workDD(); // workD TLE 了，先保留原版，改个优化
void workE(); // 没有文件夹合并操作。
void dfsE(int u, int fa);
void dec_depth(int u, int fa);

int flagB = 1, flagA = 1, flagC = 1, flagD = 1, flagE = 1;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    pre();

    if(flagB){workB(); return 0;}
    // cout << "bout\n";
    if(flagC){workC(); return 0;}
    // cout << "cout\n";
    //if(flagD){workDD(); return 0;}
    // cout << "dout\n";
    if(flagE){workE(); return 0;}

    work();
    
    return 0;
}


void dec_depth(int u, int fa){
    //if(vis[u]) return;
    vis[u] = 1;

    dth[u]--;
    for(auto v : g[u]){
        if(v == fa) continue;
        dec_depth(v, u);
    }
}

void work(){
    dfsE(1, 0);
    for(int i = 1; i <= m; i++){
        int op = wk[i].op, x = wk[i].x;
        if(op == 1){
            vector<int> son;
            for(auto u : g[x]){
                if(u == Fa[x]) continue;
                sj[x] += sj[u];
                for(auto v : g[u]) 
                if(v != Fa[u]) {
                    son.push_back(v);
                    
                    dec_depth(v,u);
                    Fa[v] = x;
                    for(auto &t : g[v])
                        if(t == u){
                            t = x;
                            break;
                        }

                    }
            }
            swap(son, g[x]);

            cout << g[x].size() << " " << sj[x] << "\n";
        }
        else {
            cout << dth[x] << "\n";
        }
    }
}

void workC(){

    dfsE(1, 0);
    for(int i = 1; i <= n; i++){
        cnt[dth[i]]++;
        sum[dth[i]] += sj[i];
    }
    int flag = 2;
    for(int i = 1; i <= m; i++){
        int op = wk[i].op, x = wk[i].x;
        if(op == 1){
            sj[1] += sum[flag++];
            cout << cnt[flag] << " " << sj[1] << "\n";
        }
        else {
            if(x == 1) cout << 1 << "\n";
            else cout << dth[x] - flag + 2 << "\n";
        }
    }
}
void workDD(){
    // ???
}

void workD(){ 
    for(int i = 1; i <= m; i++){
        vector<int> son;
        int op = wk[i].op, x = wk[i].x;
        for(auto u : g[x]){
            if(u == Fa[x]) continue;
            sj[x] += sj[u];
            for(auto v : g[u]) // 隔层搜索如果每次都隔出一个菊花图就炸了
                if(v != Fa[u]) son.push_back(v);
        }
        swap(son, g[x]);
        cout << g[x].size() << " " << sj[x] << "\n";
    }
}

void dfsE(int u, int fa){
    dth[u] = dth[fa] + 1;
    for(auto v : g[u]){
        if(v == fa) continue;
        dfsE(v, u);
    }
}

void workE(){
    dfsE(1, 0);
    for(int i = 1; i <= m; i++){
        int op = wk[i].op, x = wk[i].x;
        cout << dth[x] << "\n";
    }
}

void workB(){
    ll sum = 0;
    for(int i = 1; i <= n; i++) sum += sj[i];
    int flag = 1; // 根还没吃掉所有文件夹
    for(int i = 1; i <= m; i++){
        int op = wk[i].op, x = wk[i].x;
        if(op == 1){ // merge
            if(x != 1) cout << "0 " <<  sj[x] << "\n";
            else {
                flag = 0;
                cout << "0 " << sum << "\n";
            }
        }
        else { // visit
            if(x == 1) cout << 1 << "\n";
            else cout << 2 << "\n";
        }
    }
}


void pre(){
    cin >> n >> m;

    for(int i = 2; i <= n; i++){
        int fi;
        cin >> fi;
        Fa[i] = fi;
        if(fi != i - 1) flagA = 0;
        if(fi != 1) flagB = 0;
        g[i].push_back(fi);
        g[fi].push_back(i);
    }
    
    for(int i = 1; i <= n; i++) cin >> sj[i];
    
    for(int i = 1; i <= m; i++){
        cin >> wk[i].op >> wk[i].x;
        if(wk[i].op != 1) flagD = 0;
        if(wk[i].op != 2) flagE = 0;
        if(wk[i].op == 1 && wk[i].x != 1) flagC = 0;
    } 
}