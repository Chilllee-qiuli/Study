#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 110;
int f[maxn][maxn];
int n, m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        f[x][y] = 1;
    }

    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                f[i][j] = f[i][j] | (f[i][k] & f[k][j]);
    

    int ans = 0;
    for(int i = 1; i <= n; i++){
        int flag = 1;
        for(int j = 1; j <= n; j++)
            if(i != j){
                if(f[i][j] | f[j][i]) continue;
                flag = 0;
                break;
            }
        
        if(flag) ans++;
    }
    cout << ans << endl;

	return 0;
}