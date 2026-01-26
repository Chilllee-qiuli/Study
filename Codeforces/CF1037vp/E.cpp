#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int t;
ll n, p[maxn], s[maxn], a[maxn];


bool work(){
    
    for(int i = 1; i < n; i++) 
        if(p[i] % p[i+1] != 0 || p[i] < p[i + 1]) return 0;
    for(int i = n-1; i; i--) 
        if(s[i+1] % s[i] != 0 || s[i+1] < s[i]) return 0;

    if(p[n] != s[1]) return 0;

    ll g = p[n];

    for(int i = 1; i <= n; i++) a[i] = p[i] * s[i] / gcd(p[i] , s[i]);
    if(a[1] != p[1] || a[n] != a[n]) return 0;

    for(int i = 2; i <= n; i++)
        if(gcd(a[i], p[i-1]) != p[i]) return 0;
    
    for(int i = n - 1; i; i--)
        if(gcd(a[i], s[i + 1]) != s[i]) return 0;

    return 1;
}


int main(){
    freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> p[i];
        for(int i = 1; i <= n; i++) cin >> s[i];
        if(work()) cout << "YES" << endl;
        else cout << "NO" <<endl;
    }


	return 0;
}
