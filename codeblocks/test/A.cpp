#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;

int w[maxn];

int top(){
	return w[1];
}

void modify(int u){
	if(u == 1 || w[u >> 1] < w[u] )return;
	swap(w[u/2], w[u]);
	modify(u/2);
}

void push(int x){
	w[++tot] = x;
	modify(tot);
}

void pop(){
	swap(w[1], w[tot--]);
	repair(1);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);


    cout << "Hello world!" << endl;
    return 0;
}
