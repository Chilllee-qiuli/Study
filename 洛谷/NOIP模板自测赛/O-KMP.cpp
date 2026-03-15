#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


vector<int> prefix(string _s){
    int n = _s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++){
        int j = pi[i - 1];
        while (j > 0 && _s[i] != _s[j]) j = pi[j - 1];
        if (_s[i] == _s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

// 在 text 里找 pattern 出现的位置。
vector<int> _find(string text, string pattern){
    string cur = pattern + '#' + text;
    int szp = pattern.size(); // size pattern
    vector<int> _tmp;
    vector<int> lps = prefix(cur);
    for (int i = szp + 1; i < cur.size(); i++)
        if (lps[i] == szp) _tmp.push_back(i - 2 * szp);
    return _tmp;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    string text, pattern;
    cin >> text >> pattern;
    vector<int> ans = _find(text, pattern);
    for(auto v : ans) cout << v + 1 << endl;
    vector<int> lps = prefix(pattern);
    for(int i = 0; i < pattern.size(); i++)
    cout << lps[i] << " ";
    cout << "\n";

    return 0;
}
