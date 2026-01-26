#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e4+10, maxm = 1e5+10;
int n, m, f[maxm*2];

struct node{
    int x, y, z;
    friend bool operator < (node cmpx, node cmpy){
        return cmpx.z > cmpy.z;
    }
}e[maxm];

int find(int x){
    return x == f[x] ? x : f[x] = find(f[x]);
}

void merge(){

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1, a, b, c; i <= m; i++)
        cin >> e[i].x >> e[i].y >> e[i].z;

    sort(e + 1, e + 1 + m);
    iota(f + 1, f + 1 + n*2, 1);

    for(int i = 1; i <= m; i++){
        int x = find(e[i].x), y = find(e[i].y);
        if(x == y) return cout<< e[i].z<< endl, 0;
        int X = find(e[i].x + n), Y = find(e[i].y + n);
        f[x] = Y; f[y] = X;
    }

    cout << 0 << endl;

	return 0;
}
