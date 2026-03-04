#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 11;
int a[maxn];
int t;


void solve_one(){
    int n;
    cin >> n;
    int flag = 0;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 2; i <= n; i++){
        if(a[i] < a[i - 1]) flag = 1;
    }
    if(flag) cout << 1 << endl;
    else cout << n << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--) solve_one();

	return 0;
}
