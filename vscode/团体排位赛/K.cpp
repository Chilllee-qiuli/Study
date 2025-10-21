#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
   //freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int r, c, k;
    cin >> r >> c  >> k;

    int flag = 1;
    for(int i = 1; i <= r; i++){
        string  m, p;
        cin >> m >> p;
        int need = 0;
        for(auto ch : p){
            if(ch == '*') need = 1;
        }
        for(auto ch : m)
            if(ch == '-' && need) flag = 0;
    }
    if(flag) cout << "Y" << endl;
    else cout << "N" << endl;



    return 0;
}