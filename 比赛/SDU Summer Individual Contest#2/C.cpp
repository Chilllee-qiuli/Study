#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9;
string s;
int k, n;
struct node {
    char ch;
    int c;
};
ll c[200][200];
ll dp[200][200][200];

void pre(){
    cin >> s;
    cin >> k;
    cin >> n;
    for(int i = 1; i <= n; i++){
        char x, y;
        int z;
        cin >> x >> y >> z;
        c[x][y] = z;

    }
    // for(int i = 'a', maxc = -inf; i <= 'z'; i++)
    //     for(int j = 'a'; j <= 'z'; j++)
    //         if(c[i][j] > maxc) 
    //         {
    //             maxc = c[i][j];
    //             maxx[i] = j;
    //         }
        
    
    s = "1" + s; 
    n = s.size() - 1;

    

    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= k; j++)
        for(int x = 'a'; x <= 'z'; x++)
        dp[i][j][x] =  -inf;
    }
    for(int j = 0; j <= k; j++)
    for(int x = 'a'; x <= 'z'; x++)
    dp[1][j][x] = 0;

    for(int i = 2; i <= n; i++) 
        dp[i][0][s[i]] = dp[i-1][0][s[i-1]] + c[s[i-1]][s[i]];
    

    

}

char tr[200];

int main(){

    //freopen("1.in", "r", stdin);

    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    pre();
    
    

    for(int i = 2; i <= n; i++){
        ll tmpp = -inf;
        for(int j = 1; j <= k; j++)
            for(int x = 'a'; x <= 'z'; x++)
            for(int y = 'a'; y <= 'z'; y++){
                if(y == s[i]) {
                    dp[i][j][y] = max(dp[i][j][y], dp[i-1][j][x] + c[x][y]);
                } else {
                    dp[i][j][y] = max(dp[i][j][y], dp[i-1][j-1][x] + c[x][y]);
                }
            }
    }

    ll ans = dp[n][0][0];
    for(int i = 0; i <= k; i++)
    for(int y = 'a'; y <= 'z'; y++)
    ans = max({ans, dp[n][i][y], dp[n][i][y]});



    cout << ans << endl;


	return 0;
}
