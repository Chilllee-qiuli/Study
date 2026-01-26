#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll inf = 1e18;
int n;
ll f[1010][1010];

int main(){
    //freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;

    for(int i = 1; i <= n; i++)
    for(int j = i; j > 0; j--){
        ll x;
        cin >> x;
        if(i == 1) f[1][1] = x;
        else if(j == 1) f[i][j] = f[i-1][j] + x;
        else if(j == i) f[i][j] = f[i-1][j-1] + x;
        else f[i][j] = max(f[i-1][j], f[i-1][j-1]) + x;
    }

    ll maxx = -inf;
    for(int j = 1; j <= n; j++)
    maxx = max(maxx, f[n][j]);
    cout << maxx << endl;



	return 0;
}