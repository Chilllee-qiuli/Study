#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int t;
int n;
int ans[maxn];

void so(){
    cin >> n;
    if(n & 1){
        cout << n - 1 << " ";
        for(int i = 2; i <= n - 1; i++){
            if(i & 1) cout << i - 1 << " ";
            else cout << i + 1 << " ";
        }
        cout << 1 << endl;
    }
    else {
        int m = n & (-n);
        if(n == m) {
            cout << -1 << endl;
            return ;
        }
        for(int i = 1; i <= n; i++)ans[i] = i;
        for(int i = 2; i <= n - 2; i+=2) swap(ans[i], ans[i + 1]);

        swap(ans[1], ans[n]);
        swap(ans[1], ans[m]);
        for(int i = 1; i <= n; i++) cout << ans[i] << " ";
        cout << endl;

    }
    
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T--) so();

    return 0;
}