#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int sum;

int two_and_com(int x, int y, int xy){
    if(min(x, y) + xy >= max(x, y)) return (x + y + xy) / 2;
    else return min(x, y) + xy;
}
int two_maxx(int x, int y, int xy){
    if(min(x, y) + xy >= max(x, y)) return (x + y + xy) / 2;
    else return max(x, y);
}
int three_and_com(int x, int y, int z, int xyz){
    int minn = min({x, y, z});
    int maxx = max({x, y, z});
    int midd = x + y + z - maxx - minn;
    if(minn + xyz <= midd ) return minn + xyz;
    else if(two_and_com(minn, midd, xyz) <= maxx) return two_and_com(minn, midd, xyz);
    else return sum/3;
}



int workmaxx(int a, int b, int c, int ab, int ac, int bc, int abc){
    
    //cout << two_and_com(b+ab, c+ac, bc) << endl;
    //cout << "mid : " << a << " " << b + ab << "  " << ac + c << " " << abc << endl;
   // cout << three_and_com(a, b+ab, c+ac, abc) << endl;
    if(a >= two_and_com(b +ab, c + ac, bc)) {
        b += ab;
        c += ac;
        return three_and_com(a, two_and_com(b, c, bc), sum - a - abc - two_and_com(b, c, bc), abc);
    }
    else return sum/3;
    
}

int main(){
    //freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        int  x, y, z, xy, xz, yz, xyz;
        cin >> sum;
        cin >> x >> y >> xy >> z >> xz >> yz >> xyz;
        int maxx = max({x, y, z});
        int minn = min({x, y, z});
        //cout << "test " << t << endl;
        if(maxx == x)
            cout << workmaxx(x, y, z, xy, xz, yz, xyz) << endl;
        else if(maxx == y) cout << workmaxx(y, x, z, xy, yz, xz, xyz) << endl;
        else cout << workmaxx(z, x, y, xz, yz, xy, xyz) << endl;
    }


    return 0;
}