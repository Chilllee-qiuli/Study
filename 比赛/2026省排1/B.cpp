#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int pre[maxn];


int work(string str){
    int x = 0;
    //reverse(str.begin(), str.end());
    for(auto ch : str){
        if(ch == '1') x = x << 1 | 1;
        else x <<= 1;
    }
    
    return x;
}
string s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while(T--) {
        cin >> s;
        int n = s.length();
        
        s = "#" + s;
        for(int i = 1, cnt = 0; i <= n; i++){
            pre[i] = cnt;
            if(s[i] == '0') cnt++;
            else cnt = 0;
        }

        int ans = 0 ;
        for(int len = 1; len <= min(19, n); len++){
            for(int i = 1; i + len - 1 <= n; i++){
                if(s[i] != '1') continue;
                int x = 0, r = i + len - 1;
                x = work(s.substr(i, len));
                x -= len;
                if(x >= 0 && x <= pre[i]) {
                    ans++;
                    //cout << "test x = " <<  x + len << endl;
                    //for(int l = i; l <= i + len - 1; l++) cout << s[l];
                    //cout << " x= " << x << " len = " << len << endl;
                }
            }
        }

        cout << ans << endl;
        
    }


    return 0;
}