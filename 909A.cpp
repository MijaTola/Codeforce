#include <bits/stdc++.h>

using namespace std;


int main(){
    
   string s,t;
  cin >> s >> t;
    string p = "";
    vector<string> ans;
    for (int i = 0; i < (int)s.size(); ++i){
        p += s[i];
        string r = "";
        for (int j = 0; j < (int) t.size(); ++j){
            r += t[j];
            string cur = p + r;
            ans.push_back(cur);
        }
    }

    sort(ans.begin(),ans.end());
    cout << ans[0]<< "\n";
    return 0;
}


/*
 *
 *
 *
 
    _____
    ___
      ___
    __
     __
       __
    _
     _
      _
       _

 * */
