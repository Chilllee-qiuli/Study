#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;

string trans(string s){
    string tmp;
    for(auto ch : s){
        tmp += '#';
        tmp += ch;
    }
    return tmp + "#";
}

int d[maxn];
int ans;
void manacher(string s){
    int n = s.length();
    for(int i = 1, l = 0, r = -1; i < n - 1; i++){
        int k = (i > r) ? 1 : min(d[l + r - i], r - i + 1);
        // cout << k << endl;
        while(i - k >= 0 && i + k <= n && s[i - k] == s[i + k]) {
            if(s[i] == '#' && i >= k / 2 && k % 4 == 0 && d[i - k / 2] - 1 >= k / 2) ans = max(ans, k);
            k++;
        }
        d[i] = k--;
        if(i + k > r){
            l = i - k;
            r = i + k;
        }
        // cout << s[i] << " " << d[i] << endl;
        if(i % 2 == 0 && k % 4 == 0 && d[i - k / 2] - 1 == k / 2) ans = max(ans, k);
        
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    string s;
    cin >> n >> s;
    s = trans(s);
    manacher(s);

    cout << ans << endl;

	return 0;
}