#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void print(int id, char a, char b){
    cout << id << " " << a << " " << b << endl;
}

void work(int n, char a, char b, char c){
    if(n == 1) {
        print(1, a, b);
        return ;
    }
    //cout << "test" << endl;
    work(n-1, a, c, b);
    print(n, a, b);
    work(n-1, c, b, a);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    work(n, 'A', 'B', 'C');

	return 0;
}