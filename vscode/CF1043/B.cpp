#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll n;

int main(){
    //freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        vector<ll> ans;
        for(ll x = 10; x + 1 <= n; x *= 10){
            if(n % (x + 1) == 0) ans.push_back(n/(x + 1));
        }
        cout << ans.size() << endl;
        sort(ans.begin(), ans.end());
        if(!ans.empty()){
            for(auto it : ans) cout << it << " ";
            cout << endl;
        }
    }

	return 0;
}
