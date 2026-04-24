#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e6 + 10;

unordered_map<int, int> mp;

vector<int> manacher(string s){
    int n = s.length();
    vector<int> d(n);
    vector<int> ans;
    for(int i = 0, l = 0, r = -1; i < n; i++){
        int k = (i > r) ? 1 : min(d[l + r - i], r - i + 1);
        while(i - k >= 0 && i + k <= n && s[i - k] == s[i + k])   k++;
        d[i] = k--;
        if(i + k == n - 1) {
            mp[i] = 1;
            ans.push_back(i + 1);
        }
        if(i + k > r){
            l = i - k;
            r = i + k;
        }
        //cout << s[i] << " " << d[i] << endl;
    }
    // for(auto it : ans) cout << it << " " ;
    // cout << endl;


    for(int i = n - 1; i >= 0; i--){
        int k = d[i] - 1;
        if(i - k == 0 && mp[i + k]){
            mp[i] = 1;
            ans.push_back(i + 1);
        }
    }
    return ans;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;

    cin >> t;
    while(t--){
        string s;
        cin >> s;
        mp.clear();
        vector<int> ans = manacher(s);
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        for(auto it : ans) cout << it << " " ;
        cout << "\n";
    }
    


	return 0;
}
