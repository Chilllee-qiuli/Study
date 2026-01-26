#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


class Solution {
public:
    int countCollisions(string directions){
        int cnt = 0;
        int l = 0, r = directions.size() - 1;
        while(l < directions.size() && directions[l] == 'L') l++;
        while(r >= 0 && directions[r] == 'R') r--;
        if(l > r) cout << 0 << endl;
        else {
            for(int i = l; i <= r; i++)
            cnt += (directions[i] != 'S');
        }
        return cnt;
    }
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

	return 0;
}