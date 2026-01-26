#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long ans = -0x3f3f3f3f3f3f3f3f;
        vector<long long> a(nums.size() + 1, 0);
        a.push_back(0);
        for(int i = 0; i < nums.size(); i++) a[i + 1] = a[i] + nums[i];
        if(k == 1){
            long long tmp = 0;
            for(int i = 0; i < nums.size(); i++) {
                ans = max(ans, 1ll*nums[i]);
            }
            long long tmpp = 0;
            for(int i = 0; i < nums.size(); i++){
                tmp = max(0ll, tmp + nums[i]);
                tmpp = max(tmp, tmpp);
            }
                if(tmpp != 0)ans = max(ans, tmpp);
            return ans;
        }
        
        vector<long long> min_a(nums.size() + 1, 0x1f1f1f1f);
        min_a[0] = 0;
        for(int i = 1; i <= nums.size(); i++){
            int r = i % k;
            ans = max(ans, a[i] - min_a[r]);
            min_a[r] = min(min_a[r], a[i]);

        }
        return ans;
    }
};




int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

	return 0;
}