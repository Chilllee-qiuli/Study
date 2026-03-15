#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
map<char, int> mp;

int solve_one(){
    string x, y;
    cin >> x >> y;
    if(x == y) return 0;
    return mp[x[0]] == mp[y[0]] ? x[1] - y[1] : mp[x[0]] - mp[y[0]];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    mp['O'] = 1;
    mp['B'] = 2;
    mp['A'] = 3;
    mp['F'] = 4;
    mp['G'] = 5;
    mp['K'] = 6;
    mp['M'] = 7;

    cin >> T;
    while(T--) {
        int pd = solve_one();
        if(pd == 0) cout << "same\n";
        else if(pd < 0) cout << "hotter\n";
        else cout << "cooler\n";
    }

	return 0;
}
