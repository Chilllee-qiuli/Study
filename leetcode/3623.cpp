#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        map<int , long long> mp;
        const int mod = 1e9 + 7;
        for(auto it : points){
            mp[it[1]]++;
        }
        //for(auto it : line) sort(it.begin(), it.end());
        
        vector<long long> tmp;
        for(auto it : mp) tmp.push_back(it.second);

        for(int i = 0; i < tmp.size(); i++) tmp[i] = tmp[i] * (tmp[i] - 1) / 2 % mod;

        long long cnt = 0, ans = 0;
        for(int i = 0; i < tmp.size(); i++){
            ans += (tmp[i] * cnt) % mod;
            cnt += tmp[i];
            cnt %= mod;
        }
        return ans % mod;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cout << countTrapezoids

	return 0;
}