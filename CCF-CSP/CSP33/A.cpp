#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 110;
int n, m;

vector<int> cnt[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= m; i++) cnt[i].push_back(0);
    for(int i = 1; i <= n; i++){
        int len;
        cin >> len;
        while(len--){
            int word;
            cin >> word;
            cnt[word].push_back(i);
        }
    }

    for(int i = 1; i <= m; i++){
        int ans = 0;
        for(int j = 1; j < cnt[i].size(); j++) if(cnt[i][j] != cnt[i][j - 1]) ans++;
        cout << ans << " " << cnt[i].size() - 1 << "\n";
    }

    return 0;
}