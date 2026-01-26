#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 110;
int app[maxn];
int t, n;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        memset(app, 0, sizeof(app));
        for(int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            app[x]++;
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(app[i]){
                ans++;
            }
        }
        cout << ans << endl;
    }

	return 0;
}
