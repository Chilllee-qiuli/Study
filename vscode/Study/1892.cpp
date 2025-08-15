#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1010, maxm = 5050;
int n, m, f[maxn*2], ans, cnt[maxn], emy[maxn];


struct node{
    int x, y, z;
    friend bool operator < (node cmpx, node cmpy){
        return cmpx.z > cmpy.z;
    }
}e[maxm];

int find(int x){
    return x == f[x] ? x : f[x] = find(f[x]);
}

void merge(int x, int y){
    x = find(x); y = find(y);
    if(x == y) return ;
    f[x] =y;
    return ;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    iota(f + 1, f + n*2, 1);

    for(int i = 1; i <= m; i++){
        char ch;
        int p, q;
        cin >> ch >> p >> q;
        if(ch == 'F') merge(p, q);
        else {
            if(!emy[p]) emy[p] = find(q);
            else merge(emy[p], q);
            if(!emy[q]) emy[q] = find(p);
            else merge(emy[q], p);
        }
    }

    for(int i = 1; i <= n; i++) cnt[find(i)]++;

    for(int i = 1; i <= n; i++) if(cnt[i])ans++;
    
    cout << ans << endl;


    

	return 0;
}