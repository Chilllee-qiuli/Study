#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int n, k;

struct node{
    int l, r, real;
};

bool operator < (node x, node y){
    return x.real == y.real ? x.l > y.r : x.real > y.real;
}

bool inrange(int x, node tmp){
    return x >= tmp.l && x <= tmp.r;
}

priority_queue<node> q;

int main(){
    freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k ;
        for(int i = 1, l, r, real; i <= n; i++){
            cin >> l >> r >> real;
            q.push({l, r, real});
        }

        while(!q.empty()){
            node tmp = q.top();
            q.pop();
            if(inrange(k, tmp))  k = max(k, tmp.real);
        }

        cout << k << endl;
    }

	return 0;
}
