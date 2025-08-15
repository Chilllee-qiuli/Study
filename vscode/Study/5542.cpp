#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3+10;
int n, k, ans;

int mp[maxn][maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        int Ax, Ay, Bx, By;
        cin >> Ax >> Ay >> Bx >> By;
        Ax++; Ay++;
        mp[Ax][Ay]++;
        mp[Bx+1][By+1]++;
        mp[Ax][By+1]--;
        mp[Bx+1][Ay]--;
    }

    for(int i = 1; i <= 1000; i++)
    for(int j = 1; j <= 1000; j++){
        mp[i][j] += mp[i-1][j] + mp[i][j-1] - mp[i-1][j-1];
        //cout << mp[i][j] << " \n"[j == 8];
        if(mp[i][j] == k) ans++;
    }
    
    cout << ans << endl;

	return 0;
}