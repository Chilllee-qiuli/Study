#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
const int maxm = 6e5 + 10;

int n, m;
int head[maxn], to[maxm], nxt[maxm], eval[maxm], tot;
int fa[maxn], dep[maxn], siz[maxn], son[maxn], top[maxn];
int val[maxn], dis[maxn]; // 关键修改1: 增加dis数组存储根到节点的距离
int uu[maxn], vv[maxn], lcaa[maxn], path_len[maxn]; // 关键修改2: 存储所有路径信息
int diff[maxn], rak[maxn], dfn[maxn], cnt; // 关键修改3: 增加树上差分相关数组

void adde(int u, int v, int w) {
    nxt[++tot] = head[u];
    to[head[u] = tot] = v;
    eval[tot] = w;
}

// 关键修改4: 重构DFS1，添加距离计算
void dfs1(int u, int f, int d) {
    fa[u] = f; dep[u] = d; siz[u] = 1;
    son[u] = 0;
    for (int i = head[u]; i; i = nxt[i]) {
        int v = to[i];
        if (v == f) continue;
        val[v] = eval[i]; // 边权赋给子节点
        dis[v] = dis[u] + val[v]; // 计算从根到v的距离
        dfs1(v, u, d + 1);
        siz[u] += siz[v];
        if (siz[v] > siz[son[u]]) son[u] = v;
    }
}

// 关键修改5: 重构DFS2，添加DFS序记录
void dfs2(int u, int tp) {
    top[u] = tp;
    dfn[u] = ++cnt;   // DFS序
    rak[cnt] = u;     // DFS序对应的节点
    if (!son[u]) return;
    dfs2(son[u], tp);
    for (int i = head[u]; i; i = nxt[i]) {
        int v = to[i];
        if (v == fa[u] || v == son[u]) continue;
        dfs2(v, v);
    }
}

// 关键修改6: 修复LCA函数
int LCA(int x, int y) {
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        x = fa[top[x]];
    }
    return dep[x] < dep[y] ? x : y;
}

// 关键修改7: 实现二分答案检查函数
bool check(int mid) {
    memset(diff, 0, sizeof(diff)); // 初始化差分数组
    int cnt_path = 0, max_len = 0; // cnt_path: 超过mid的路径数，max_len: 这些路径中的最大长度
    
    // 标记所有超过mid的路径
    for (int i = 1; i <= m; i++) {
        if (path_len[i] > mid) {
            cnt_path++;
            max_len = max(max_len, path_len[i]); // 更新最大长度
            diff[uu[i]]++;    // 路径起点+1
            diff[vv[i]]++;    // 路径终点+1
            diff[lcaa[i]] -= 2; // LCA处-2
        }
    }
    
    // 如果没有超过mid的路径，直接返回true
    if (!cnt_path) return true;
    
    // 关键修改8: 通过DFS序逆序累加差分值（从叶子到根）
    for (int i = n; i >= 1; i--) {
        int u = rak[i]; // 获取DFS序为i的节点
        diff[fa[u]] += diff[u]; // 向父节点累加
    }
    
    // 关键修改9: 检查是否存在满足条件的边
    for (int i = 2; i <= n; i++) { // 从2开始，根节点没有对应的边
        // 条件1: 该边被所有超过mid的路径覆盖
        // 条件2: 该边权值足够大，使得删除后最长路径<=mid
        if (diff[i] == cnt_path && val[i] >= max_len - mid)
            return true;
    }
    return false;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        adde(u, v, w);
        adde(v, u, w);
    }
    
    // 关键修改10: 执行两次DFS进行树链剖分
    dfs1(1, 0, 1);
    dfs2(1, 1);
    
    int max_len = 0; // 存储所有路径中的最大长度
    // 预处理所有路径信息
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &uu[i], &vv[i]);
        lcaa[i] = LCA(uu[i], vv[i]); // 计算LCA
        // 计算路径长度: dis[u] + dis[v] - 2*dis[lca]
        path_len[i] = dis[uu[i]] + dis[vv[i]] - 2 * dis[lcaa[i]];
        max_len = max(max_len, path_len[i]); // 更新最大路径长度
    }
    
    // 关键修改11: 二分答案框架
    int l = 0, r = max_len; // 答案范围[0, 最长路径长度]
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) r = mid; // 满足条件，尝试更小的答案
        else l = mid + 1;        // 不满足条件，需要增大答案
    }
    printf("%d\n", l);
    return 0;
}
