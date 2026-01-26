#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e5+10;
int n;
int maxl[maxn], maxr[maxn], minl[maxn], minr[maxn];
ll ans, a[maxn];

vector<int> tmp;
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];

	for(int i = 1; i <= n; i++){
		while(!tmp.empty() && a[i] >= a[tmp.back()]){
			maxr[tmp.back()] = i;
			tmp.pop_back();
		}
		if(!tmp.size()) maxl[i] = 0;
		else maxl[i] = tmp[tmp.size() - 1];
		tmp.push_back(i);
	}
	while(!tmp.empty()){
		maxr[tmp.back()] = n + 1;
		tmp.pop_back();
	}

	for(int i = 1; i <= n; i++){
		while(!tmp.empty() && a[i] <= a[tmp.back()]){
			minr[tmp.back()] = i;
			tmp.pop_back();
		}
		if(!tmp.size()) minl[i] = 0;
		else minl[i] = tmp[tmp.size() - 1];
		tmp.push_back(i);
	}
	while(!tmp.empty()){
		minr[tmp.back()] = n + 1;
		tmp.pop_back();
	}

	for(int i = 1; i <= n; i++){
		ans += a[i]*(maxr[i] - i)*(i - maxl[i]);
		ans -= a[i]*(minr[i] - i)*(i - minl[i]);
	}

	cout << ans << endl;

	return 0;
}
