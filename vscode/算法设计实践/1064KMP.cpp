#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
string s, t;
int pi[maxn];

int main(){
    //freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while(cin >> s >> t){
        memset(pi, 0, sizeof(pi));
        for(int i = 1; i < t.size(); i++){
            int j = pi[i - 1];
            while(j > 0 && t[i] != t[j]) j = pi[j - 1];
            if(t[i] == t[j]) j++;
            pi[i] = j;
        }
        int ans = -1;
        for(int i = 0, j = 0; i < s.size(); i++){
            
            while(j > 0 && s[i] != t[j]) j = pi[j - 1];
            if(s[i] == t[j]) j++;
            if(j == t.size()){
                //cout << "oi= " << i << endl;
                ans = i - t.size() + 1;
                break;
            }
        }
        if(ans != -1) cout << ans << endl;
        else cout << s.size() << endl;
    }

	return 0;
}