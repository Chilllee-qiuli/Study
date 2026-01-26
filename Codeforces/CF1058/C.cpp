#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int f(int x){
    int ans = 0;
    while(x){
        ans <<= 1;
        ans += (x & 1);
        x /= 2;
        
    }
    return ans;
}

void solve(int x){
    vector<int> ans(33);

    int i = 0;

    while(x){
        ans[i++] = x & 1;
        x /= 2;
    }
    reverse(ans.begin(), ans.end());
    for(auto v : ans) cout << v;
    //cout << "\n";
}

void test(int x){
    for(int i = 0; i <= x * 1000; i++){
        int tmp = i ^ f(i);
        if(tmp == x){
            cout << x << " ";
            cout << i << " ";
            solve(x);
            cout << endl;
            return;
        }
    }
    cout << "NO" << " ";
    solve(x);
    cout << endl;
}

int main(){
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        test(n);
    }

	return 0;
}
