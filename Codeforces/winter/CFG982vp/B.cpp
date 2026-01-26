#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2020;
int t;
int n;
int a[maxn], b[maxn];
int l[maxn];
int num[maxn], tot;

int c[maxn];

set<int> st;

void add(int x, int y){
    for(; x <= n; x += x & -x) c[x] += y;
}
int sum(int x){
    int res = 0;
    for(; x; x -= x & -x) res += c[x];
    return res;
}


int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        tot = 0;
        int ans = maxn;
        memset(c, 0, sizeof(c));
        memset(l, 0, sizeof(l));
        st.clear();
        tot = 0;
        memset(num, 0, sizeof(num));
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            st.insert(a[i]);
        }

        for(auto x : st) num[++tot] = x;

        for(int i = 1; i <= n; i++) b[i] = lower_bound(num + 1, num + 1 + tot, a[i]) - num;

        for(int i = n; i; i--){
            add(b[i], 1);
            ans = min(ans, i - 1 + (n - i + 1) - sum(b[i]));
        }
        cout << ans << endl;
    }

	return 0;
}
