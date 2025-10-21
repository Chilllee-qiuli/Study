#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;
int a[maxn];
ll sum[maxn];
map<ll, int> mp;
int t;
int n;

int main(){
    //freopen("trip5.in", "r", stdin);
    //freopen("trip.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        mp.clear();
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            sum[i] = sum[i - 1] + a[i];
            mp[sum[i]]++;
        }
        int ans = 0;
        for(auto it : mp){
            ans = max(ans, it.second - 1);
            if(it.first == 0) ans = max(ans, it.second);
        }
        cout << ans << endl;
    }

	return 0;
}
