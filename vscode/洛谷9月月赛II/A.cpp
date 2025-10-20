#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int max_M = 1e5;
ll num[maxn];

void pre(){

    for(int i = 2; i <= max_M; i++)
        num[i] = 1ll * i * (i - 1) / 2 ;

}

int main(){
   // freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    pre();
    int t;
    cin >> t;

    while(t--){
        ll m;
        cin >> m;
        int id = lower_bound(num + 1, num + 1 + max_M, m) - num;
        //cout << id << endl;
        if(id > m * 2 - 2) cout << "Lose!" << endl;
        else cout << id << " " << m * 2 - 2 << endl;
    }

	return 0;
}
