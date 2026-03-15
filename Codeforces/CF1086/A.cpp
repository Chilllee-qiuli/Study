#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
map<int, int> mp;

int solve(){
    mp.clear();
    for(int i = 1; i <= n * n; i++){
        int x;
        cin >> x;
        mp[x]++;
    }
    
    if(n == 1) return 0;
    for(auto it : mp){
        if(it.second > n * n - n) return 0;
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        cin >> n;
        if(solve()) cout << "YES\n";
        else cout << "NO" << endl;

    }

	return 0;
}