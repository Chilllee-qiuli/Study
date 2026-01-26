#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class C{};
class D{};
class A{
    public:
    void f(C tmp){
        cout << "1a" << endl;
    }
    void f(D cur){
        cout << "2a" <<endl;
    }
};
class B: public A{
    public:
    
};
int main(){
    A* a = new A();
    D* lxj = new D(); 
    a->f(*lxj);
    return 0;
}