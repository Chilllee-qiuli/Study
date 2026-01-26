#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int t;
int n;
ll k;
ll q[maxn], r[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 1; i <= n; i++) cin >> q[i];
        
        for(int i = 1; i <= n; i++) cin >> r[i];

        sort(q + 1, q + 1 + n);
        sort(r + 1, r + 1 + n);

        int a = 1, b = n;
        int ans = 0;
        while(b >= 1 && r[b] >= k) b--;
        
        vector<ll > mr;
        for(int i = n; i; i--){
            if(q[i] > k) continue;
            mr.push_back((k - q[i]) / (q[i] + 1));
        }
        int j = 1;
        for(auto it : mr){
            if(j > b) break;
            if(it >= r[j]){
                j++; ans++;
            }
        }
        cout << ans << endl;

    }

	return 0;
}