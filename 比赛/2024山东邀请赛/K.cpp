#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 55;
int a[maxn][maxn];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    if(n == 2 || n == 3){
        cout << "Yes\n";
        if(n == 2){
            cout << "1 2\n3 4\n"; 
        }
        else cout << "3 2 6\n4 3 3\n3 1 5\n";
    }
    else {
        cout << "Yes\n";
        a[1][1] = 1;
        a[1][2] = 2;
        a[2][1] = 3;
        a[2][2] = 4;
        int tag = 6;
        for(int j = 4; j <= n; j++) a[3][j] = tag++;
        for(int i = 4; i <= n; i++) a[i][3] = tag++;
        a[3][3] = 5;
        for(int i = 4; i <= n; i++)
        for(int j = 4; j <= n; j++) 
        a[i][j] = 5;
        for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        if(!a[i][j]) a[i][j] = tag;

        for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        cout << a[i][j] << " \n"[j == n];
        cout << endl;
    }

	return 0;
}
