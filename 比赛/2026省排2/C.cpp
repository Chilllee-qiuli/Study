#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 500500;
int n;

struct Len{
    int l, r;
    int id, fa;
    friend bool operator < (Len x, Len y){
        return x.l == y.l ? x.r > y.r : x.l < y.l;
    }
}len[maxn];


int main(){ 
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while(T--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> len[i].l >> len[i].r;
            len[i].id = i;
        }

        sort(len + 1, len + 1 + n);

        int tot = 0;
        int r = 0;
        for(int i = 1; i <= n; i++){
            if(len[i].l > r) {
                len[i].fa = ++tot;
                r = len[i].r;
            }
            else{
                len[i].fa = tot;
                r = max(r, len[i].r);
            }
        }
        if(tot == 1) cout << -1 << endl;
        else {
            sort(len + 1, len + 1 + n, [](const Len & x, const Len & y){
                return x.id < y.id;
            });
            for(int i = 1; i <= n; i++){
                if(len[i].fa == tot) cout << 2 << " ";
                else cout << 1 << " ";
            }
            cout << endl;
        }
        
    }   


    return 0;
}