#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 20;
int a[maxn];
int n;
int cnt1, cnt2;
int ans;
int cntans1, cntans3;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt1 += (a[i] == 1);
        cnt2 += (a[i] == 2);
    }
    cnt2 += cnt1;

    for(int l = 1; l <= cnt1; l++){
        if(a[l] == 3) cntans3++;
        else if(a[l] == 2) ans++;
    }

    for(int l = cnt2 + 1; l <= n; l++)
    if(a[l] == 1) cntans1++;
    else if(a[l] == 2) ans++;

    ans += max(cntans1, cntans3);
    cout << ans << endl;



	return 0;
}