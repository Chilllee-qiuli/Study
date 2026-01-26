#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2000 * 75 + 10;
int trie[maxn][27];
int word[maxn];
char str[80];
int n, tot, ans = 0;

void insert(char *str){
    int rot = 0; // 当前子树根节点
    int len = strlen(str);
    int res = 0 ; // 表示字典树路径上存在有几个别的单词，用于这道题统计答案
    for(int i = 0; i < len; i++){
        int c = str[i] - 'a';
        if(trie[rot][c] == 0)// 没有这个节点
        trie[rot][c] = ++tot;
        rot = trie[rot][c]; // 跳到该节点
        res += word[rot];
    }
    word[rot]++;
    if(res + 1 > ans) ans = res + 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> str;
        insert(str);
    }

    cout << ans << endl;






	return 0;
}
