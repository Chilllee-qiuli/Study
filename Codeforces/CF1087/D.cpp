#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


string solve(int r, int g, int b);
string solve_eq(int r, int g, int b);
string solve_rgrg(int r, int g, int b);

char R, G, B;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int r, g, b;
        cin >> r >> g >> b;
        vector< pair<int, char> > vc ;
        vc.push_back({r, 'R'});
        vc.push_back({g, 'G'});
        vc.push_back({b, 'B'});
        sort(vc.rbegin(), vc.rend());
        r = vc[0].first; R = vc[0].second;
        g = vc[1].first; G = vc[1].second;
        b = vc[2].first; B = vc[2].second;
        string ans = solve(r, g, b);
    }

	return 0;
}

string solve(int r, int g, int b){ // r >= g >= b
    string tmp;
    
    if(b * 2 <= r){
        r -= b * 2;
        g -= b;
        b = 0;
        tmp += solve_rgrg(b * 2 , b, b);
        tmp += solve_rgrg(r, g, 0);
        return tmp;
    }
    else {
        int delta = g - b;
        r -= delta;
        g = b;
        tmp += solve_rgrg(delta, delta, 0);
        tmp += solve_eq(b, b, b); r -= b;
        if(r) tmp += R;
        return tmp;
    }
} 

string solve_eq(int r, int g, int b){
    // 注意末尾必须是 BRG
    string t[3]; t[0] += R + G + B; t[1] += G + B + R; t[2] += B + R + G;




}

string solve_rgrg(int r, int g, int b){
    string tmp;
    if(r == 0) return "";
    if(b)
    for(int i = 1; i <= b; i++) {
        tmp += R;
        tmp += G;
        tmp += R;
        tmp += B;
    }
    else 
    for(int i = i; i <= g; i++){
        tmp += R;
        tmp += G;
    }
    return tmp;
    
}