#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, d, h;


bool judge(){
    if(d == 1) {
        if(n != 2 || h > 1) return 1;
    }
    else if(h * 2 < d || d < h) return 1;
    return 0;
}

void zhijing(){
    for(int i = 2; i <= h + 1; i++) // h
        cout << i - 1 << " " << i << endl;
    
    for(int i = h + 2; i <= d + 1; i++){
        if(i == h + 2) cout << 1 << " " << i << endl;
        else cout << i - 1 << " " << i << endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> d >> h;
    if(judge()) {
        cout << -1 << endl;
        return 0;
    }

    if(d == 1) cout << 1 << " " << 2 << endl;
    else {
        zhijing();
        int k = d == h ? 2 : 1;
        for(int i = d + 2; i <= n; i++) 
            cout << k << " " << i << endl;
    } 
     

	return 0;
}
