#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 2e5 + 10;
int a[maxn];
int n , m;


int solve_one(){
    int tmp = 1;
    for(int i = 2; i <= n; i++){
        if(a[i - 1] == a[i]) tmp++;
        else tmp = 1;
        if(tmp >= m) return 0;
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 1; i <= n; i++) cin >> a[i];

        int flag = solve_one();
        if(flag) cout << "YES\n";
        else  cout << "NO\n";
    }

	return 0;
}