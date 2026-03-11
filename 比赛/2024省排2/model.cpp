#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;

string p, x, y;
int k;

string hex_to_bin(const string& s) {
    string res = "";
    for (char c : s) {
        if (c == '0') res += "0000";
        else if (c == '1') res += "0001";
        else if (c == '2') res += "0010";
        else if (c == '3') res += "0011";
        else if (c == '4') res += "0100";
        else if (c == '5') res += "0101";
        else if (c == '6') res += "0110";
        else if (c == '7') res += "0111";
        else if (c == '8') res += "1000";
        else if (c == '9') res += "1001";
        else if (c == 'A') res += "1010";
        else if (c == 'B') res += "1011";
        else if (c == 'C') res += "1100";
        else if (c == 'D') res += "1101";
        else if (c == 'E') res += "1110";
        else if (c == 'F') res += "1111";
    }
    return res;
}


void solve_one(){
    cin >> p >> x;
    k = p.size() - 1;
    y = hex_to_bin(x);
    for(int i = 1; i <= k; i++) y += "0";

    for(int i = 0; i + k < y.length(); i++){
        if(y[i] == '1'){
            for(int j = 0; j < p.size(); j++)
            if(p[j] == y[i + j]) y[i + j] = '0';
            else y[i + j] = '1';
        }
    }

    for(int i = y.length() - k; i < y.length(); i++)
        cout << y[i];
    
    cout << "\n";

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T--) solve_one();

	return 0;
}
