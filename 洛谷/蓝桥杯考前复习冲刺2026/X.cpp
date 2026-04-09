#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;
int a[maxn], k, n;

int tmp[maxn], l, r;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);


    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    
    for(int i = 1; i <= n; i++){
        while(l < r && tmp[l] + k <= i) l++;
        while(l < r && a[i] < a[tmp[r - 1]]) r--;
        tmp[r++] = i;
        if(i >= k) cout << a[tmp[l]] << " ";
    }
    cout << endl;
    l = r = 0;
    for(int i = 1; i <= n; i++){
        while(l < r && tmp[l] + k <= i) l++;
        while(l < r && a[i] > a[tmp[r - 1]]) r--;
        tmp[r++] = i;
        if(i >= k) cout << a[tmp[l]] << " ";
    }

    return 0;
}