#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int n, m;

int fa[maxn];

int find(int x){
    if(x == fa[x]) return x;
    else return fa[x] = find(fa[x]);
}

void merge(int x, int y){
    int fax = find(x), fay = find(y);
    fa[fay] = fax; // 一定要将一个集合的总父亲挂在另一个集合下，不然会引起集合分裂
}

int main(){
    freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    iota(fa, fa + n, 0); // 并查集一定记得要初始化每一个集合
    for(int i = 1; i <= m; i++){
        int t, a, b;
        cin >> t >> a >> b;
        if(t == 1) merge(a, b);
        else {
            cout << a << " " << b ;
            if(find(a) == find(b)) cout << " Y" << endl;
            else cout << " N" << endl;
        }
    }

	return 0;
}