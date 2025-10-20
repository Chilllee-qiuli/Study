#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    //ios::sync_with_stdio(0);
    //cin.tie(0), cout.tie(0);

    for(ll i = 1; i <= 2; i++){
        printf("buy: %lld, cost: %lld\n", pow(3ll, 1ll * i), pow(3ll, i + 1) + pow(3ll, i - 1)*i);
    }
    cout << "test: " << endl;
    cout << pow(3ll, 2ll);

	return 0;
}
