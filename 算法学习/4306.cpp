#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2020;
int n;

bitset<maxn> b[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s; // 不要用 scanf(" %s", string); 这是未定义行为，有极大的副作用。scanf %s 最好只用于char数组
        s = "0" + s;
        for(int j = 1; j <= n; j++)
        if(i == j) b[i][j] = 1;
        else b[i][j] = s[j] - '0';
    }   

    for(int k = 1; k <= n; k++)
    for(int i = 1; i <= n; i++)
    if(b[i][k]){
        /* 
        下面的 1 就是 b[i][k]，提取出来判断了
            for(int j = 1; j <= n; j++)
            b[i][j] = b[i][j] | (1 & b[k][j]); 
        继续优化为；
            for(int j = 1; j <= n; j++)
            b[i][j] = b[i][j] | b[k][j]; 
        于是最终优化为：
        */
       b[i] = b[i] | b[k];
    }

    int ans = 0;
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
    ans += b[i][j];

    cout << ans << endl;
    

	return 0;
}