#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
ll sum[maxn];
int n, k;

void add(int p, ll x){
    for(int i = p; i <= maxn; i+= i & (-i))
        sum[i] += x;
}

ll qry(int p){
    ll res = 0 ;
    for(int i = p; i; i -= i & (-i)) res += sum[i];
    return res;
}

int main(){
    //freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        add(i, x);
    }

    while(k--){
        char ch;
        cin >> ch;
        int x, y;
        cin >> x >> y;
        if(ch == 'U') add(x, y);
        if(ch == 'Q') {
            cout << qry(y) - qry(x - 1) << endl;
        }
    }


	return 0;
}