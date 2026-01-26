#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("1.in", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> graph(n + 1);
        vector<int> deg(n + 1, 0);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }
      
        bool isPath = true;
        for (int i = 1; i <= n; i++) {
            if (deg[i] > 2) {
                isPath = 0;
                break;
            }
        }
        if (isPath) {
            cout << -1 << endl;
            continue;
        }
      
        int b = -1;
        for (int i = 1; i <= n; i++) {
            if (deg[i] > 2) {
                b = i;
                break;
            }
        }
      
        int c = -1;
        for (int nei : graph[b]) {
            if (c == -1 || deg[nei] < deg[c]) {
                c = nei;
            }
        }
      
        int a = -1;
        for (int nei : graph[b]) {
            if (nei != c) {
                a = nei;
                break;
            }
        }
      
        cout << a << " " << b << " " << c << endl;
    }
    return 0;
}
