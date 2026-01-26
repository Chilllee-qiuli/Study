#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int t;
int a, b, n;


int main(){
    freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> a >> b >> n;
        if(a/n - b >= 0 || b >= a) cout << 1 << endl;
        else cout << n - a/b + 1 << endl;
    }

	return 0;
}
