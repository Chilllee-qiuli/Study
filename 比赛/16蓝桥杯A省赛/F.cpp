#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;
vector<ll> vc;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> s;
    s = 'a' + s;
    ll len = 0;
    for(int i = 1; i < s.length(); i++){
        if(s[i] == s[i - 1] + 1 || s[i] == s[i - 1]) len ++;
        else {
            vc.push_back(len);
            len = 1;
        }
    }
    vc.push_back(len);
    ll ans = 0;

    for(int i = 1; i < vc.size(); i++){
        ll len = vc[i];
        ans += (len + 1) * len / 2;
        ans += len * vc[i - 1];
    }

    cout << ans << endl;

	return 0;
}
