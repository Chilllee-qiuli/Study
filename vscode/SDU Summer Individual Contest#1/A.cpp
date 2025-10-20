#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int n;

struct node{
    string str;
    ll s, h;
    ll sum;
}s[maxn];

bool cmp(node x, node y){
    ll tmpx = x.s * y.h, tmpy = y.s * x.h;
    return tmpx == tmpy ? x.h < y.h : tmpx > tmpy;
    //return tmpx > tmpy;
}

int main(){
    //freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        string str;
        cin >> str;
        s[i].str = str;
        s[i].s = s[i].h = s[i].sum = 0;
        for(int j = 0; j < str.size(); j++)
        {
            if(str[j] == 's') s[i].s++;
            else 
            {
                s[i].h++;
                s[i].sum += s[i].s;
            }
        }
    }

    sort(s + 1, s + 1 + n, cmp);

    ll cnts = 0, cnth = 0;
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        //cout << s[i].str << " ";
        ans += s[i].sum;
        ans += cnts * s[i].h;
        cnts += s[i].s;
        cnth += s[i].h;
    }
    //cout << endl;

    cout << ans << endl;


	return 0;
}
