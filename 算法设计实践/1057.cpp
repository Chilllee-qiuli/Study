#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
int n;
int t;

int main(){
    freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    while(cin >> n){

        int minn = inf;
        int ans = -inf;
        for(int i = 1; i <= n; i++){
            int x;
            cin >> x;
            ans = max(x - minn, ans);
            minn = min(x, minn);
        }

        cout << ans << endl;
    }

	return 0;
}