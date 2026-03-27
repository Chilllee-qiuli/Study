#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e6 + 10;
// P8306 【模板】字典树 / Trie：
// 查询给定串是多少个模式串的前缀
struct trie {
  int nex[maxn][66], cnt;
  int exist[maxn];  // 该结点为前缀的字符串个数

  int getnum(char x){ // 由于此题又大小写字母与数字共存，故先做好映射
    if(x >= 'A' && x <= 'Z') return x - 'A';
    else if(x >= 'a' && x <= 'z') return x - 'a' + 26;
    else return x - '0' + 52;
  } 

  void init(){ // 多测清空
    for (int i = 0; i <= cnt; i++) {
        memset(nex[i], 0, sizeof(nex[i]));
        exist[i] = 0;
    }
    cnt = 0;
  }

  void insert(char *s, int l) {  // 插入字符串
    int p = 0;
    for (int i = 0; i < l; i++) {
      int c = getnum(s[i]);
      if (!nex[p][c]) nex[p][c] = ++cnt;  // 如果没有，就添加结点
      p = nex[p][c]; // 先走到当前节点
      exist[p]++;
    }
  }

  int find(char *s, int l) {  // 查找字符串
    int p = 0;
    for (int i = 0; i < l; i++) {
      int c = getnum(s[i]);
      if (!nex[p][c]) return 0;
      p = nex[p][c]; // 
    }
    return exist[p];
  }
}tr;


char s[maxn];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n, q;
        tr.init();
        cin >> n >> q;
        for(int i = 1; i <= n; i++) {
            cin >> s;
            tr.insert(s, strlen(s));
        }
        while(q--){
            cin >> s;
            cout << tr.find(s, strlen(s)) << "\n";
        }
    }
	return 0;
}
