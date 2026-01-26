#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


vector<int> prefix_function(string s) {
    int n = s.length();
    vector<int> ans(n, 0);
    for(int i = 1; i < n; i++){
        int j = ans[i - 1];
        while(j > 0 && s[i] != s[j]) j = ans[j - 1];
        if(s[i] == s[j]) j++;
        ans[i] = j;
    }
    return ans;
}

vector<int> kmp(string text, string pattern){
    string tmp = pattern + "#" + text;
    vector<int> ans ;
    vector<int> f = prefix_function(tmp);
    for(int i = 0; i < f.size(); i++){
        if(f[i] == pattern.size()) ans.push_back(i - 2 * pattern.size());
    } 
    return ans;
}


int main(){
    freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    string text, pattern;
    while( cin >> text >> pattern){
        vector<int> ans = kmp(text, pattern);
        if(ans.size()) cout << ans[0] << endl;
        else cout << text.size() << endl;
    }
	return 0;
}