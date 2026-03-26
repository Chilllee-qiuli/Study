#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 33;
int n;
ll f[maxn][maxn];
int root[maxn][maxn];


void print(int u, int l, int r){
    if(l > r) return ; 
    cout << u << " ";
    if(l == r) return ;
    print(root[l][u - 1], l, u - 1);
    print(root[u + 1][r], u + 1, r);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);


    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> f[i][i];
        f[i][i - 1] = 1; // 空子树为1
        root[i][i] = i;
    }
    f[n + 1][n] = 1;

    for(int len = 2; len <= n; len++)
    for(int l = 1; l + len - 1 <= n; l++){
        int r = l + len - 1;
        for(int k = l; k <= r; k++){ // 枚举断点，注意左右子树为空时自然无权值，我们已经设置空子树为1
            ll tmp = f[l][k - 1] * f[k + 1][r] + f[k][k];
            if(tmp > f[l][r]){
                f[l][r] = tmp;
                root[l][r] = k;
            }
        }
    }
    cout << f[1][n] << endl;
    print(root[1][n], 1, n);


	return 0;
}
