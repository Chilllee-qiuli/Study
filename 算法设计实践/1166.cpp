#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

vector<ull> tmp;
int n;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++){
        ull x;
        cin >> x;
        tmp.push_back(x);
    }

    sort(tmp.begin(), tmp.end());
    vector<ull> res;

    for(int i = 0; i < tmp.size(); i++ ){
        if(i + 1 < tmp.size() && tmp[i + 1] == tmp[i]) i++;
        else  res.push_back(tmp[i]);
        
    }

    sort(res.begin(), res.end());
    cout << res[0] << " " << res[1] << endl;

	return 0;
}