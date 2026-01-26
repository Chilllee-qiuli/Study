#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int t;
int n, m;
string s;
int a[maxn];
int r = 1;

int nextwhite(int x){
    for(; r <= m; r++)
    if(a[r] > x) break;

    if(a[r] > x + 1) return x + 1;
    else if(r > m) return x + 1;
    else return nextwhite(a[r]);
}

int main(){
    freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        vector<int> ans;
        cin >> n >> m;
        cin >> s;
        s = "1" + s;
        for(int i = 1; i <= m; i++) {
            cin >> a[i];
            ans.push_back(a[i]);
        }
        int l = 1;
        r = 1;
        for(int i = 1; i <= n; i++)
            if(s[i] == 'A') {
                l++;
                ans.push_back(l);
            }
            else {
                l = nextwhite(l);
                ans.push_back(l);
                l = nextwhite(l);
            }
        sort(ans.begin(), ans.end());
        auto it = unique(ans.begin(), ans.end());
        ans.erase(it, ans.end());
        cout << ans.size() << endl;
        for(int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        
        cout << endl;

    }

	return 0;
}
