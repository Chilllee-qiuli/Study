#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

unordered_map<ll, int> mp;
int n;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++){
        ll x;
        cin >> x;
        mp[x]++;
    }

    vector<ll> res;

    for(auto& it : mp){
        if(it.second % 2 != 0){
            res.push_back(it.first);
        }
    }

    sort(res.begin(), res.end());
    cout << res[0] << " " << res[1] << "\n";

	return 0;
}