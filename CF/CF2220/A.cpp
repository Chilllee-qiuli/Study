#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 210;
int n;
int a[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        cin >> n;
        int flag = 1;
        for(int i = 1; i <= n; i++)  cin >> a[i];
        sort(a + 1, a + 1 + n, greater<int>());
        for(int i = 2; i <= n; i++){
            if(a[i] == a[i - 1]) flag = 0;
        }
        if(!flag){
            cout << -1  << "\n";
            continue;
        }
        else {
            for(int i = 1; i <= n; i++) cout << a[i] << " ";
            cout << "\n";
        }
    }

	return 0;
}