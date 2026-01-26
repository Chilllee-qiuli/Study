#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int n, k;


inline long long read(){
	char readch=getchar(); ull readtmp=0;
	ull readflag=1;
	while(readch<'0' || '9'<readch){if(readch=='-')readflag=-1;readch=getchar();}
	while('0'<=readch && readch<='9'){readtmp=readtmp*10+readch-'0';readch=getchar();}
	return readtmp*readflag;
}

int main(){
    cin >> n >> k;
    vector<ull> a(n+1);
    deque<int> q;
    for(int i=1; i<=n; i++){
        ull x = read();
        int l = max(i-k+1, 1);
        while(!q.empty() && q.front() < l ) q.pop_front();
        while(!q.empty() && a[q.back()] <= x) q.pop_back();
        q.push_back(i);
        a[i] = x;
        if(i-k+1 >= 1) printf("%d\n", q.size());
    }

	return 0;
}
