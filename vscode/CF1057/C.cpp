#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int n;
const int maxn = 2e5 + 10;


map<ll, int> mp;

int main(){
    //freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);


    cin >> t;
    while(t--){
        cin >> n;
        mp.clear();
        for(int i = 1; i <= n; i++) {
            ll x;
            cin >> x;
            mp[x]++;
        }

        int cnt = 0;
        ll ans = 0;
        for(auto v : mp)
            if(v.second > 1) {
                int num = v.second/2;
                cnt += num;
                ans += v.first*num*2;
            }
        

        if(!cnt) cout << 0 << endl;
        else {
            vector<ll> tmp;
            for(auto v : mp) if(v.second & 1) tmp.push_back(v.first); 
            

            sort(tmp.begin(), tmp.end());


            if(tmp.size() > 1)
            for(int i = tmp.size() - 1; i >= 0; i--){
                if(i == 0){
                    if(tmp[0] < ans) cout << ans + tmp[0] << endl;
                    else if(cnt > 1) cout << ans << endl; 
                    else cout << 0 << endl;
                    break;
                }
                else if(tmp[i] < ans + tmp[i-1]) {
                    cout << ans + tmp[i] + tmp[i-1] << endl;
                    break;
                }
            }
            else if(tmp.size()){
                if(tmp[0] < ans) cout << ans + tmp[0] << endl;
                else if(cnt > 1) cout << ans << endl; 
                else cout << 0 << endl;
            }
            else if(cnt > 1) cout << ans << endl; 
            else cout << 0 << endl;



        }

    }

	return 0;
}
