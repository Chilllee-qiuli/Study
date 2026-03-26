// 代码取自洛谷题解第一篇
inline void solve () {
    cin >> n;
    vector <bitset <N>>bit(n + 1);
    for (int i = 1; i <= n; ++ i) {
        cin >> s[i];
        for (int j = 1; j <= n; ++ j) {
            if (s[i][j - 1] == '1') bit[i].set (j);
        }
    }
    for (int i = 1; i <= n; ++ i)
        if (!bit[i][i]) { cout << "No" << endl; return; }//自己必须能到达自己
    for (int i = 1; i <= n; ++ i)
        for (int j = i + 1; j <= n; ++ j)
            if (bit[i][j] && bit[j][i]) { cout << "No" << endl; return; }//不能出现环
            
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= n; ++ j)
            if (bit[i][j] && (bit[j] & ~bit[i]).any ()) { cout << "No" << endl; return; }//第三种情况
            
    for (int i = 1; i <= n; ++ i) sz[i] = bit[i].count();
    vector <int> ans (n);
    iota (ans.begin(), ans.end(), 1);
    sort (ans.begin(), ans.end(), [&](int x, int y) {
        return sz[x] > sz[y];
    });//一个点能够到达的节点越多说明它在原树中越浅
    vector <pair <int, int>> edges;
    for (int i = 1; i <= n; ++ i) {
        bitset<N> dir = bit[i];
        dir.reset (i);
        vector <int> nn;
        for (int j : ans) {
            if (j == i) continue;
            if (bit[i][j]) nn.emplace_back(j);
        }
        for (int j : nn) {
            if (dir[j]) {
                edges.emplace_back(i, j);
                dir &= ~bit[j];//去除满足 i->j->k 的所有 i->k 的边
                // 这里写法很巧妙，而且由于直接儿子肯定在前面，故正确性有所保障
            }
        }
    }
    if (edges.size() != n - 1) { cout << "nO" << endl; return; }//不连通
    for (int i = 1; i <= n; ++ i) fa[i] = i, rk[i] = 1;
    for (auto [u, v] : edges) join (u, v);
    int rt = find(1);
    for (int i = 2; i <= n; ++ i)
        if (find(i) != rt) { cout << "nO" << endl; return; }//不连通
    cout << "yEs" << endl;
    for (auto [u, v] : edges) cout << u << " " << v << endl;
}
