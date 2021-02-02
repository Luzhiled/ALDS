#include <bits/stdc++.h>
using namespace std;

vector<int> knuth_morris_pratt(const string &s){
    int n=s.size();
    //vector<int> kmp(n+1,-1),mp(n+1,-1);
    vector<int>kmp(n+1,-1);
    for(int i=0,j=-1;i<n;i++){
        while(~j&&s[i]!=s[j]) j=kmp[j];
        //kmp[i+1]=mp[i+1]=++j;
        j++;
        if(i+1<n&&s[i+1]==s[j]) kmp[i+1]=kmp[j];
        else kmp[i+1]=j;
    }
    //return mp;
    return kmp;
}
// smallest d s.t. s[x] == s[x + d] for all x
vector<int> minimum_period(const string &s){
    auto mp=knuth_morris_pratt(s);
    for(int i=1;i<(int)mp.size();i++) mp[i]=i-mp[i];
    return mp;
}
// positions for t that match s
vector<int> pattern_match(string s,string t){
    int n=s.size(),m=t.size();
    vector<int> kmp=knuth_morris_pratt(s);

    vector<int> res;
    int i=0,j=0;
    while(i+j<m){
        if(s[j]==t[i+j]){
            if(++j!=n) continue;
            res.emplace_back(i);
        }
        i+=j-kmp[j];
        j=max(kmp[j],0);
    }
    return res;
}

int main() {
    string s, t;
    cin >> s >> t;

    auto idxs = pattern_match(t, s);
    for (auto idx: idxs) cout << idx << endl;
}
