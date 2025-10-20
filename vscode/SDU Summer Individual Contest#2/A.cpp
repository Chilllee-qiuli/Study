#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;

struct node{
    ll x, y;
}p[9];

ll len[5];
map<node, int> mp;
node mpp[5];

bool operator < (node x, node y){
    return x.x == y.x ? x.y < y.y : x.x < y.x;
}



bool judge1(){
    if(mp.size() != 4) return 0;
    for(auto it : mp) if(it.second != 2) return 0;

    int tot = 0;
    for(auto it : mp) mpp[++tot] = it.first;

    if(mpp[1].y != mpp[3].y || mpp[2].y != mpp[4].y || mpp[1].x != mpp[2].x || mpp[3].x != mpp[4].x) return 0;

    if(len[1] == len[2]){
        if(len[1] * len[3] != len[2] * len[4]) return 0;
    }
    else if(len[1] == len[3]){
        if(len[1] * len[2] != len[3] * len[4]) return 0;
    }
    else if(len[1] == len[4]){
        if(len[1] * len[3] != len[2] * len[4]) return 0;
    }
    else return 0;

    vector<pair<node, node> > line;
    vector<pair<node, node> > row;
    for(int i = 2; i <= 8; i += 2){
        if(p[i].x == p[i-1].x) line.push_back(pair(p[i], p[i-1]));
        if(p[i].y == p[i-1].y) row.push_back(pair(p[i], p[i-1]));
    }

    if(line.size() != 2 || row.size() != 2) return 0;
    else {
        if(line[0].first < line[0].second)
        {
            swap(line[0].first.x, line[0].second.x);
            swap(line[0].first.y, line[0].second.y);
        }
        
        if(row[0].first < row[0].second)
        {
            swap(row[0].first.x, row[0].second.x);
            swap(row[0].first.y, row[0].second.y);
        }
        if(line[1].first < line[1].second)
        {
            swap(line[1].first.x, line[1].second.x);
            swap(line[1].first.y, line[1].second.y);
        }
        
        if(row[1].first < row[1].second)
        {
            swap(row[1].first.x, row[1].second.x);
            swap(row[1].first.y, row[1].second.y);
        }
        // 确保大的在前面
        // cout << line[1].first.x << " " << line[1].first.y << endl;
        if(line[0].first.y != line[1].first.y || line[0].first.x == line[1].first.x) return 0;
        // cout << "test" << endl;
        
        if(line[0].second.y != line[1].second.y || line[0].second.x == line[1].second.x) return 0;
        if(row[0].first.y == row[1].first.y || row[0].first.x != row[1].first.x) return 0;
        if(row[0].second.y == row[1].second.y || row[0].second.x != row[1].second.x) return 0;

        
    }

    return 1;
}


int main(){
    //freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int flag = 1;
    for(int i = 1; i <= 8; i++){
        cin >> p[i].x >> p[i].y;
        
        if(i % 2 == 0) 
        {
            if(p[i].x != p[i-1].x && p[i].y != p[i-1].y) flag = 0;
            if(p[i].x == p[i-1].x && p[i].y == p[i-1].y) flag = 0;
            len[i/2] = abs(p[i].x - p[i-1].x) + abs(p[i].y - p[i-1].y);
        }
    }
    for(int i = 1; i <= 8; i++)
    mp[p[i]]++;


    if(!flag){
        cout << "NO" << endl;
        return 0;
    }
    

    if(!judge1()) cout << "NO" << endl;
    else cout << "YES" << endl;




	return 0;
}
