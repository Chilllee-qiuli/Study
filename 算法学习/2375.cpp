#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int maxl = 1e6 + 10;
int pi[maxl];
int tmp[maxl]; // 定义为当前前缀的公共真前后缀对数

void pre(string s){
    
    for(int i = 1; i < s.length(); i++){
        int j = pi[i - 1];
        while(j && s[i] != s[j]) j = pi[j - 1];
        if(s[i] == s[j]) j++;
        pi[i] = j;
        tmp[i] = (j ? tmp[j - 1] + 1 : 0); // 无匹配则为0，有匹配则在基础上 + 1.
    }
}
ll ans = 1;
void gettmp(string s){
    for(int i = 1, j = 0; i < s.length(); i++){
        while(j && s[i] != s[j]) j = pi[j - 1];
        if(s[i] == s[j]) j++;
        while(i + 1 < j * 2) j = pi[j - 1];
        // j是计算出来的当前前缀的最长不重叠 border 长度
        // 于是当前的最长不重叠border个数就是 j 的... 个数 + j本身
        ans = ans * ( (j ? tmp[j - 1] + 1 : 0) + 1 )% mod;
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){

        string s;
        cin >> s;
        pre(s);
        ans = 1;
        gettmp(s);
        cout << ans << endl;
        
    }



	return 0;
}