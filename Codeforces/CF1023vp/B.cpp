#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int t;
int n, k;
map<int, int> mp;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k;
        mp.clear(); 
        ll sum = 0;
        ll maxx = 0, minn = 0x3f3f3f3f;
        for(int i = 1; i <= n; i++){
            ll x; cin >> x;
            sum += x;
            mp[x]++;
            maxx = max(maxx, x);
            minn = min(minn, x);
        }
        if(maxx - minn > k + 1 || (maxx - minn == k + 1 && mp[maxx] > 1)) cout << "Jerry" << endl;
        else {
            if(sum & 1) cout << "Tom" << endl;
            else cout << "Jerry" << endl;
        }
    }

	return 0;
}
