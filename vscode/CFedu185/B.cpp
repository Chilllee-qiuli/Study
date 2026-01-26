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
        ll sum = 0, cnt = 0;
        for(int i = 1; i <= n; i++) {
            cin >> b[i];    
            sum += b[i];
            cnt += (b[i] != 0);
        }
        sum -= cnt;
        if(n <= sum + 1) cout << cnt << endl;
        else cout << cnt - (n - sum - 1) << endl;

    }


	return 0;
}
