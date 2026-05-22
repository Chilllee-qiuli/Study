#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;

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
        vector<int> a(n + 1, 0);
        int maxx = 0;
        set<int> now;
        
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            maxx = max(maxx, a[i]);
            mp[a[i]]++;
        }
        
        ll ans = 1ll * n * maxx;
        int mex = 0;
        mp[maxx]--;
        if(maxx == 0) mex = 1;
        now.insert(maxx);
        ans += mex;
        
        int l = 1;
        while(l < n && mp[mex] > 0){
            now.insert(mex);
            while(now.count(mex)) mex++;
            l++;
            ans += mex;
        }
        
        ans += 1ll * (n - l) * mex;

        cout << ans << endl;

    }

	return 0;
}
