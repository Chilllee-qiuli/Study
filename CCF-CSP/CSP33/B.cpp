#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
set<string> st;
map<string, int > mp;

string turn(string s){
    for(int i = 0; i < s.length(); i++) 
    if('A' <= s[i] && s[i] <= 'Z') s[i] += 'a' - 'A';
    return s;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        s = turn(s);
        st.insert(s);
        mp[s] = 1;
    }

    int jiao = 0;
    for(int i = 1; i <= m; i++){
        string s;
        cin >> s;
        s = turn(s);
        st.insert(s);
        if(mp[s]) {
            jiao++;
            mp[s] = 0;
        }
    }

    cout << jiao << "\n";
    cout << st.size() << '\n';


    return 0;
}