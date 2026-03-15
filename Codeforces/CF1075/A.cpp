#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 110;
int n, h, l;
int a[maxn];

int solve_one();

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while(T--) cout << solve_one() << endl;

    return 0;
}

int solve_one(){
    cin >> n >> h >> l;
    for(int i = 1; i <= n; i++) cin >> a[i];

    int cnt = 0 ;
    sort(a + 1, a + 1 + n);
    int r = n;
    while(r) {
        if(a[r] > max(h, l)) r--;
        else break;
    }
    int f = r / 2;
    while(l){
        if(a[f] > min(h, l)) f--;
        else break;
    }
    return min(r / 2, f);
}
