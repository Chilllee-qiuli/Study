#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxl = 5e5 + 10;

int pi[maxl];
int f[maxl]; // 某前缀能盖出来的最小印章长度
int vis[maxl]; // 以某个值为章能覆盖的最右端点

void Pre(string s){
    int l = s.length();
    f[0] = 1;
    vis[1] = 0;
    for(int i = 1; i < l; i++){
        int j = pi[i - 1];
        while(j && s[i] != s[j]) j = pi[j - 1];
        if(s[i] == s[j]) j++;
        pi[i] = j;

        if(j && vis[f[j - 1]] + j >= i)  f[i] = f[j - 1];
        else f[i] = i + 1; // 没有能盖的章只能把整个串盖了
        
        vis[f[i]] = i;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    string s;
    cin >> s;
    Pre(s);

    cout << f[s.length() - 1] << "\n";

	return 0;
}
