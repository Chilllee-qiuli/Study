#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;

bool work(int a, int b, int c){
    while(a || b || c){
        if((a & 1) + (b & 1) + (c & 1) == 2) return 0;
        a /= 2;
        b /= 2;
        c /= 2;
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        if(work(a, b, c)) cout << "yes" << endl;
        else cout << "no" << endl;
    }

	return 0;
}
