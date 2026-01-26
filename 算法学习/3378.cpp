#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;
int n;
struct node{
    int val;
    node* left;
    node* right;
    friend bool operator < (const node x, const node y){
        return x.val < y.val;
    }
};


void repair(int x){ //自底向上修复
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    while(n--){
        int op;
        cin >> op;
        if(op == 1){
            int x;
            cin >> x;
        }
        else if(op == 2){

        }
        else if(op == 3){

        }
    }


	return 0;
}
