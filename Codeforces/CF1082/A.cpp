#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int x, y;

bool judge(int x, int y){
    if(y > 0){
        if(2 * y > x || (x - 2 * y) % 3 != 0 ) return false;
        return true;
    }
    else if(y == 0){
        if(x % 3 != 0) return false;
        return true;
    }
    else {
        if(4 * y * -1 > x || (x - 4 * y * -1) % 3 != 0) return false;
        return true;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> x >> y;
        int tmp = x - 2 * y;
        if(judge(x, y)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

	return 0;
}
