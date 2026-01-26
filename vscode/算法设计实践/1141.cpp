#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n & 1)  cout << "No" << endl;
        else cout << "Yes" << endl;
    }


	return 0;
}