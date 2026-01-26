#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int t;
int n;
int b[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        int cnt1 = 0, cnt2 = 0;
        ll sum = 0;
        for(int i = 1; i <= n; i++) {
            cin >> b[i];
            cnt1 += (b[i] != 0);
            cnt2 += (b[i] == 1);
            sum += b[i];
        }
        sum -= cnt1;
        if(sum + 1 >= n) cout << cnt1 << endl;
        else cout << cnt1 - (n - sum) + 1 << endl;

    }

	return 0;
}