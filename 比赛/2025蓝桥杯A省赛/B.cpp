#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int mp[7][7];
int n = 6;

void print(){
  for(int i = 1; i <= 6; i++)
  for(int j = 1; j <= 6; j++){
    if(mp[i][j] == 1) cout << 1 ;
    else  cout << 0 ;
    
  }
  cout << endl;
}
bool judge_hhhwww(int i, int j){
  if(i >= 3 && mp[i][j] == mp[i - 1][j] && mp[i - 1][j] == mp[i - 2][j]) return 1;
  if(i <= 4 && mp[i][j] == mp[i + 1][j] && mp[i + 1][j] == mp[i + 2][j]) return 1;
  if(j >= 3 && mp[i][j] == mp[i][j - 1] && mp[i][j] == mp[i][j - 2]) return 1;
  if(j <= 4 && mp[i][j] == mp[i][j + 1] && mp[i][j] == mp[i][j + 2]) return 1;
  return 0;
}
bool judge(){
  for(int i = 1; i <= 6; i++)
  for(int j = 1; j <= 6; j++)
    if(judge_hhhwww(i, j)) return 0;
    
    int hang[7], lie[7];
    memset(hang, 0, sizeof(hang));
    memset(lie, 0, sizeof(lie));
    for(int i = 1; i <= 6; i++)
    for(int j = 1; j <= 6; j++){
        hang[i] += mp[i][j];
        lie[j] += mp[i][j];
    }
    for(int k = 1; k <= n; k++){
        if(lie[k] || hang[k]) return 0;
    }
  
  set<string> st;
  for(int i = 1; i <= 6; i++) {
    string s;
    for(int j = 1; j <= n; j++) 
    if(mp[i][j] == 1) s += '1';
    else s += '0';
    if(st.find(s) != st.end()) return 0;
    st.insert(s);
  }
  set<string> sr;
  for(int j = 1; j <= 6; j++){
    string s;
    for(int i = 1; i <= n; i++) 
    if(mp[i][j] == 1) s += '1';
    else  s += '0';
    if(sr.find(s) != sr.end()) return 0;
    sr.insert(s);
  }
  return 1;

}

void dfs(int cnt){
  if(cnt > 36){
    if(judge()) print();
    return ;
  }
  int u = (cnt - 1) / 6 + 1;
  int v = (cnt - 1)% 6 + 1;
  if(u < 1 || u > 6 || v < 1 || v > 6){
    cout << "!! " << u << " "  << v << "\n";
  }
  if(mp[u][v]) {
    dfs(cnt + 1);
    return ;
  }
  mp[u][v] = 1;
  dfs(cnt + 1);
  mp[u][v] = -1;
  dfs(cnt + 1);
  mp[u][v] = 0;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

  mp[1][1] = mp[5][3] = mp[5][6] = mp[6][5] = mp[1][3] = mp[3][4] = 1;
  mp[1][2] = mp[1][4] = mp[2][4] = mp[3][5] = mp[3][6] = mp[6][2] = -1;

  dfs(1); 
    

    return 0;
}