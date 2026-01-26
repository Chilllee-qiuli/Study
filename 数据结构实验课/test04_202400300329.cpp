#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 7;
int n;
int fa[maxn];

int find(int x){
    if(x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

void print(const vector<int>& vec){
    cout << "(";
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i];
        if(i != vec.size() - 1) cout << ",";
    }
    cout << ")" << endl;
} 

map<int, vector<int> > mp;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cout << "input" << endl;
    cin >> n;
    for(int i = 1; i <= n; i++){
        fa[i] = i;
    }
    int r;
    cin >> r;
    while(r--){
        int x, y;
        string str;
        cin >> str;
        x = str[1] - '0';
        y = str[3] - '0';
        int fax = find(x), fay = find(y);
        fa[fax] = fay;
    }
    cout << "output" << endl;
    
    for(int i = 1; i <= n; i++)
        mp[find(i)].push_back(i);

    for(auto it : mp) {
        sort(it.second.begin(), it.second.end());
        print(it.second);
    }

    cout << "end" << endl;

	return 0;
}
