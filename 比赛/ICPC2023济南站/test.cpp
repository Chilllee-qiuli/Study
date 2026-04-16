#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3030;
const ll mod = 998244353;

int n, m;
char tmp[3030];
string s;
int ans;
ll a[5][maxn];

bool check(){
    for(int i = 1; i <= n - m + 1; i++){
        int flag = 1;
        for(int j = 0; j < m; j++)
            if(tmp[i + j] != s[j]) {
                flag = 0;
                break;
            }
        if(flag == 1) return 1;
    }
    return 0;
}

char getch(int x){
    if(x == 1) return 'A';
    if(x == 2) return 'T';
    if(x == 3) return 'G';
    return 'C';
}

void dfs(int u, ll p){
    if(!p) return ;
    if(u > n){
        if(check()) ans = (ans + p) % mod;
        return;
    }
    for(int i = 1; i <= 4; i++){
        tmp[u] = getch(i);
        dfs(u + 1, p * a[i][u] % mod);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    cin >> s;
    for(int i = 1; i <= n; i++)
    cin >> a[1][i] >> a[2][i] >> a[3][i] >> a[4][i];

    dfs(1, 1);

    cout << ans << endl;


	return 0;
}
