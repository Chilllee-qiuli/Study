#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
string a, b;
int n;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int  t;
    cin >> t;
    while(t--){
        cin >> n;
        cin >> a;
        cin >> b;
        int bal1 = 0, bal2 = 0;
        int flag = 1;
        for(int i = 0; i < n; i++){
            if(a[i] == b[i]){
                if(a[i] == '(') bal1 ++, bal2 ++;
                else bal1 --, bal2 --;
            }
            else {
                if(bal1 > bal2) bal1--, bal2++;
                else bal1++, bal2--;
            }
            if(bal1 < 0 || bal2 < 0) flag = 0;
        }
        if(flag && bal1 + bal2 == 0) cout << "YES\n";
        else cout << "NO\n";
        
    }

	return 0;
}
