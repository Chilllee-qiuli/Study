#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
ull的自然溢出是错误的
因为自然溢出是对 2^32 或者 2^64取模
显然会破坏对5取模的正确性
*/


class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> lst;
        unsigned int x = 0;
        for(auto ch : nums){
            if(ch == 0) x <<= 1;
            else x = x << 1 | 1;
            if(x % 5 == 0) lst.push_back(1);
            else lst.push_back(0);
            x %=10;
        }
        return lst;
    }
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

	return 0;
}