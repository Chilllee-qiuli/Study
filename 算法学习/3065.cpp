#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e4 + 10;
const int maxm = 3e5 + 10;

struct trie {
  int nex[maxm][26], cnt = 0;
  int exist[maxm];

  void insert(string s, int l) {  // 插入字符串
    int p = 0;
    for (int i = 0; i < l; i++) {
      int c = s[i] - 'a';
      if (!nex[p][c]) nex[p][c] = ++cnt;  // 如果没有，就添加结点
      p = nex[p][c];
    }
    exist[p]++;
  }

  bool find(string s, int l) {  // 查找字符串
    vector<int> in(27, 0);
    vector<int> g[27];
    int p = 0;
    for(int i = 0; i < l; i++){
        if(exist[p]) return 0;
        int c = s[i] - 'a';
        for(int j = 0 ; j < 26; j++)
            if(nex[p][j] && j != c) {++in[j]; g[c].push_back(j);}   
        p = nex[p][c];
    }
    queue<int> qu;
    for(int i = 0; i < 26; i++)
        if(!in[i]) qu.push(i);
    
    int tot = 0;
    while(!qu.empty()){
        int u = qu.front(); qu.pop();
        tot++;
        for(auto v : g[u])
            if(--in[v] == 0) qu.push(v);
    }

    return tot == 26;
  }
}tr;

string s[maxn];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> s[i];
        tr.insert(s[i], s[i].length());
    }

    int ans = 0;
    vector<string> tmp;
    for(int i = 1; i <= n; i++)
        if(tr.find(s[i], s[i].length())){
            ans++;
            tmp.push_back(s[i]);
        }
    cout << ans << endl;
    for(auto it : tmp) cout << it << "\n";

	return 0;
}
