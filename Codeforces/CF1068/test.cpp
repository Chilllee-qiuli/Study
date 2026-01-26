#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int t;
int k;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

        int x = pow(2, 30);
        //cout << "x=" << x << endl;
        int flag = 0;
        for(int i = 30; i >= 0; i--){
            if(n & x) {
                cout << 1;
                flag = 1;
            }
            else if(flag)cout << 0;
            x /= 2;
        }
        cout << endl;

    

	return 0;
}
