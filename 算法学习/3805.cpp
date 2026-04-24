#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;


string trans(string str){
    string tmp;
    for(auto ch : str){
        tmp += '#';
        tmp += ch;
    }
    return tmp + "#";
}
int ans ;
void solve(string s){
    int n = s.length();
    vector<int> d(n);
    for(int i = 0, l = 0, r = -1; i < n; i++){
        int k = (i > r) ? 1 : min(d[l + r - i], r - i + 1);
        while(i - k >= 0 && i + k < n && s[i - k] == s[i + k]){k++;}
        d[i] = k--;
        if(i + k > r){
            l = i - k;
            r = i + k;
        }
        ans = max(ans, k);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> s;
    s = trans(s);
    solve(s);
    cout << ans << '\n';


	return 0;
}
