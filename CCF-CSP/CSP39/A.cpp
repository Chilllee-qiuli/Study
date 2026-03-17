#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, a;

int main(){
    freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> a;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        double x, y;
        cin >> x >> y;
        if((x * x + y * y - a * a) < 1e-9) cnt++;
    }

    double ans = 4.0 * cnt / n;
    printf("%.6lf\n", ans);

	return 0;
}