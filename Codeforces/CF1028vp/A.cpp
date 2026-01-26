#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int a, b, c, d;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> a >> b >> c >> d;
        int e = min(a, c), f = min(b, d);
        if(e >= f){
            cout << "Gellyfish" << endl;
        }
        else cout << "Flower" << endl;
    }


	return 0;
}
