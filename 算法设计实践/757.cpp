#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[1] != b[1]) {
                return a[1] < b[1];
            }
            return a[0] > b[0]; 
        });

        int cnt = 0; 
        int first = -1, second = -1; 

        for (auto interval : intervals) {
            int start = interval[0];
            int end = interval[1];

            bool fir = (first >= start && first <= end);
            bool sec = (second >= start && second <= end);

            if (fir && sec) continue;
            else if (fir || sec) {
            if (!fir) {
                    first = second;
                    second = end;
                } else second = end;
                cnt++;
            } 
            else {
                first = end - 1;
                second = end;
                cnt += 2;
            }
        }

        return cnt;
    }
};

vector<vector<int>> test = {{1,3},{3,7},{8,9}};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    Solution sl;
    cout << sl.intersectionSizeTwo(test) << endl;
    return 0;
}