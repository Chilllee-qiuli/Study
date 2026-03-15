#include <bits/stdc++.h>
using namespace std;

const int maxn = 550;
bitset<maxn> bt[maxn], sub[maxn];
vector<int> g[maxn];
int n, indeg[maxn];

int dfs(int u){
    sub[u].reset();
    sub[u].set(u);
    for(int v : g[u]){
        dfs(v);
        sub[u] |= sub[v];
    }
    return 0;
}

int work(){
    cin >> n;

    for(int i = 1; i <= n; i++){
        bt[i].reset();
        sub[i].reset();
        g[i].clear();
        indeg[i] = 0;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            char x;
            cin >> x;
            if(x == '1') bt[i].set(j);
        }
    }

    // 自反
    for(int i = 1; i <= n; i++){
        if(!bt[i].test(i)) return 0;
    }


    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            if(bt[i].test(j) && bt[j].test(i)) return 0;
        }
    }


    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) continue;
            if(bt[i].test(j)){
                if((bt[i] & bt[j]) != bt[j]) return 0;
            }
        }
    }


    int edges = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j || !bt[i].test(j)) continue;

            bool direct = true;
            for(int k = 1; k <= n; k++){
                if(k == i || k == j) continue;
                if(bt[i].test(k) && bt[k].test(j)){
                    direct = false;
                    break;
                }
            }

            if(direct){
                g[i].push_back(j);
                indeg[j]++;
                edges++;
            }
        }
    }

    if(edges != n - 1) return 0;

    int root = 0, roots = 0;
    for(int i = 1; i <= n; i++){
        if(indeg[i] == 0){
            root = i;
            roots++;
        }else if(indeg[i] != 1){
            return 0;
        }
    }
    if(roots != 1) return 0;


    dfs(root);

    for(int i = 1; i <= n; i++){
        if(sub[i] != bt[i]) return 0;
    }

    return 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        cout << (work() ? "YES\n" : "NO\n");
    }
    return 0;
}
