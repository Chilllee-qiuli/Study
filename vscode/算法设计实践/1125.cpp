#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/*
* 个税计算，p为综合所得收入额，d为其他扣除额，f为减免税额。
* 返回应纳税额。请用整数运算。
*/
/*
* 个税计算，p为综合所得收入额，d为其他扣除额，f为减免税额。
* 返回应纳税额。请用整数运算。
*/
int income_tax(int p, int d, int f) {
  p -= 60000 + d;

  if(p <= 0) return 0;
  if(p <= 36000) return max(0, int( p * 0.03 - f));
  if(p <= 144000) return max(0, int(1080 + (p - 36000) * 0.1 - f));
  if(p <= 300000) return max(0, int(11880 + (p - 144000) * 0.2 -  f));
  if(p <= 420000) return max(0, int(43080 + (p - 300000) * 0.25 - f));
  if(p <= 660000) return max(0, int(73080 + (p - 420000) * 0.3 - f)) ;
  if(p <= 960000) return max(0, int(145080 + (p - 660000) * 0.35 - f));
  return max(0, int(250080 + (p - 960000) * 0.45 - f));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    cout << income_tax(a, b, c) << endl;

	return 0;
}