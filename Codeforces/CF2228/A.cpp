#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        for(int i = 1; i <= n; i++){
            int x;
            cin >> x;
            if(x == 0) cnt0++;
            else if(x == 1) cnt1++;
            else cnt2++;
        }
        int m = min(cnt1, cnt2);
        int ans = cnt0 + m;
        ans += (cnt1 - m) / 3;
        ans += (cnt2 - m) / 3;
        cout << ans << endl;
    }

	return 0;
}
