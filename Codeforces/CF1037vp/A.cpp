#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        int x, ans;
        cin >> x;
        ans = x;
        while(x){
            ans = min(ans, x % 10);
            x /= 10;
        }
        cout << ans << endl;
    }

	return 0;
}
