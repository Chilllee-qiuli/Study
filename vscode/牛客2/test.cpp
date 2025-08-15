#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n = 100;

int a[100] = {0, 1, 2, 3, 4, 5};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int f = 2;
    int k = lower_bound(a + 1, a + 6, f) - a;
    cout << k << endl;


	return 0;
}
