#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int n;
map<char, int> mp;

int main(){
    //freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        string str;
        mp.clear();
        char ch;
        for(int i = 1; i <= n; i++){
            cin >> ch;
            mp[ch]++;
        }
        cout << n - mp[ch] << endl;
    }


	return 0;
}