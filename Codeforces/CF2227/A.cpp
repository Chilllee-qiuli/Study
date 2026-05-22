#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        int x, y;
        cin >> x >> y;
        int cnt = (x % 2) + (y % 2);
        if(cnt <= 1) cout << "yes\n";
        else cout << "no\n";
    }

	return 0;
}
