#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(ll x){
    if(!x) return ;
    solve(x / 2);
    if(x & 1) cout << 1;
    else cout << 0 ;
}

void turn(string s){
    
    ll tmp = 0, tmp1 = 0, tmp0 = 0;
    for(auto ch : s){
        tmp <<= 1;
        if(ch == '1') tmp++;
        if(ch == '1') tmp1++;
        else tmp0++;
    }
    cout << tmp << "\n";
    //cout << tmp1 << " " << tmp0 << "\n"; 
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    //turn("111001100101101001000001111011011000111011010001010");
    //turn("11111111111111111111111110000000000000000000000000");
    turn("1000000000000000000000000001111111111111111111111111");
    // for(int i = 1; i <= 25; i++) cout << 1;
    // for(int i = 1; i <= 25; i++) cout << 0 ;
    // cout << "\n";

    // cout << 1;
    // for(int i = 1; i <= 26; i++) cout << 0 ;
    // for(int i = 1; i <= 25; i++) cout << 1 ;
    // cout << endl;
    
    

	return 0;
}
