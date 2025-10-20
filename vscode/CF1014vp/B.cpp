#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int n, num[2];
string a, b;

int main(){
    // freopen("1.in", "r", stdin);
   ios::sync_with_stdio(0);
   cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        cin >> a >> b;
        int flag = 0;
        num[1] = num[0] = 0;
        for(int i = 0; i < n; i++, flag ^= 1){
            num[flag] += (a[i] == '1');
            num[flag^1] += (b[i] == '1');
        }
        if(num[0] <= n/2 && num[1] <= (n/2 + (n%2 == 1))) cout << "YES" << endl;
        else cout << "NO" << endl;
       // printf("test: %d, %d\n", num[0], num[1]);
    }

	return 0;
}
