#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 6000 + 100;
const int mod = 1e4 + 7;

int n, m;

struct node{
    int nxt[26];
    int fail;
    int cnt;
} tr[maxn];
int tot;

void insert(string s){
    int l = s.length();
    int p = 0;
    for(int i = 0; i < l; i++){
        int c = s[i] - 'a';
        if(!tr[p].nxt[c]) tr[p].nxt[c] = ++tot;
        p = tr[p].nxt[c];
    }
    tr[p].cnt++;
}

void build(){
    queue<int> q;
    for(int i = 0; i < 26; i++)
        if(tr[0].nxt[i]) q.push(tr[0].nxt[i]);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0; i < 26; i++){
            if(tr[u].nxt[i]){
                int nxt = tr[u].nxt[i];
                tr[nxt].fail = tr[tr[u].fail].nxt[i];
                q.push(tr[u].nxt[i]);
                tr[nxt].cnt += tr[tr[nxt].fail].cnt;
            }
            else tr[u].nxt[i] = tr[tr[u].fail].nxt[i];
        }
    }
}

int f[110][maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        insert(s);
    }

    


	return 0;
}
