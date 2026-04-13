#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int l;
string s;
vector<int> pre(string s){
    vector<int> pi(l);
    for(int i = 1; i < l; i++){
        int j = pi[i - 1];
        while(s[i] != s[j] && j) j = pi[j - 1];
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}
int solve(){

    vector<int> pi = pre(s);
    
    return l - pi[l - 1];
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> l;
    cin >> s;

    cout << solve() << "\n";

	return 0;
}
