#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
    int x;
    cin >> x;
    vector<int> ans(33);

    int i = 0;

    while(x){
        ans[i++] = x & 1;
        x /= 2;
    }
    reverse(ans.begin(), ans.end());
    for(auto v : ans) cout << v;
    cout << "\n";
}

	return 0;
}
