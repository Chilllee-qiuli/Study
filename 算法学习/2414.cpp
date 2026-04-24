#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pr pair<int, int>
#define mk make_pair
#define fi first 
#define se second
const int Len = 1e5 + 10;
const int maxn = 1e5 + 10;

struct node{
    int son[27];
    int fail;
    int in;
    int dfn;
}tr[Len];
int tot;

vector<int> g[maxn];

void build(){

    queue<int> qu;
    for(int i = 0; i < 26; i++)
        if(tr[0].son[i]) {
            qu.push(tr[0].son[i]);
            g[0].push_back(tr[0].son[i]);    
        }



    while(!qu.empty()){
        int u = qu.front();
        qu.pop();
        for(int i = 0; i < 26; i++){
            if(tr[u].son[i]){
                int son = tr[u].son[i];
                tr[son].fail = tr[tr[u].fail].son[i];
                g[tr[tr[u].fail].son[i]].push_back(son);
                qu.push(son);
            }
            else tr[u].son[i] = tr[tr[u].fail].son[i];
        
        }
    }
}
int Dfn, siz[Len];
void dfs(int u){
    tr[u].dfn = ++Dfn;
    siz[u]++;
    for(auto v : g[u]){
        dfs(v);
        siz[u] += siz[v];
    }
}

struct qq{
    int x, y, id;
    ll ans;
}ask[maxn];

ll sum[Len];

ll fd(int x){
    ll ans = 0;
    for(; x; x -= x & (-x)) ans += sum[x];
    return ans;
}

void add(int x, ll num){
    for(; x < Len; x += x & (-x)) sum[x] += num;
}
int id_p[Len];
int stk[Len];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);


    string str;
    cin >> str;
    
    int top = 0;
    for(int i = 0, p = 0, id = 0; i < str.length(); i++){
        if(str[i] == 'P') {
            ++id;
            id_p[id] = p;
            continue;
        }
        if(str[i] == 'B'){
            top = max(top - 1, 0);
            p = stk[top];
            continue;
        }
        int c = str[i] - 'a';
        if(!tr[p].son[c]) tr[p].son[c] = ++tot;
        p = tr[p].son[c];
        stk[++top] = p;
    }

    build();
    dfs(0);
    int Q;
    cin >> Q;

    for(int i = 1; i <= Q; i++){
        int x, y;
        cin >> x >> y;
        ask[i].x = x; ask[i].y = y;
        ask[i].id = i;
    }
    sort(ask + 1, ask + 1 + Q, [&](qq x, qq y){
        return x.y < y.y;
    });

    top = 0;
    stk[0] = 0;
    for(int i = 0, p = 0, id = 0, pos = 1; i < str.length() && pos <= Q; i++){
        if(str[i] == 'P') {
            ++id;
            while(pos <= Q && ask[pos].y == id) {
                int x = ask[pos].x;
                int u = id_p[x];
                ask[pos].ans = fd(tr[u].dfn + siz[u] - 1) - fd(tr[u].dfn - 1);
                pos++;
            }
        }
        else if(str[i] == 'B'){
            add(tr[p].dfn, -1);
            top = max(top - 1, 0);
            p = stk[top];
        }
        else{
            int c = str[i] - 'a';
            if(!tr[p].son[c]) tr[p].son[c] = ++tot;
            p = tr[p].son[c];
            stk[++top] = p;
            add(tr[p].dfn, 1);
        }
    }

    sort(ask + 1, ask + 1 + Q, [&](qq a, qq b){
        return a.id < b.id;
    });

    for(int i = 1; i <= Q; i++)
    cout << ask[i].ans << endl;

	return 0;
}