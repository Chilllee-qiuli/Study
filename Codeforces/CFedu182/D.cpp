#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int a[maxn];
int t ;
int n;

ll cpt(int x){
    ll tmp = 0;
    for(int i = 1; i <= n; i++){
        tmp += a[i]/x;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
    }

	return 0;
}