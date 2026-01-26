#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    // 计算最大公约数
    ll gcd_ll(ll a, ll b){
        return b == 0 ? a : gcd_ll(b, a % b);
    }

    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        // key = (dx, dy, c) 表示一条直线
        // dx, dy 是方向向量（已约分）
        // c 表示截距相关参数：dx * y - dy * x  (整数表达)
        map<tuple<ll,ll,ll>, int> lineCount;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ll x1 = points[i][0], y1 = points[i][1];
                ll x2 = points[j][0], y2 = points[j][1];

                ll dx = x2 - x1;
                ll dy = y2 - y1;

                // 归一化方向
                if(dx == 0){
                    dy = 1;
                }else if(dy == 0){
                    dx = 1;
                }else{
                    ll g = gcd_ll(abs(dx), abs(dy));
                    dx /= g; dy /= g;
                }

                // 保证方向唯一：例如 (1,2) 和 (-1,-2) 归一
                if(dx < 0 || (dx == 0 && dy < 0)){
                    dx = -dx;
                    dy = -dy;
                }

                // 截距：dx*y - dy*x
                ll c = dx * y1 - dy * x1;

                lineCount[{dx, dy, c}]++;
            }
        }

        // 第二步：按斜率(方向向量) 分组
        map<pair<ll,ll>, vector<int>> slopeGroups;

        for(auto &it : lineCount){
            auto [dx, dy, c] = it.first;
            int cnt = it.second;
            slopeGroups[{dx,dy}].push_back(cnt);
        }

        // 第三步：对每个斜率的所有平行线组合计算梯形数量
        ll ans = 0;

        for(auto &sg : slopeGroups){
            auto &vec = sg.second;
            int m = vec.size();
            if(m < 2) continue;

            // 总线段数
            ll total = 0;
            for(int x : vec) total += x;

            // 如果有 k 条平行线，每条线段数为 si，
            // 任取两条平行线，乘它们线段组合即可形成梯形
            // sum(si * sj)
            ll sumAll = 0;
            for(ll x : vec) sumAll += x * (total - x);

            ans += sumAll / 2; // 每对计算了两次
        }

        return ans;
    }
};
