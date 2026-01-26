#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;

    while(t--){
        int n, s, x;
        cin >> n >> s >> x;
        int sum = 0;
        for(int i = 1, y; i <= n; i++){
            cin >> y;
            sum += y; 
        }
        if(sum > s) cout << "NO\n";
        else {
            if((s - sum) % x != 0) cout << "NO\n";
            else cout << "YES\n";
        }
    }


	return 0;
}