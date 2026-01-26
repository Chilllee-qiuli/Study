#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n = 8;
int a[100] = {0, 1, 2, 5, 7, 8, 9, 11, 13};
int tmp[10];

void add(int p, int x){
    for(int i = p; i <= n; i += i & (-i)) tmp[i] += x;
}

int qry(int p){
    ll res = 0;
    for(int i = p; i; i -= i & (-i)) res += tmp[i];
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

   
    for(int i = 1; i <= n; i++) add(i, a[i] - a[i-1]);
    add(1, 1);
    add(8, -1);

    cout << qry(7) << endl;



	return 0;
}
