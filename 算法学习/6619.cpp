#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxq = 2e6 + 10;
int Q;
vector<int> lisan;
/*
1. 不用map，离散化完直接用lower_bound找到位置，替换掉所有qus的x
    用时3.20s -> 1.43s
2. 从前往后跳的二进制倍增，只适用于前缀数组，所以火的后缀数组需要用前缀数组的值减去总和来得到
3. 每次更新完后都要从头开始二分，找到最大的k，使得冰的前缀和不超过火的后缀和
    还要考虑k+1的情况，可能会有更大的答案，并且k+1的情况需要再从头开始二分，找到最大的k_2，使得冰的前缀和不超过火的后缀和或者两者相等（因为可能会有多个温度对应同一个答案）
    因为对于同一个ans可能是一段区间，题目要找最大的温度
3.2 第二次倍增必须从头开始，因为从中间倍增树状数组是错的
    特别值得注意的是，不能只使用判等那一个条件，要或上小于等于的条件，先找到区间再移到最大的地方
4. 从前向后跳的树状数组倍增只支持前缀树状数组，从后向前则只支持后缀树状数组
那怎么维护后缀树状数组呢，可以用总和减去 sum[i - 1] 得到 sum[i] 的后缀和
    */
struct Question{
    int op;
    int t;
    int x, y;
} qus[maxq];

struct BIT{
    ll val[maxq];
    void change(int x, int y){
        for (; x < maxq; x += x & -x) val[x] += y;
    }
    ll query(int x){
        ll res = 0;
        for (; x; x -= x & -x) res += val[x];
        return res;
    }
} ice, fire;


ll sumf, sumi;

void pre();
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    pre();
    
    for (int i = 1; i <= Q; i++){
        if (qus[i].op == 1) {
            if (qus[i].t) { // fire
                fire.change(qus[i].x + 1, qus[i].y);
                sumf += qus[i].y;
            }
            else ice.change(qus[i].x, qus[i].y);
        }
        else { // delete
            Question q = qus[i];
            if (qus[q.t].t) {
                fire.change(qus[q.t].x + 1, -qus[q.t].y);
                sumf -= qus[q.t].y;
            }
            else  ice.change(qus[q.t].x, -qus[q.t].y);
        }
        int k = 0; // temperature
        ll ans = 0;
        ll tmpi = 0, tmpf = sumf;
        for (int d = pow(2, 20); d; d >>= 1) {
            if (k + d >= lisan.size()) continue;
            if (tmpi + ice.val[k + d] <= tmpf - fire.val[k + d]){
                tmpi += ice.val[k + d];
                tmpf -= fire.val[k + d];
                k += d;
            }
        }
        ans = max(ans, min(tmpi, tmpf) * 2);
        ll tmpans = 0;
        if(k + 1 < lisan.size()) tmpans = (sumf - fire.query(k + 1)) * 2;

        if(tmpans >= ans) {
            ans = tmpans;
            k++;
            int k_2 = 0;
            tmpi = 0;
            tmpf = sumf;

            for (int d = pow(2, 20); d; d >>= 1){
                if (k_2 + d >= lisan.size())continue;
                if (tmpi + ice.val[k_2 + d] <= tmpf - fire.val[k_2 + d] || min(tmpi + ice.val[k_2 + d], tmpf - fire.val[k_2 + d]) * 2 == ans){
                    tmpi += ice.val[k_2 + d];
                    tmpf -= fire.val[k_2 + d];
                    k_2 += d;
                }
            }
            k_2 = max(k_2, k);
            if (ans == 0)cout << "Peace\n";
            else cout << lisan[k_2] << " " << ans << "\n";
            continue;
        }
        if (ans == 0)cout << "Peace\n";
        else cout << lisan[k] << " " << ans << "\n";
    }

    return 0;
}
void pre(){
    cin >> Q;
    for (int i = 1; i <= Q; i++) {
        cin >> qus[i].op;
        if (qus[i].op == 1) {
            cin >> qus[i].t;
            cin >> qus[i].x >> qus[i].y;
            lisan.push_back(qus[i].x);
        }
        else cin >> qus[i].t;
    }
    lisan.push_back(0);
    sort(lisan.begin(), lisan.end()); 
    lisan.erase(unique(lisan.begin(), lisan.end()), lisan.end());

    for(int i = 1; i <= Q; i++) if (qus[i].op == 1) 
        qus[i].x = lower_bound(lisan.begin(), lisan.end(), qus[i].x) - lisan.begin();
        
    
}