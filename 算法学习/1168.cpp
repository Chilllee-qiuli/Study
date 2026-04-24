#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int n;
int a[maxn];

priority_queue<int> big;
priority_queue<int, vector<int>, greater<int> > small;

void adjust(){
    while(big.size() > small.size()){
        small.push(big.top());
        big.pop();
    }
    if(!big.empty() && !small.empty()){
        while(big.top() > small.top()){
            int x = big.top(); big.pop();
            int y = small.top(); small.pop();
            big.push(y);
            small.push(x);
        }
    }
}

int find(){
    adjust();
    return small.top();
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    cin >> n;
    for(int i = 1, x; i <= n; i++){
        cin >> x; big.push(x);
        if(i & 1) cout << find() << '\n';
    }


	return 0;
}
