#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 55;
int a[maxn][maxn];

bool ck(int x, int y, int i, int j){
    return a[x][y] == a[i][j];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
int n;
cin >> n;
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
    cin >> a[i][j];

    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
    for(int x = i + 1; x <= n; x++)
    for(int y = j + 1; y <= n; y++){
        if(ck(i, j, x, y) || ck(i, y, x, j) || ck(i, j, i, y) || ck(i, j, x, j) || ck(x, j, x, y) || ck(i, y, x, y)) continue;
        cout << i << " " << j << " " << x << " " << y << "\n";
    }


	return 0;
}
