#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;
int t;
string s2 = "nanjing";

int cnt(string s){
    int tmp = 0;
    for(int i = 0; i < max((int)s.size() - 6, 0); i++){
        if(s.substr(i, 7) == s2) tmp++;
    }
    return tmp;
}

int main(){
    //freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k;
        string s;
        cin >> s;
        int ans = cnt(s);
        for(int kkk = 1; kkk <= min(20, k); kkk++){
            s = s.substr(1, s.size() - 1) + s[0];
            //cout << s << endl;
            ans = max(ans, cnt(s));
        }
        cout << ans << endl;
    }

	return 0;
}