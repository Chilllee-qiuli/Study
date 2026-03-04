#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int x;
    cin >> x;
    for(int i = 2; i * i <= x; i++){
        if(x % i == 0){
            cout << i << ' ';
            while(x % i == 0) x /= i;
        }
    }

	return 0;
}
