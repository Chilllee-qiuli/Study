#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int x){
    int tmp = 0;
    while(x){
        if(x & 1) tmp++;
        x >>= 1;
    }
    return tmp;
}

int main(){
    //ios::sync_with_stdio(0);
    //cin.tie(0), cout.tie(0);

    int m;
    cin >> m;
    while(m--){
        ll n, k;
        cin >> n >> k;
        k += pow(2, n - 1) - 1;
        int tmp = solve(k);
        if(tmp & 1) cout << "RED\n";
        else cout << "BLACK\n";
    }

	return 0;
}
