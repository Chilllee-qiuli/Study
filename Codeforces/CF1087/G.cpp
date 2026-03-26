#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;
int g[maxn]; // pi是最长border，g是最短border

vector<int> prefix(string _s){
    int n = _s.length();
    vector<int> pi(n);
    for(int i = 1; i < n; i++){
        int j = pi[i - 1];
        while(j > 0 && _s[i] != _s[j]) j = pi[j - 1];
        if(_s[j] == _s[j]) j++;
        pi[i] = j;
        if (pi[i] == 0) g[i] = 0;
        else if (g[pi[i] - 1] == 0) g[i] = pi[i];
        else g[i] = g[pi[i] - 1];
    }

    return pi;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while(T--){
        int n, q;
        string s;
        vector<int> pi = prefix(s);
        cin >> n >> q;
        cin >> s;

        while(q--){
            int l, r;
            cin >> l >> r;
            
        }

    }

	return 0;
}
