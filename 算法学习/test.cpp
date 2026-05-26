#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e6 + 10;
struct Trie{
    int nxt[maxn][66], cnt;
    int exist[maxn];
    int getnum(char ch){
        if(ch >= 'A' && ch <= 'Z') return ch - 'A';
        else if(ch >= 'a' && ch <= 'z') return ch - 'a' + 26;
        else return ch - '0' + 52;
    }

    void init(){
        for(int i = 0; i <= cnt; i++){
            memset(nxt[i], 0, sizeof(nxt[i]));
            exist[i] = 0;
        }
        cnt = 0;
    }
    void insert(string& s, int len){
        int p = 0;
        for(int i = 0; i < len; i++){
            int c = getnum(s[i]);
            if(!nxt[p][c]) nxt[p][c] = ++cnt;
            p = nxt[p][c];
            exist[p]++;
        }
    }
    int find(string& s, int len){
        int p = 0;
        for(int i = 0; i < len; i++){
            int c = getnum(s[i]);
            if(!nxt[p][c]) return 0;
            p = nxt[p][c];
        }
        return exist[p];
    }
}tr;



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        tr.init();
        for(int i = 1; i <= n; i++){
            string s;
            cin >> s;
            tr.insert(s, s.length());
        }

        while(q--){
            string s;
            cin >> s;
            cout << tr.find(s, s.length()) << "\n";
        }
    }


    return 0;
}