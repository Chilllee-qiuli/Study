#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e4 + 10;
int n, m;
int a[maxn], b[maxn];
int dp[2][maxn];

vector<int> tmp[110];

vector<int> c;

int main(){
    //freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i];
    
    for(int i = 1; i <= m; i++){
        tmp[b[i]].push_back(i);
    }
    for(int i = 1; i <= 100; i++)
    sort(tmp[i].begin(), tmp[i].end(), greater<int>());

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < tmp[a[i]].size() - 1; j++)
        c.push_back(tmp[a[i]][j]);
    }

    


    return 0;
}