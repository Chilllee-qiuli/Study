#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e4 + 10;
int a[maxn];
int n;
vector<int> tmp;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];

  tmp.push_back(0);
  int cnt = 0;
  for(int i = 1; i <= n; i++){
    if(a[i] >= tmp[cnt]) tmp.push_back(a[i]), cnt++;
    else {
        int p = lower_bound(tmp.begin() + 1, tmp.begin() + cnt, a[i]) - tmp.begin();
        tmp[p] = a[i];
    }
  }
  cout << cnt << endl;
 
	return 0;
}