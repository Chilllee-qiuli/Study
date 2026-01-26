#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f3f3f;
int x, y;




ll work(ll small, ll mid, ll big){
    if(mid + big - 1 >= x){
        return 3;
    }
    
    small = mid + big - 1;
    ll s = min({small, mid, big}), b = max({small, mid, big});
    ll m = small + mid + big - s - b;
   // printf("now: s = %d, m = %d, b = %d\n", s, m, b);
    return work(s, m, b) + 1;

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> x >> y;


    cout << work(y, y, y) << endl;


	return 0;
}
