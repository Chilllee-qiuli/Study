#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void work(int x){
    if(x == 0) return;
    if(x == 1) {
        cout << 1 << "";
        return ;
    }

    work(x/2);
    if(x & 1) cout << 1 << "";
    else cout << 0 << "";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int x;
    cin >> x;
    work(x);


	return 0;
}
