#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int a[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            if(a[i] <= i) ans++;
        }
        cout << ans << endl;
        

    }

	return 0;
}
