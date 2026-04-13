#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int l;
string s;
ll ans = 0;
pair<vector<int>, vector<int>> pre(string s){
    vector<int> pi(l);
    vector<int> mn(l);
    for(int i = 1; i < l; i++){
        int j = pi[i - 1];
        while(s[i] != s[j] && j) j = pi[j - 1];
        if(s[i] == s[j]) j++;
        pi[i] = j;
        if(!j) mn[i] = 0;
        else if(mn[j - 1]) mn[i] = mn[j - 1];
        else mn[i] = j;
        if(mn[i]) ans += i + 1 - mn[i];        
    }
    return make_pair(pi, mn);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> l;
    cin >> s;
    pre(s);
    cout << ans << endl;

	return 0;
}
