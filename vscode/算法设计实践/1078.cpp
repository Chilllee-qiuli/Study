#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int n, q;
int st[maxn][22];
int log_2[maxn];

int qrymax(int l, int r){
    int x = log_2[r - l + 1];
    return max(st[l][x], st[r - (1 << x) + 1][x]);
}

void pre(){
    for(int j = 1; (1 << j) < n; j++)
    for(int i = 1; i <= n - (1 << j) + 1; i++)
    st[i][j] = max(st[i][j-1], st[i + (1 << j - 1)][j-1]);
}


int main(){
    //freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> st[i][0];

    for(int i = 2; i <= n; i++) log_2[i] = log_2[i >> 1] + 1;

    pre();

    while(q--){
        int l, r;
        cin >> l >> r;
        cout << qrymax(l, r) << endl;
    }

	return 0;
}