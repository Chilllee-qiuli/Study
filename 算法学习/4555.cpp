#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxl = 1e5 + 10;
int vis[maxl * 3];
string s;


string trans(string str){
    string tmp= "!";
    for(auto ch : str){
        tmp += '#';
        tmp += ch;
    }
    return tmp + "#@";
}
int ans ;
int L[maxl * 3], R[maxl * 3];

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
        L[i - k] = max(L[i - k], k);
        R[i + k] = max(R[i + k], k);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> s;
    s = trans(s);
    solve(s);
    int n = s.length();
    // L: 左端点往右传播
    for(int i = 1; i < n; i++)
        L[i] = max(L[i], L[i - 2] - 2);
    

    // R: 右端点往左传播
    for(int i = n; i >= 0; i--)
        R[i] = max(R[i], R[i + 2] - 2);
    

    for(int i = 2; i <= n - 2; i ++)
        ans = max(ans, L[i] + R[i]);
    

    cout << ans << endl;


	return 0;
}
