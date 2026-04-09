#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;

int n, m;
int fa[maxn];
int find(int x){
    if(x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}
void merge(int x, int y){
    int fx = find(x), fy = find(y);
    if(fx != fy) fa[fx] = fy;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) fa[i] = i;

    for(int i = 1; i <= m; i++){
        int op, x, y;
        cin >> op >> x >> y;
        if(op == 1) merge(x, y);
        else {
            int fx = find(x), fy = find(y);
            if(fx == fy) cout << "Y\n";
            else cout << "N\n";
        }
    }

    

    return 0;
}