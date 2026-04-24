#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxc = 5.1e5 + 10;
const int maxn = 1e5 + 10;
int nex[maxc][27];
int exist[maxc];
int cnt;
ll n;
string s[maxn];
vector<int> g[maxn];


void insert(string& s, int id) {  // 插入字符串
    int p = 0;
    int l = s.length();
    for (int i = 0; i < l; i++) {
      int c = s[i] - 'a';
      if (!nex[p][c]) nex[p][c] = ++cnt; 
      p = nex[p][c];
    }
    exist[p] = id;
}


void op(string &s, int id){
    int p = 0;
    int l = s.length();
    int bar = 0; //  找到最长的前缀
    for (int i = 0; i < l; i++) {
      int c = s[i] - 'a';
      if(exist[p]) bar = exist[p];
      p = nex[p][c];
    }
    g[bar].push_back(id);
}
int siz[maxn];
ll ans = 0;
int pos[maxn], tot;
void predfs(int u){
    siz[u]++;
    for(auto v : g[u]){
        predfs(v);
        siz[u] += siz[v];
    }
    sort(g[u].begin(), g[u].end(), [&](int x, int y){
        return siz[x] < siz[y];
    });
}
void dfs(int u){
    pos[u] = ++tot;
    for(auto v : g[u]){
        dfs(v);
        ans += pos[v] - pos[u];
    }   
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> s[i];
        reverse(s[i].begin(), s[i].end());
        insert(s[i], i);
    }

    for(int i = 1; i <= n; i++) op(s[i], i);
    predfs(0);
    dfs(0);
   
    cout << ans  << endl;
    



	return 0;
}
