#include<bits/stdc++.h>
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
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    string s;
    cin >> s;
    vector<int> pi = prefix(s);
    int t = pi[s.length() - 1];
    cout << s.length() << " " << t << "\n";
    if(t * 2 >= s.length()) cout << t << endl;
    else cout << s.length() - t << endl;


	return 0;
}
