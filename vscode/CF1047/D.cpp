#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> b(n);
        vector<vector<int>> indices(n + 1);
        

        for (int i = 0; i < n; i++) {
            cin >> b[i];
            if (b[i] <= n) {
                indices[b[i]].push_back(i);
            }
        }
        

        bool possible = true;
        for (int k = 1; k <= n; k++) {
            if (!indices[k].empty() && indices[k].size() % k != 0) {
                possible = false;
                break;
            }
        }
        
        if (!possible) {
            cout << "-1\n";
            continue;
        }
        

        vector<int> a(n);
        int next_value = 1;
        
        for (int k = 1; k <= n; k++) {
            if (indices[k].empty()) continue;
            
            int group_count = indices[k].size() / k;
            
            for (int g = 0; g < group_count; g++) {
                int current_value = next_value + g;
                
                for (int i = 0; i < k; i++) {
                    int idx = indices[k][g * k + i];
                    a[idx] = current_value;
                }
            }
            
            next_value += group_count;
        }
        
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
