#include <bits/stdc++.h>
using ll = long long;
const int N=1e5+9;
using namespace std;
ll a;
string f(int n,bool flag,string s){
    if(flag){
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                return s.substr(0,i-1)+"1"+s.substr(i,n-i+1);
            }
        }
        return s+"1";
    }
    else{
        for(int i =0;i<n;i++){
            if(s[i]-'1'>0){
                return "-"+s.substr(0,i-1)+"1"+s.substr(i,n-1+1);
            }
        }
        return "-"+s+"1";
    }
}
int main(){
    freopen("1.in", "r", stdin);
    int _;cin>>_;
    while(_--) {
        cin >> a;
        bool flag;
        if (a == 0) {
            cout << 10 << endl;
            continue;
        }
        if (a > 0) {
            flag = true;
        } else if (a < 0) {
            flag = false;
        }
        string s = to_string(abs(a));
        int n = s.size();
        cout << f(n, flag, s)<<endl;
    }
    return 0;
}