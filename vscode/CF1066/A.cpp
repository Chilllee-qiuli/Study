#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int t;
int n;
map<int, int> mp;



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        mp.clear();

        for(int i = 1; i <= n; i++){
            int x;
            cin >> x;
            mp[x]++;
        }
        ll ans = 0;
        for(auto x : mp){
            if(x.second < x.first) ans += x.second;
            else ans += x.second - x.first;
        }
        cout << ans << endl;
    }

	return 0;
}
