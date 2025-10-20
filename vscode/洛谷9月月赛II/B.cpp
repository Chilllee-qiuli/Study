#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;
string s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    cin >> s;
    s = "@" + s;

    int cnt = 0;
    for(int i = 1; i <= n; i++)
        if(s[i] != s[i-1]) cnt++;
    
    int minn = 0, maxx = 0;
    if(k <= cnt - 1) minn = cnt;
    else minn = k + 1;
    if(k <= n - cnt) maxx = cnt + k;
    else maxx = n;
    if(n - 1 < k) cout << 0 << endl;
    else cout << maxx - minn + 1 << endl;

    printf("test: %d, %d\n", minn, maxx);

	return 0;
}
