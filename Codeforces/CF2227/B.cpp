#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        string s;
        int n;
        cin >> n;
        cin >> s;
        int cnt = 0;
        for(auto ch : s){
            if(ch == '(') cnt++;
        }
        if(cnt * 2 == s.length()) cout << "yes\n";
        else cout << "no\n";
    }

	return 0;
}
