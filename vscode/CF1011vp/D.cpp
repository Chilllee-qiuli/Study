#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int t;
int n, k;
int d[maxn];
ll c[maxn];
struct node{
    int id; ll num;
};

bool operator < (node x, node y){
    return x.num == y.num ? x.id > y.id : x.num < y.num;
}
priority_queue<node> pr;

void add(int x){
    for(; x <= n; x += x & -x)c[x] += k + 1;
}

ll sum(int x){
    ll res = 0;
    for(; x; x -= x & -x) res += c[x];
    return res;
}

int main(){
    freopen("1.in", "r", stdin);
    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k;
        while(!pr.empty()) pr.pop();
        for(int i = 1; i <= n; i++) {
            cin >> d[i];
            if(i <= n - k)
                pr.push((node){i, d[i]});
                
            
            c[i] = 0;
        }
        ll ans = 0;
        while(!pr.empty()){
            node tp = pr.top(); pr.pop();
            //printf("tp.id= %d, tp.num= %d\n", tp.id, tp.num);
            ll now = sum(n) - sum(max(0, tp.id - k));
            if(now + k + 1 <= n - tp.id + 1){
                ans += tp.num;
                printf("ans = %lld, tp.id = %d  now = %lld \n", ans, tp.id, now);
                add(tp.id);
            }
        }

        cout << ans << endl;



    }

	return 0;
}
