#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
string s;
int flag[maxn];
int bck[maxn];
char st[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> s;
    s = "1" + s;
    
    int top = 0;
    for(int i = s.size() - 1;  i >= 1; i--){
        while(top > 0 && s[i] <= st[top]){
            top--;
        }
        st[++top] = s[i];
        if(top == 1) flag[i] = 1;
    }

    string stck = "";
    string ans = "";
    for(int i = 1; i <= s.size() - 1; i++){
        if(flag[i]) ans += s[i];
        else stck += s[i];
    }
    reverse(stck.begin(), stck.end());

    cout << ans + stck << endl;

	return 0;
}
