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
ll ans ;


void solve(string t){
    int n = t.length();
    vector<int> d(n);
    for(int i = 0, l = 0, r = -1; i < n; i++){
        int k = (i > r) ? 1 : min(d[l + r - i], r - i + 1);
        while(i - k >= 0 && i + k < n && t[i - k] == t[i + k]){k++;}
        d[i] = k--;
        if(i + k > r){
            l = i - k;
            r = i + k;
        }
         //cout << s[i] << " " << k << "\n";
        if(i % 2 == 0) ans += k / 2;
        
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    cin >> s;
    // 构造新串：奇数位取反
    string t = s;
    for (int i = 0; i < n; i++) {
        if (i & 1) {
            t[i] = (t[i] == '0' ? '1' : '0');
        }
    }
    t = trans(t);
    solve(t);
    cout << ans << '\n';


	return 0;
}
