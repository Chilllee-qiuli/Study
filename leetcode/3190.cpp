#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        ll ans = 0;
        for(auto it : nums){
            it %= 3;
            ans += (it != 0);
        }

        cout << ans << endl;
        return ans;
    }
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

	return 0;
}