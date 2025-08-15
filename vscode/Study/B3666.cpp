#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int n;
ull ans;
vector<ull> vc;
vector<ull> tmp;

inline long long read(){
	char readch=getchar(); ull readtmp=0;
	ull readflag=1;
	while(readch<'0' || '9'<readch){if(readch=='-')readflag=-1;readch=getchar();}
	while('0'<=readch && readch<='9'){readtmp=readtmp*10+readch-'0';readch=getchar();}
	return readtmp*readflag;
}

int main(){
    cin >> n;
    tmp.push_back(1);
    for(int i=1; i<=n; i++){
        ull x = read();
        tmp.push_back(x);
        while(!vc.empty() && x >= tmp[vc.back()]){
            ans ^= vc.back();
            vc.pop_back();
        }
        ans ^= i;
        vc.push_back(i);
        
        printf("%d\n", ans);
    }


	return 0;
}
