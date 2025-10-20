#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e7 + 10;
int n;
int cnt[maxn];
int k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for(int i = 1, x; i <= n; i++){
        cin >> x;
        cnt[x]++;
    }

    int tmp = 0;
    for(int i = 0; i <= maxn; i++){

        tmp += cnt[i];
        if(tmp >= k){
            cout << i << endl;
            return 0;
        }
    }


	return 0;
}
