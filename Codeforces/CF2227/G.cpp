#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int a[maxn];
int t;
int n;
int tr[2][maxn];

int fd(int id, int x){
    int tmp = 0;
    for(; x; x -= x & -x) tmp += tr[id][x];
    return tmp;
}

void add(int id, int x, int y){
    for(; x <= n; x += x & -x) tr[id][x] += y;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++) tr[0][i] = tr[1][i] = 0;

        ll ans = 0;
        for(int i = 1; i <= n; i++){
            if(i & 1){

            }
        }
    }

	return 0;
}
