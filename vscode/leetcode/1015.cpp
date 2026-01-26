#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


class Solution {
public:
    int smallestRepunitDivByK(int k) {
        unsigned long long x = 1;
        for(int i = 1; i <= 100; i++){
            if(x % k == 0) return i;
            x = x * 10 + 1;
            x %= k;
        }
        return -1;
    }
};
/*
class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int resid = 1 % k, len = 1; // resid为余数，len为数字长度，初始值为1
        unordered_set<int> st; // 创建一个无序集合，用于存储余数
        st.insert(resid); // 插入余数1
        while (resid != 0) { // 当余数为0时退出循环
            resid = (resid * 10 + 1) % k; // 计算下一个余数
            len++; // 数字长度+1
            if (st.find(resid) != st.end()) { // 如果余数重复出现，则无解
                return -1;
            }
            st.insert(resid); // 将余数插入集合
        }
        return len; // 返回数字长度
    }
};

作者：力扣官方题解
链接：https://leetcode.cn/problems/smallest-integer-divisible-by-k/solutions/2263173/ke-bei-k-zheng-chu-de-zui-xiao-zheng-shu-ynog/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

	return 0;
}