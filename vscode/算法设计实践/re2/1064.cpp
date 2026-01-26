#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100000 * 2 + 10;
string s, t;
int n, m;
int flag;
int cnt[maxn];

void pre(string x){
    for(int i = 1; i < x.size() ; i++){
        int j = cnt[i - 1];
        while(j > 0 && x[i] != x[j]) j = cnt[j - 1];
        if(x[i] == x[j]) j++;
        cnt[i] = j;
        if(j == m){
            flag = i - m + 1 - (m + 1);
            break;
        }
    }
}

int main(){
    freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    while(cin >> s >> t){
        memset(cnt, 0, sizeof(cnt));
    flag  = -1;
    n = s.size();
    m = t.size();

    string ts = t  + '\1' + s;

    pre(ts);

    if(flag != -1) cout << flag << endl;
    else cout << n << endl;
    }

	return 0;
}