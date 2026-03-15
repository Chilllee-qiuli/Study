#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll s, m;


vector<int> wk(ll x){
    vector<int> vc;
    while(x){
        if(x & 1) vc.push_back(1);
        else vc.push_back(0);
        x /= 2;
    }
    return vc;
}

ll solve_one(){
    cin >> s >> m;
    m %= s;
    if(m == 0) return 1; 
    vector<int> vcs = wk(s), vcm = wk(m);
    int flag = 0;
    for(int i = 0; i < min(vcs.size(), vcm.size()); i++){
        if(vcm[i]) {flag = 1; break;}
        if(vcs[i] && !vcm[i]) return -1;
    }
    ll tmp = s / m;
    if(s % m != 0) tmp++;
    return tmp;

    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int T;
    cin >> T;
    while(T--) cout << solve_one() << "\n";



	return 0;
}
