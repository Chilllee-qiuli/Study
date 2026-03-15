#include<bits/stdc++.h>
using namespace std;
#define mk make_pair
#define pr pair<int, int>
typedef long long ll;
const int maxn = 2e5 + 10;
const int maxm = 2e5 + 10;
int T;
int n, m, k;

struct edge{
    int u, v, w;
    int _w;
    int id; 
    friend bool operator < (edge x, edge y){
        return x._w < y._w;
    }
}ed[maxm];
int fa[maxn];

vector<edge> ans;
priority_queue<edge> qu;

void solve_one();
void kruskal();
int find(int x){
    if(x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> T;
    while(T--) solve_one();
    
	return 0;
}

void solve_one(){
    priority_queue<edge> ().swap(qu);
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++){
        cin >> ed[i].u >> ed[i].v >> ed[i].w;
        ed[i].id = i;
    }

    for(int i = 1; i <= n; i++) fa[i] = i;
    

    sort(ed + 1, ed + 1 + m, [](const edge&x, const edge& y){
        return x.w < y.w;
    });

    kruskal();

    ll sum = 0;
    for(auto it : ans) sum += it.w;
    cout << qu.size() << endl;
    while(!qu.empty()){
        cout << qu.top().u << " " << qu.top().v << endl;
        sum += qu.top()._w;
        ans.push_back(qu.top());
        qu.pop();
    }
    cout << sum << endl;
    int cnt = 1;
    for(auto it : ans) 
        if(!it._w) cout << it.id << " ";
        else {
            cout << m + cnt << " ";
            cnt++;
        }

    
    cout << endl;
}

void kruskal(){
    for(int i = 1; i <= m; i++){
        int u = find(ed[i].u);
        int v = find(ed[i].v);
        if(u == v) continue;
        int _w = abs(ed[i].u - ed[i].v);

        if(_w >= ed[i].w) ans.push_back(ed[i]);
        else {
            while(qu.size() >= k && ed[i].w - _w > qu.top()._w) {
                ans.push_back(qu.top());
                qu.pop();
            }
            if(qu.size() < k){
                edge tmp = ed[i];
                tmp._w = ed[i].w - _w;
                qu.push(tmp);
            }
            else ans.push_back(ed[i]);
        }
        fa[v] = u;
    }
}
