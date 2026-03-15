#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 +  10;

int n;
struct work{
    double c, p;
    friend bool operator < (work x, work y){
        return 100 * x.c >= (100 - x.p) * y.c;
    }
}wk[maxn];



int main(){
    //ios::sync_with_stdio(0);
    //cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while(T--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> wk[i].c >> wk[i].p;

        }

        double dp = 0.0;
        for(int i = n; i; i--){
            double tmp = 1.0 - 1.0 * wk[i].p / 100.0;
            dp = max(dp,  wk[i].c + dp * tmp);
        }
        printf("%.10lf\n", dp);
    }

	return 0;
}