#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;

int cpt(int x){
    int ans = 0;
    while((x & 1) == 0){
        ans++;
        x >>= 1;
    }
    return ans;
}

bool solve(int x){
    if(x == 0) return 1;
    string s;int m = cpt(x);
    while(x){
        s.push_back((x & 1) + '0');
        x >>= 1;
    }
    
    for(int i = 0; i <= m; i++){
        string s2 = string(s.rbegin(), s.rend());
        if(s == s2){
            int len = (int)s.size();
            bool testtt = (len % 2 == 0) || (s[len/2] == '0');
            if(testtt) return 1;

        }

        s.push_back('0');
    }
    

    return 0;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(solve(n)) cout << "YES\n";
        else cout << "NO\n";
    }

	return 0;
}
