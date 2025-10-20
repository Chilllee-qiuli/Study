#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int n, m;

map<int, int> mp;
int t[maxn], s[maxn];

int main(){
    //ios::sync_with_stdio(0);
    //cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int x; char ch;
        scanf(" %d-%c", &x, &ch);
        t[i] = x;
        s[i] = ch;
    }

	return 0;
}
