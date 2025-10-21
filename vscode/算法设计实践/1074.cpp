#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

map<int, int> mp;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        mp[x]++;
    }
    for(auto x : mp)
        if(x.second == 1){
            cout << x.first << endl;
            return 0;
        }

	return 0;
}