#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string str;
string in;

char stk[5050000];
int top;
vector<ll> ans;

int main(){
    freopen("b.in", "r", stdin);
    //freopen("b.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    string s;
    while(cin >> s){
        str += s;
    }
    str += "@@@@@@@@@@@@@@@@";
    // cout << str << endl;

    ll fl = 0;
    while(str[fl] != '@'){
        string tmp = "";
        for(;fl < str.size() - 7; fl++){
            tmp += str[fl];
            if(str[fl] == '@') break;
            if(str[fl] == '>') break;
        }
         //cout << tmp << endl;

        if(tmp == "<table>") in += "{";
        if(tmp == "</table>") in += "}";
        if(tmp == "<td>") in += "(";
        if(tmp == "</td>") in += ")";
        //if(tmp == "<tr>") in += "[";
        //if(tmp == "</tr>") in += "]";

        
        fl++;
        
        
        tmp = "";
    }
    //cout << in << endl;
    //in = "{(())}";

    ll cnt = 0;
    for(ll i = 0; i < in.size(); i++)
        if(in[i] == '}'){
            ans.push_back(cnt);
            cnt = 0;
            --top;
        }
        
        else if(in[i] == ')') {
            --top;
             ++cnt;
        }
        else stk[++top] = in[i];
        
    //cout <<"top: " << top << endl;
    
    if(ans.empty()) {
        cout << 0 << endl;
        return 0;
    }
    sort(ans.begin(), ans.end());
    for(auto it : ans) cout << it << " " ;

   

	return 0;
}
