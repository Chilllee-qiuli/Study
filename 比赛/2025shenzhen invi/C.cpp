#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; ++ i){
        cin >> a[i];
    }
    vector<int> l(n + 2, -1), r(n + 2, -1);
    r[0] = 1, l[n + 1] = n;
    for(int i = 1; i <= n; ++ i){
        l[i] = i - 1;
        r[i] = i + 1;
    }
    auto check = [&](int i)->bool{
        if(i > n) return false;
        if(r[i] > n) return false;
        if(r[r[i]] > n) return false;
        return true;
    };
    auto cmp = [&](int i, int j)->bool{
        if(!check(i)) return true;
        if(!check(j)) return false;
        int x[] = {a[i], a[r[i]], a[r[r[i]]]};
        int y[] = {a[j], a[r[j]], a[r[r[j]]]};
        sort(x, x + 3);
        sort(y, y + 3);
        if(x[1] != y[1]) return x[1] <= y[1];
        if(x[0] != y[0]) return x[0] <= y[0];
        return x[2] <= y[2];
    };
    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
    for(int i = 1; i <= n - 2; ++ i){
        pq.push(i);
    }
    while(!pq.empty()){
        int i = pq.top();
        if(!check(i)) continue;
        int x[] = {a[i], a[r[i]], a[r[r[i]]]};
        sort(x, x + 3);
        a[i] = x[1];
        l[r[r[i]]] = i;
        r[i] = r[r[r[i]]];
        pq.push()
    }
    for(int i = 1; i <= n; ++ i){
        if(l[i] == 0 && r[i] == n + 1){
            cout << a[i] << endl;
            return;
        }
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while(T --) solve();
    return 0;
}