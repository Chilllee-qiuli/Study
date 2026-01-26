#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, k;

int gra[550][550], boom[550][550];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> k;

    while(k--){
        int i, j;
        cin >> i >> j;
        boom[i][j] = 1;
        gra[i-1][j]++;
        gra[i-1][j-1]++;
        gra[i-1][j+1]++;
        gra[i][j-1]++;
        gra[i][j + 1]++;
        gra[i + 1][j - 1]++;
        gra[i + 1][j]++;
        gra[i + 1][j + 1]++;
    }

    for(int i = 1; i <= n; i++, cout << endl)
    for(int j = 1; j <= m; j++){
        if(boom[i][j]) cout << "B ";
        else cout << gra[i][j] << " ";
    }



	return 0;
}
