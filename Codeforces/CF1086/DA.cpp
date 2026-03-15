#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 550;
bitset<maxn> bt[maxn];

int n;
int in[maxn], out[maxn], fa[maxn];

int find(int x){
    if(x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

int work(){
    cin >> n;
    for(int i = 1; i <= n; i++) {
            in[i] = 0;
            out[i] = 0;
            fa[i] = i;
            bt[i].reset();
        }
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++){
        char x;
        cin >> x;
        if(x == '1') bt[i].set(j);
        if(i == j && x == '1') bt[j].set(i);
    }
    // for(int i = 1; i <= n; i++, cout << endl)
    // for(int j = 1; j <= n; j++)
    // cout << bt[i].test(j);

    int cnt = 0;
    for(int i = 1; i <= n; i++)
    for(int j = i; j <= n; j++){
        if(i == j) {
            if(bt[i].test(j) != 1) return 0;
            continue;
        }
        if(bt[i].test(j) && bt[j].test(i)) return 0;
        
        if(bt[i].test(j)){
            out[i]++;
            in[j]++;

        }
        if(bt[j].test(i)){
            out[j]++;
            in[i]++;

        }
    }

    //cout << "test2 " << endl;
    //if(cnt != n - 1) return 0;

    for(int i = 1; i <= n; i++)
        if(!in[i] && !out[i]) return 0;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) continue;
            if(bt[i].test(j)){
                bitset<maxn> tmp = bt[i] & bt[j];
                if(tmp != bt[j]) return 0;
            }
        }        
    }
    for(int i = 1; i <= n; i++){
        bitset<maxn> ti;
        int flag = 0;
        for(int j = 1; j <= n; j++){
            if(i == j) continue;
            if(bt[i].test(j)){
                bitset<maxn> tmp = bt[i] & bt[j];
                tmp ^= bt[i];
                if(!flag) {
                    ti = tmp;
                    flag = 1;
                }
                else ti &= tmp;
            }
        }    
        for(int j = 1; j <= n; j++){
            if(i == j) continue;
            if(ti.test(j)){
                int u = find(i), v = find(j);
                if(u == v) return 0;
                fa[u] = v;
                cnt++;
            }
        } 
    }
    for(int i = 2; i <= n; i++){
        if(find(i) != find(i - 1)) return 0;
    }
    return 1;
    
}

void print(){
    cout << "YES\n";


}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while(T--){
        
        if(work()) print();
        else cout << "NO\n";
    }

	return 0;
}