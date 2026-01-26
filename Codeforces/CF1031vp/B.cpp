#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int w, h, a, b;



int main(){
    freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t; 

    while(t--){
        cin >> w >> h >> a >> b;
        int ax, ay, bx, by;
        cin >> ax >> ay >> bx >> by;
        //cout << "test " << t <<  endl;
        /*if(ax > bx) {swap(ax, bx); swap(ay, by);}
        int Ax = ax + a; 
        
        if(bx - Ax < a){

            if(ay > by){
                swap(ay, by);
                swap(ax, bx);
            }
            int Ay = ay + b;
            if(by < Ay) {cout << "NO" << endl; continue;}
        }

        if(ay > by) {swap(ax, bx); swap(ay, by);}
        int  Ay = ay + b;

        if(by - Ay < b){
            if(ax > bx) {swap(ax, bx); swap(ay, by);}
            int Ax = ax + a;
            if(bx < Ax) {cout << "NO" << endl; continue;}
        }

        cout << "YES" << endl;
        */
        if(ax == bx) cout << (abs(by - ay) % b ? "NO" : "YES");
        else if(ay == by) cout << (abs(bx - ax) % a ? "NO" : "YES");
        else cout << ((abs(by - ay) % b) && (abs(bx - ax) % a) ? "NO" : "YES");


       cout << endl;
    }

	return 0;
}
