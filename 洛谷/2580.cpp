#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e4*50 + 10;

int trie[maxn][27];
int word[maxn], cnt[maxn];

char str[90];

int n, m, tot;
void insert(char str[]){
    int u = 0;
    int len = strlen(str);
    for(int i = 0; i < len; i++){
        int a = str[i] - 'a';
        if(trie[u][a] == 0) trie[u][a] = ++tot;
        u = trie[u][a];
    }
    word[u]++;
}

int find(char *str){
    int u = 0;
    int len = strlen(str);
    for(int i = 0; i < len; i++){
        int a = str[i] - 'a';
        if(trie[u][a] == 0) return -1;
        u = trie[u][a];
    }
    return word[u] ? cnt[u]++ : -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> str;
        insert(str);
    }
    cin >> m;
    while(m--){
        cin >> str;
        int res = find(str);
        if(res == -1) cout << "WRONG" << endl;
        else if(res == 0) cout << "OK" << endl;
        else cout << "REPEAT" << endl;
    }

	return 0;
}
