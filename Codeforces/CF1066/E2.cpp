#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 6e5 + 10;
int t;
int n, k;
int cnt[maxn];

int main(){
    //freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        ll ans = 0;
        cin >> n >> k;
        for(int i = 1; i <= n * 3; i++) cnt[i] = 0;
        for(int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            cnt[x]++;
        }
        int flag = 0;
        for(int i = 1, tmp = 0; i <= n * 3 + 1; i++){
            cnt[i] += tmp;
            if(cnt[i] > k) {
                flag = 1;
                tmp = cnt[i] - 1;
                ans ++;
            }
            else tmp = 0;
        }

        

        cout << ans << endl;
    }

	return 0;
}
