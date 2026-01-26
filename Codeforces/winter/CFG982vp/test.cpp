#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int a[10] = {0, 1, 2, 3, 4, 5};

    int id = lower_bound(a, a + 1 + 5, 2) - a;
    cout << id << endl;

	return 0;
}
