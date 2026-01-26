#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int n, q;
int p[maxn][32];
int num[maxn][32];
int pre_2[maxn];

void pre(){
    for(int j = 1; (1 << j) < n; j++)
    for(int i = 1;  i + (1 << j) - 1 <= n; i++){
        p[i][j] = max(p[i][j - 1], p[i + (1 << j - 1)][j - 1]);
    }

    for(int i = 2; i <= n; i++) pre_2[i] = pre_2[i >> 1] + 1;
}


ll qrymax(int l, int r){
    int len = r - l + 1;
    len = pre_2[len];
    return max(p[l][len], p[r - (1 << (len)) + 1][len]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> q ;
    for(int i = 1; i <= n; i++) cin >> p[i][0];
    pre();

    while(q--){
        int a, b;
        cin >> a >> b;
        cout << qrymax(a, b) << endl;
    }

	return 0;
}