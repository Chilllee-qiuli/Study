#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


class Solution {
public:
    int countPalindromicSubsequence(string s) {
        map<char, int> total;
        map<char, int> mpl;
        map<pair<char, char>, int> cnt;

        for(int i = 0; i < s.length(); i++) total[s[i]]++;
        mpl[s[0]]++;
        total[s[0]]--;
        for(int i = 1; i < s.length() - 1; mpl[s[i++]]++){
            total[s[i]]--;
            for(char k = 'a'; k <= 'z'; k++)
                if(total[k] && mpl[k]){
                    string str = "";
                    cnt[make_pair(k, s[i])]++;
                }
        }
        cout << cnt.size() << endl;
        //for(auto it : cnt) cout << it.first.first << ":" << it.first.second << " " << it.second << endl;
        return 0;
    }
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    string s = "aabca";
    Solution st;
    st.countPalindromicSubsequence(s);
    

	return 0;
}