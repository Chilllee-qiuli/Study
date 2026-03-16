#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int work(string str){
    int x = 0;
    //reverse(str.begin(), str.end());
    for(auto ch : str){
        if(ch == '1') x = x << 1 | 1;
        else x <<= 1;
    }
    
    return x;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    string s;
    cin >> s;
    cout << work(s) << endl;


    return 0;
}