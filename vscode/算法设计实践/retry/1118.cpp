#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e4 + 10;
string stra, strb;
ll ans[maxn * 2];

int main(){
   // freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> stra >> strb;

    reverse(stra.begin(), stra.end());
    reverse(strb.begin(), strb.end());  
    int lena = stra.length();
    int lenb = strb.length();

    for(int j = 0; j < lenb; j++)
    for(int i = 0; i < lena; i++){
        int x = stra[i] - '0', y = strb[j] - '0';
        ans[j + i] += x * y;
    }

    int len = lena * lenb;
    int flag = maxn * 2 - 1;
    
    for(int i = 0; i <= maxn * 2 - 1; i++){
        ans[i + 1] += ans[i] / 10;
        ans[i] %= 10; 
    }

    while(flag > 0 && ans[flag] == 0) flag--;

    for(int i = flag; i >= 0; i--) 
        cout << ans[i];
    cout << endl;
    


	return 0;
}