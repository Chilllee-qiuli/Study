#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // 1. 预处理B的值位置 (升序存储)
    vector<vector<int>> pos(101); 
    for (int j = 0, v; j < M; j++) {
        cin >> v;
        if (v >= 1 && v <= 100) pos[v].push_back(j);
    }

    // 2. 使用动态LIS数组 (不构建C)
    vector<int> d;
    for (int a : A) {
        if (a < 1 || a > 100 || pos[a].empty()) continue;
        
        // 关键优化：逆序遍历同一值的所有位置
        auto& pvec = pos[a];
        for (int k = pvec.size()-1; k >= 0; k--) {
            int p = pvec[k];
            auto it = lower_bound(d.begin(), d.end(), p);
            if (it == d.end()) d.push_back(p);
            else *it = p;
        }
    }

    cout << d.size() << endl;
    return 0;
}