#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;

void solve_one();
string work(string str);
string s;
vector<char> vc;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> T;
    while(T--) solve_one();

	return 0;
}

string work(string str){
    string ans;
    int r = str.size() / 2 - 1;
    while(r >= 0 && str[r] == 0) r--;
}

void solve_one(){
    cin >> s;
    int n = s.size();
    if(n & 1){
        for(int i = 1; i < n; i++) cout << 9;
        cout << endl;
        return ;
    }
    vector<int> fl;
    vector<char>().swap(vc);
    for(int i = 0; i < s.size(); i++){
        char ch = s[i];
        if(vc.empty()) {
            vc.push_back(ch);
            fl.push_back(i);
        }
        else if(vc.back() == ch) vc.pop_back();
        else vc.push_back(ch);
    }
    int flag0 = 1;

    if(vc.size() == 0) cout << s << endl;
    else {
        int len = n - fl.back();
        string tmp = "1";
        for(int i = 2; i <= len; i++) tmp += "0";
        string bk = s.substr(fl.back(), len);
        if(bk != tmp){
            int l = len / 2;
            
        }
    }

}   