#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n, m;

int c[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;

    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;

        if(a == b-1) c[a] = 1;
    }

    int flag = 1;
    for(int i = 1; i <= n-1; i++){
        if(!c[i]) flag = 0;
    }
    if(flag)

    return 0;
}