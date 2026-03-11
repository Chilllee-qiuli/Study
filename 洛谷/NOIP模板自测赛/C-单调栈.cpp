#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e6 + 10;
int a[maxn], n;
int qu[maxn], top;
int rm[maxn]; // rmax

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n; i++){
        while(top && a[i] > a[qu[top]]) rm[qu[top--]] = i;
        qu[++top] = i;
    }
    while(top) rm[qu[top--]] = 0;
    
    for(int i = 1; i <= n; i++) cout << rm[i] << " ";
    cout << endl;
	return 0;
}
