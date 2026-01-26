#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int t;
int n, m;

int sub; // submission

struct node{
    string teamname;
    char problemid;
    int tme;
    int result;
}su[maxn];int top;


struct team{
    int ac;
    int tme;
    int flag;
    string name;
};

bool cmp1(node x, node y){
    return x.tme < y.tme;
}

bool cmp2(node x, node y){
    if(x.teamname != y.teamname) return x.teamname < y.teamname;
    else return x.tme < y.tme;
}

map<string, vector<node> > unk;

map<string, team> tam;


map<string, int[28] > pro_tme; // 题目总罚时记录

//map<string, int> team_tme; // 队伍总罚时记录

priority_queue<team> ans;
vector<team> ans_tmp;

vector<string> print;

bool operator < (team x, team y){
    if(x.ac != y.ac) return x.ac < y.ac ; // ac多在前
    else if(x.tme != y.tme) return x.tme > y.tme; // 罚时少在前
    else return x.name > y.name;// 字典序小在前
}
bool equ(team x, team y){
    return x.ac == y.ac && x.tme == y.tme;
}

int main(){
   // freopen("a.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> t;
    while(t--){
        cin >> sub;
        pro_tme.clear();
        // team_tme.clear();
        tam.clear();
        unk.clear();
        while(!ans.empty()) ans.pop();
        print.clear();
        top = 0;
        string teamnam, result;
        char problrmeid;
        for(int i = 1, tme; i <= sub; i++){
            cin >> teamnam;
            cin >> problrmeid;
            cin >> tme;
            cin >> result;
            su[++top].teamname = teamnam;
            su[top].tme = tme;
            su[top].problemid = problrmeid;
            if(result == "Unknown") su[top].result = 0;
            else if(result == "Rejected") su[top].result = -1;
            else su[top].result = 1;
        }

        sort(su + 1, su + 1 + sub, cmp1);

        for(int i = 1; i <= sub; i++){
            string teamname = su[i].teamname;tam[teamname].name = teamname;
            if(su[i].result == -1 && pro_tme[teamname][su[i].problemid - 'A'] != -1) pro_tme[teamname][su[i].problemid - 'A'] += 20;
            else if(su[i].result && pro_tme[teamname][su[i].problemid - 'A'] != -1) { // 已经AC的不再重复统计
                // team_tme[teamname] += su[i].tme + pro_tme[teamname][su[i].problemid - 'A'];
                tam[teamname].tme += su[i].tme + pro_tme[teamname][su[i].problemid - 'A'];
                tam[teamname].ac++;
                
                pro_tme[teamname][su[i].problemid - 'A'] = -1;
                
            }
            else unk[teamname].push_back(su[i]);
        }

        for(auto it : tam){
            ans.push(it.second);
        };


        print.push_back(ans.top().name);

        while(!ans.empty()){
            team teamtmp = ans.top();
            ans_tmp.push_back(ans.top());
            ans.pop();
            if(equ(teamtmp, ans.top())) print.push_back(ans.top().name);
            else break;
        }

        for(auto it : ans_tmp) ans.push(it);
        ans_tmp.clear();

        for(auto it : unk){
            sort(it.second.begin(), it.second.end(), cmp2);
            string teamname = it.first;
            tam[teamname].name = teamname;

            for(int i = 0; i < (int)it.second.size(); i++){
                node tmpt = it.second[i];
                if(pro_tme[teamname][it.second[i].problemid - 'A'] != -1) {
                    tam[teamname].tme += it.second[i].tme + pro_tme[teamname][it.second[i].problemid - 'A'];
                    tam[teamname].ac++;
                    // cout << tmpt.teamname << " " << tmpt.problemid << " " << tmpt.tme << " " << tmpt.result << endl;
                    pro_tme[teamname][it.second[i].problemid - 'A'] = -1;
                }
            }

            //  cout << teamname << " : " << tam[teamname].ac << endl;
            tam[teamname].flag = 1;
            ans.push(tam[teamname]);

            if(!ans.empty() && ans.top().name == teamname) print.push_back(teamname);
            else {
                
                while(!ans.empty() && ans.top().name != teamname && ans.top().flag == 1) ans.pop();
                if(!ans.empty() && ans.top().name == teamname) {
                    print.push_back(teamname);//cout << "yes: " << teamname << endl;
                    continue;
                }


                while(!ans.empty()){
                    team teamtmp = ans.top();
                    ans_tmp.push_back(ans.top());
                    ans.pop();
                    if(equ(teamtmp, ans.top())) {
                        if(teamtmp.name == teamname){
                            print.push_back(ans.top().name);//cout << "yes: " << teamname << endl;
                            break;
                        }
                    }
                    else break;
                }

                for(auto itt : ans_tmp) ans.push(itt);
                ans_tmp.clear();
                //cout << teamname << " " << "not" << endl;
            }

        }


       
        sort(print.begin(), print.end());
        
        for(int i = 0; i < print.size(); i++){
            if(i == 0)cout << print[i] << " ";
            else if(print[i] != print[i-1]) cout << print[i] << " ";
        }
        cout << endl;

        print.clear();

    }


    return 0;
}