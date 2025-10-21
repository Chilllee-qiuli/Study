#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int t;
int n, m;
int p[maxn];
int tmp[maxn];
int lf[maxn], rh[maxn];


void add(int p, int x){
    for(int i = p; i <= n; i += i & (-i)) tmp[i] += x;
}

int qry(int p){
    int res = 0;
    for(int i = p; i; i -= i & (-i)) res += tmp[i];
    return res;
}

int worklf(int x){
    if(x == 0) return 0;
    if(!qry(x)) return x;
    return lf[x] = worklf(lf[x]);
}


int findrh(int x){
    if(x == n + 1) return n + 1;
    if(!qry(x)) return x;
    return rh[x] = findrh(rh[x]);
}

int cntq = 0;
struct node{
    int l, r;
    int op;
    friend bool operator < (node x, node y){
        return x.l < y.l;
    }
}q[maxn];

void spj0(){
    cntq = 0;
    while(m--){
        int op, x, y;
        cin >> op >> x >> y;
        if(op == 1){
            //int l = lower_bound(p + 1, p + 1 + n, x) - p;
            //int r = lower_bound(p + 1, p + 1 + n, y) - p;
            int l = x, r = y;
            if(l == r) continue;
            q[++cntq] = {l, r};
        }
        else {
            int ans = p[y] - p[x];
            for(int i = 1; i <= cntq; i++){
                if(q[i].l <= x && y <= q[i].r ){
                    if(q[i].l == 1 && q[i].r == n) {ans = -1; break;}
                    else {
                        if(q[i].l == 1) ans = max(ans, p[q[i].r + 1] - p[x]);
                        else if(q[i].r == n) ans = max(ans, p[y] - p[q[i].l - 1]);
                        else ans = max(ans, min(p[q[i].r + 1] - p[x], p[y] - p[q[i].l - 1]));
                    }
                }
            }
            cout << ans << endl;
        }
    }
}

bool oor(int L, int R, int l, int r){
    return R < l || r < L;
}//outofrangre
bool ir(int L, int R, int l, int r){
    return L <= l && r <= R;
}


void spjc(){
    int L = 0, R = 0;
    for(int i = 1; i <= m; i++){
        int o = q[i].op;
        int x = q[i].l;
        int y = q[i].r;
        if(o == 1){
            L = x, R = y;
        }
        else {
            
            if(ir(L, R, x, y)) {
                if(R == n && L == 1) cout << -1 << endl;
                else if(R == n) cout << p[y] - p[L - 1] << endl;
                else if(L == 1) cout << p[R + 1] - p[x] << endl;
                else cout << min(p[y] - p[L - 1], p[R + 1] - p[x]) << endl;
            }
            else cout << p[y] - p[x] << endl;
        }
    }
}

void spja(){
    for(int i = 1; i <= m; i++){
        int o = q[i].op;
        int x = q[i].l;
        int y = q[i].r;
        if(o == 2) cout << p[y] - p[x] << endl;
    }
}

int main(){
    //freopen("train6.in", "r", stdin);
    //freopen("train.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> m;
        cntq = 0;
        int flagc = 1;
        int flaga = 1, flagatmp = 0;
        for(int i = 1; i <= n; i++) {
            cin >> p[i];
            lf[i] = i - 1;
            rh[i] = i + 1;
        }

        if(n <= 3000){
            spj0();
            continue;
        }

        memset(tmp, 0, sizeof(tmp));
        for(int i = 1; i <= m; i++) {
            int o, x, y;
            cin >> o >> x >> y;
            q[i].op = o;
            q[i].l = x;
            q[i].r = y;
            if(i != 1 && x >= q[i-1].l && y <= q[i-1].r) flagc = 0;
            if(flagatmp && o == 2) flaga = 0;
            if(o == 1) flagatmp = 1;
        }
        if(flaga){
            spja();
            continue;
        }
        if(flagc) {
            spjc();
            //cout << "test" << endl;
            continue;
        }
        for(int i = 1; i <= m; i++){
            int o = q[i].op;
            int x = q[i].l;
            int y = q[i].r;
            if(o == 1){
                //int l = lower_bound(p + 1, p + 1 + n, x) - p;
                //int r = lower_bound(p + 1, p + 1 + n, y) - p;
                //if(l == r) continue;
                //if(y == p[r])r++;
                add(x, 1);
                add(y + 1, -1);
                //cout << "test: " << l << " " << r << endl; 
                
            }
            else {
                int l, r;
                if(qry(x)) l = worklf(x);
                else l = x;
                if(qry(y)) r = findrh(y);
                else r = y;
                if(l == 0 && r == n + 1) cout << -1 << endl;
                else cout << min(p[r] - p[x], p[y] - p[l]) << endl;
            }
        }
    }

	return 0;
}
