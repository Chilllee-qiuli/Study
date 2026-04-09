#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100;
int n;
int a[maxn];

void print(){
    for(int i = 1; i <= n; i++) 
    if(a[i]) cout << "Y";
    else cout << "N";
    cout << "\n";
}
void dfs(int u){
    if(u > n){
        print();
        return ;
    }
    dfs(u + 1);
    a[u] = 1;
    dfs(u + 1);
    a[u] = 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;

    dfs(1);


    

    return 0;
}