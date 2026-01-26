#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int a, b, n;

bool judge(){
    if((n % 2 + b % 2) == 1) return 0;
    if(a > b && (n % 2 + a % 2) == 1) return 0;
    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        cin >> a >> b;
        if(!judge()) cout << "NO" << endl;
        else cout << "YES" << endl;
    }

	return 0;
}
