#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    ll x;
    cin >> x;
    vector<int> vc;
    while(x){
        if(x & 1) vc.push_back(1);
        else vc.push_back(0);
        x /= 2;
    }
    reverse(vc.begin(), vc.end());

    for(auto it : vc) cout << it ;
    cout << "\n";


	return 0;
}
