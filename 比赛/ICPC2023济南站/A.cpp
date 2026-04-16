#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pr pair<char, char>
#define mk make_pair
int t;
const int maxn = 1e5 + 10;
string s;
pr stk[maxn];
int tp;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> s;
        tp = 0;
        int flag = 1;
        char cur = '#';
        for(auto ch : s){
            if(ch == ')') ch = '(';
            if(ch == ']') ch = '[';

            if(tp == 0 || stk[tp].first != ch)  {
                stk[++tp] = mk(ch, cur);
                cur = '#';
            }
            else {
                if(stk[tp].second == ch) {
                    flag = 0;
                    break;
                }
                tp--;
                cur = ch;
            }
        }

        tp = 0;
        // cur = '#';
        int f1 = 0, f2 = 0;
        for(auto ch : s){
            if(ch == ')') ch = '(';
            if(ch == ']') ch = '[';

            if(tp == 0 || stk[tp].first != ch)  {
                stk[++tp] = mk(ch, cur);
            }
            else{
                tp--;
                if(tp == 0){
                    if(ch == '('){
                        if(f1) {
                            flag = 0;
                            break;
                        }
                        f1 = 1;
                    }
                    else {
                        if(f2){
                            flag = 0;
                            break;
                        }
                        f2 = 1;
                    }
                }
            }
        }

        

        if(flag) cout << "Yes\n";
        else cout << "No\n";
    }

	return 0;
}
