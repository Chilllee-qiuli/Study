#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 55;
int a[maxn][maxn];
int t;
int n, k;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k;
        if(k < n || k > n * n - n + 1) cout << "No\n";
        else {
            for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++) a[i][j] = 0;
            
            a[1][1] = k;
            for(int i = 2; i <= n; i++) a[1][i] = i - 1;
            int l = n, r = n * n;

            for(int j = n; j >= 2; j--) {
                a[j][j] = r;
                r--;
            }

            for(int i = 2; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(!a[i][j]){
                    if(l == k) l++;
                    a[i][j] = l;
                    l++;
            }
            
            cout << "Yes\n";
            for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
            cout << a[i][j] << " \n"[j == n];
        }
    }

	return 0;
}
