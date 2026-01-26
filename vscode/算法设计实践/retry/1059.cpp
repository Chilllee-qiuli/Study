#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 // 注意先分治第一个然后下面盘子一股脑丢是错误的

 // 应该是先分治上面一坨留给后人解决，然后移动最后一个盘子
 // 之所以我能发现错误是因为拿 n = 3 手算了一下，发现用上面第一种方法步数多了很多，而先把上面一坨看成一个盘子才是对的
void work(int n, char a, char b, char c){
    if(n == 1) {
        cout << 1 << " " << a << " " << b << endl;
        return ;
    }
    work(n - 1, a, c, b);
    cout << n << " " << a << " " << b << endl;
    work(n - 1, c, b, a);
} 
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;

    work(n, 'A', 'B', 'C'); // a -> b use c


	return 0;
}