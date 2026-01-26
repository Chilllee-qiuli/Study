#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    string name;
    int rank;
};

bool operator <(node x,node y){
    return x.rank<y.rank;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    map<string,int> a,b,c;
    for(int i=1;i<=n;i++){
        string uni;
        cin>>uni;
        if(!a[uni]) a[uni]=i;
    }
    for(int i=1;i<=m;i++){
        string uni;
        cin>>uni;
        if(!b[uni]) b[uni]=i;
    }
    //cout<<"test"<<endl;
    vector<node> aa,bb;
    //cout<<"test2"<<endl;
    for(auto x:a){
        node n;
        n.name=x.first;
        n.rank=x.second;
        aa.push_back(n);
    }
    //cout<<"test3"<<endl;
    for(auto x:b){
        node n;
        n.name=x.first;
        n.rank=x.second;
        bb.push_back(n);
    }
    sort(aa.begin(),aa.end());
    //cout<<"test4"<<endl;
    sort(bb.begin(),bb.end());
    //cout<<"test5"<<endl;
    int minlen=min(aa.size(),bb.size());
    unordered_set<string> ans;
    vector<string> anss;    
    for(int i=0;i<minlen;i++){
        if(ans.find(aa[i].name)==ans.end()){
            anss.push_back(aa[i].name);
            ans.insert(aa[i].name);
        }
        if(ans.find(bb[i].name)==ans.end()){
            anss.push_back(bb[i].name);
            ans.insert(bb[i].name);
        }
    }
    if(aa.size()>bb.size()){
        for(int i=minlen;i<aa.size();i++){
            if(ans.find(aa[i].name)==ans.end()){
            anss.push_back(aa[i].name);
            ans.insert(aa[i].name);
        }
        }
        
    }
    else if(aa.size()<bb.size()){
        for(int i=minlen;i<bb.size();i++){
            if(ans.find(bb[i].name)==ans.end()){
            anss.push_back(bb[i].name);
            ans.insert(bb[i].name);
            }
        }
        
    }
    for(auto x:anss) cout<<x<<endl;
    return 0;
}