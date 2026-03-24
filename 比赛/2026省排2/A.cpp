#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1010;
int a[maxn][maxn];
int n, m, k;

bool judge(int x, int y){
    return a[x][y] & a[x - 1][y - 1] & a[x - 1][y] & a[x][y - 1];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> k;
    int flag = 0;
    for(int b = 1; b <= k; b++){
        int i, j;
        cin >> i >> j;
        a[i][j] = 1;
        if(judge(i, j) || judge(i, j + 1) || judge(i + 1, j) || judge(i + 1, j + 1)){
            if(!flag) flag = b;
        }
    }
    cout << flag << endl;


    return 0;
}