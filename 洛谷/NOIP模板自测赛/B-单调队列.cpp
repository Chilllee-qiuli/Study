#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;
int n, k;
int a[maxn];
int qmin[maxn], qmax[maxn], l1, r1, l2, r2;
int maxx[maxn], minn[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    // r1 = r2 = 1;
    // l1 = l2 = 1;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        //if(i < k) continue;
        while(l1 < r1 && qmin[l1] + k <= i) l1++;
        while(l1 < r1 && a[i] < a[qmin[r1 - 1]]) r1--;
        qmin[r1++] = i;   
        minn[i] = a[qmin[l1]];

        while(l2 < r2 && qmax[l2] + k <= i) l2++;
        while(l2 < r2 && a[i] > a[qmax[r2 - 1]]) r2--;
        qmax[r2++] = i;
        maxx[i] = a[qmax[l2]];
    }
    for(int i = k; i <= n; i++) cout << minn[i] << " ";
    cout << endl;

    for(int i = k; i <= n; i++) cout << maxx[i] << " ";
    cout << endl;


	return 0;
}
