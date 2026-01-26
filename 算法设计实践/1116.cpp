#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;
int n;
int r[maxn], h[maxn];
int qu[maxn], top;

int main(){
    freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> h[i];
        while(top > 0 && h[i] > h[qu[top]])
            r[qu[top--]] = i;

        top++;
        qu[top] = i;        
    }
    while(top > 0) r[qu[top--]] = 0;

    for(int i = 1; i <= n; i++) cout << r[i] << endl;

	return 0;
}