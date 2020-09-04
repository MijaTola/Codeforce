#include <bits/stdc++.h>

using namespace std;

int n;
string s,t;
vector<string> v;

int main() {
    cin >> n >> s >> t;
    string x = "abc";

    do {
        v.push_back(x);
        string p = "";
        for (int i = 0; i < n; ++i) p += x[0];
        for (int i = 0; i < n; ++i) p += x[1];
        for (int i = 0; i < n; ++i) p += x[2];
        if(p.find(s) == string::npos and p.find(t) == string::npos) 
            return cout << "YES\n" << p << "\n",0;
    } while(next_permutation(x.begin(), x.end()));

    for (auto x: v) {
        string p = "";
        for (int i = 0; i < n; ++i) 
            p += x;

        if(p.find(s) == string::npos and p.find(t) == string::npos) 
            return cout << "YES\n" << p << "\n",0;
    }
    cout << "NO\n";
    return 0;
}

