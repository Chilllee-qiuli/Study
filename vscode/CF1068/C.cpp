#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
ll a[maxn];
int t;
int n;
ll k;
map<ll, int> mp;
map<ll, int> vis;

bool judge(ll x){
    for(int i = 1; x * i <= k; i++)
    if(!mp[x * i]) return 0;
    return 1;
}

int main(){
    freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
       // cout << "---------" << endl;
        cin >> n >> k;
        mp.clear();
        vis.clear();
        vector<int> vc;
        
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            mp[a[i]]++;
        }    
        //cout << "tst" << endl;
        sort(a + 1, a + 1 + n);

        int flag = 0;

        for(int i = 1; i <= n; i++){
            if(vis[a[i]]) continue;
            if(judge(a[i])) {
                vc.push_back(a[i]);
                //cout << "in: " << a[i] << endl;
                for(int j = 1; a[i] * j <= k; j++) vis[a[i] * j] = 1;
            }
            else flag = 1;
        }

        
        if(flag || vc.empty()) cout << -1 << endl;
        else {
            sort(vc.begin(), vc.end());
            cout << vc.size() << endl;
            for(int i = 0; i < vc.size(); i++) cout << vc[i] << " \n"[(i == (vc.size() - 1))];
        }

    }


	return 0;
}
