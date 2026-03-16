#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
vector<int> a;
int n;
map<int, int> mp;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while(T--) {    
        cin >> n;
        vector<int> ().swap(a);
        mp.clear();
        for(int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());

        for(auto v : a) mp[v] = 1;
        ll ans = 0;
        for(int i = a.size() - 1; i >= 0; i--){
            if(a[i] & 1) continue;
            int cnt = 0;
            while(a[i] % 2 == 0){
                cnt ++;
                a[i] /= 2;
                if(mp[a[i]]) break;
            }
            ans += cnt;
        }

        cout << ans << endl;

    }


    return 0;
}