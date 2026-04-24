#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxl = 2e6 + 10;
int m, n;

struct trie {
  int nex[maxl][26], cnt;
  int sum[maxl];
  int exist[maxl];

  void insert(char *s, int l) {  // 插入字符串
    int p = 0;
    for (int i = 0; i < l; i++) {
      int c = s[i] - '0';
      if (!nex[p][c]) nex[p][c] = ++cnt;  // 如果没有，就添加结点
      p = nex[p][c];
      sum[p]++;
    }
    exist[p]++;
  }

  int find(char *s, int l) {  // 查找字符串
    int p = 0;
    int ans = 0;
    for (int i = 0; i < l; i++) {
      int c = s[i] - '0';
      if (!nex[p][c]) return ans;
      p = nex[p][c];
      ans += exist[p];
    }
    return ans + sum[p] - exist[p];
  }
}tr;
char s[maxl];

int main(){
    //freopen("P2922_2.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> m >> n;
    for(int i = 1; i <= m; i++){
        int b;
        cin >> b;
        for(int j = 0; j < b; j++) cin >> s[j];
        tr.insert(s, b);
    }
    for(int i = 1; i <= n; i++){
        int c;
        cin >> c;
        for(int j = 0; j < c; j++) cin >> s[j];
        cout << tr.find(s, c) << "\n";
    }


	return 0;
}
