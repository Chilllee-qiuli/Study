#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Len = 1e6 + 10;
const int maxn = 220;

struct node{
    int son[27];
    int cnt;
    int in;
    int fail;
}tr[Len];
int tot;
int idx[maxn];

void insert(string s, int id){
    int l = s.length();
    int u = 0;
    for(int i = 0; i < l; i++){
        int c = s[i] - 'a';
        if(!tr[u].son[c]) tr[u].son[c] = ++tot;
        u = tr[u].son[c];
        tr[u].cnt++;
    }
    idx[id] = u;
}

void build(){
    queue<int> qu;
    for(int i = 0; i < 26; i++)
        if(tr[0].son[i]) qu.push(tr[0].son[i]);

    while(!qu.empty()){
        int u = qu.front();
        qu.pop();
        for(int i = 0; i < 26; i++)
            if(tr[u].son[i]){
                int son = tr[u].son[i];
                tr[son].fail = tr[tr[u].fail].son[i];
                tr[ tr[tr[u].fail].son[i] ].in ++;
                qu.push(son);
            }
            else tr[u].son[i] = tr[tr[u].fail].son[i];
    }
}

int ans[Len];

void topu(){
    queue<int> q;
    for(int i = 0; i <= tot; i++)
        if(!tr[i].in) q.push(i);
    
    while(!q.empty()){
        int u = q.front();
        q.pop();
        ans[u] = tr[u].cnt;
        int v = tr[u].fail;
        tr[v].cnt += tr[u].cnt;
        if(!--tr[v].in) q.push(v);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        insert(s, i);
    }
    build();

    topu();

    for(int i = 1; i <= n; i++) cout << ans[idx[i]] << "\n";



	return 0;
}
