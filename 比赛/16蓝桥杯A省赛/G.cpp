#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pr pair<double, double>
#define mk make_pair
const int maxn = 1e5 + 10;
int n;

vector<pr> vc;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++){
        double x, y, r;
        cin >> x >> y >> r;
        double a = atan(y / x);
        double b = asin(r / sqrt(x * x + y * y));
        cout << sin(y/x) << endl;
        vc.push_back(mk(a - b, a + b));
    }

    sort(vc.begin(), vc.end());




	return 0;
}
