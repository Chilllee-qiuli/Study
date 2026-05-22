#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(false);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1, 0);
    for(int i = 1; i <= n; ++ i){
        cin >> a[i];
    }
    int k;
    cin >> k;
    vector<long long> b(n + 1, 0);
    for(int i = 1; i <= n; ++ i){
        b[i] = max(0, a[i] - a[i - 1]);
        b[i] += b[i - 1];
    }
    while(m --){
        int s, t;
        cin >> s >> t;
        long long ans = (long long) k + b[t] - b[s];
        cout << ans << endl;
    }
}