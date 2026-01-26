#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int n, k;

bool judge(string s1){
    string s2 = s1;
    reverse(s2.begin(), s2.end());
    return s1 < s2;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k;
        string s;
        cin >> s;
        string tmps = s;
        char minn = 'z' + 1, maxx = 0;
        for(char ch : s){
            minn = min(minn, ch);
            maxx = max(maxx, ch);
            }
        if(k == 0) cout << (judge(s) ? "YES" : "No") << endl;
        else if(minn == maxx) cout << "No" << endl;
        else cout << "Yes" << endl;
        
    }



	return 0;
}    