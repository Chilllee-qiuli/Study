#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+10;
int h[maxn], n, tmax, tmin;
int hmax[maxn], hmin[maxn], ans;


inline long long read(){
	char readch=getchar(); ll readtmp=0;
	ll readflag=1;
	while(readch<'0' || '9'<readch){if(readch=='-')readflag=-1;readch=getchar();}
	while('0'<=readch && readch<='9'){readtmp=readtmp*10+readch-'0';readch=getchar();}
	return readtmp*readflag;
}

int main(){
    cin >> n; 
    for(int i=1; i<=n; i++){
        h[i] = read();
        while(tmax && h[i] > h[hmax[tmax]]) --tmax;
        while(tmin && h[i] <= h[hmin[tmin]]) --tmin;
        int k = upper_bound(hmin+1, hmin+1+tmin, hmax[tmax]) - hmin;
        if(k != (tmin+1)){
            ans = max(ans, i - hmin[k]+1); 
            // 最后加进来这个数一定是后缀最大值
            // 只要找到这个数大于【这个数前一个后缀最大值的坐标】的【最小的后缀最小值的坐标】就是一段合法区间
            // 分类讨论可知，合法区间内不存在其他后缀最大值，故最大值一定是r，即此时的i
            // 合法区间内最小值一定是k，因为他是第一个后缀最小值
        }
        hmax[++tmax] = i;
        hmin[++tmin] = i;
    }

    printf("%d\n", ans);

	return 0;
}
