#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
string s;

int wk(){
    int n = s.length();
    if(s[0] == s[n - 1]) return 0;
    for(int i = 1; i < n; i++){
        if(s[i] == s[i - 1]) return i;
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> s;
        cout << wk() << "\n";
    }


	return 0;
}
