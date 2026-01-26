#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void work(int n, char a, char b, char c){
    if(n == 1) {
        printf("%d %c %c\n", 1, a, b);
        return ;
    }

    work(n-1, a, c, b);
    printf("%d %c %c\n", n, a, b);
    work(n-1, c, b, a); 
}

int main(){
    //ios::sync_with_stdio(0);
    //cin.tie(0), cout.tie(0);

    int n;

    cin >> n;

    work(n, 'A', 'B', 'C');


	return 0;
}