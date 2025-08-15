#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int t;
int n;
int a[maxn], b[maxn], c[maxn];

bool judge(){
    if(a[n] != b[n]) return 0;
    for(int i = n - 1; i; i--){
        if(a[i] == b[i]) continue;
        if((a[i] ^ a[i + 1]) == b[i]) continue;
        if((a[i] ^ b[i + 1]) == b[i]) continue;
        return 0;
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++) cin >> b[i];

        if(judge()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

	return 0;
}
