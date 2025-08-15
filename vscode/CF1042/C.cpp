#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5+120;
int T;
int n, k;
map <int, int> mp;

bool judge(){
    for(auto it : mp){
        if(!it.second) continue;

        int x = abs(it.first - k);
        //cout << "x: " << x <<  endl;
        while(it.second > 0){
            //cout << "mp[x] " << mp[x] << endl;
            if(mp[x] >= 0) return 0;
            it.second--;
            mp[it.first]--;
            mp[x]++;
        }
        while(it.second < 0) {
            if(mp[x] <= 0) return 0;
            it.second++;
            mp[it.first]++;
            mp[x]--;
        }
    }
    return 1;
}

int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--){
        mp.clear();
        cin >> n >> k;
        int x = 0;
        for(int i = 1; i <= n; i++) {cin >> x; x %= k, mp[x]++;}
        for(int i = 1; i <= n; i++) {cin >> x; x %= k, mp[x]--;}
        
        if(judge()) cout << "YES" << endl;
        else cout << "NO" << endl;
        //for(auto it : mp) cout << "test: " << it.first << " " << it.second << endl;
        
 
    }
    

	return 0;
}