#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 210;

vector<int> g[maxn];
int n;
int a[maxn], pos[maxn];
int vis[maxn];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    for(int i = 1; i <= n; i++)
    sort(g[i].begin(), g[i].end(), [](int &x, int & y){
        return pos[x] < pos[y];
    });

    queue<int> qu;
    vector<int> tmp;
    vis[1] = 1;
    qu.push(1);
    while(!qu.empty()){
        int u = qu.front();
        qu.pop();
        tmp.push_back(u);
        for(auto v : g[u]){
            if(!vis[v]) {
                vis[v] = 1;
                qu.push(v);
            }
        }
    }

    for(int i = 1; i <= n; i++)
        if(tmp[i - 1] != a[i]){
            cout << "No" << endl;
            return 0;
        }

        cout << "Yes\n";


    return 0;
}