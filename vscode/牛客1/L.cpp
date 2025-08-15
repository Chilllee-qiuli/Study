#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5+10;
int T;
int n, q;
int a[maxn], tmp[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    while(T--){
        cin >> n >> q;
        memset(a, 0, sizeof(a));
        for(int i = 1; i <= n; i++) cin >> a[i], tmp[i] = a[i];
        sort(a + 1, a + 1 + n);
        int mid = (n+1)/2, rid = mid + 1;
        int m = a[mid], r = a[rid];
        int cry = 0;
        if(m == r){
            while(m == a[mid-1] && mid > 1)mid--;
            cry = mid - 1;
        }
        else cry = mid;
        while(q--){
            int p, v;
            cin >> p >> v;

            if(tmp[p] + v < m || tmp[p] > r) continue; // small -> small, big -> big
            else if(m == r){
                if(tmp[p] + v == m) cry--;
                else 
            }
        }
    }


	return 0;
}
