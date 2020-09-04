#include <bits/stdc++.h>

using namespace std;

bool vis[100010];

deque<int> v,b;
int main() {
    int n;
    string s;
    cin >> n >> s;
    
    for (int i = 0; i < n; ++i) 
        if(s[i] == '8') v.push_back(i);
        else b.push_back(i);

    bool flag = 0;
    while(v.size() + b.size() > 11) {
        if(flag) {
            if(!b.empty())b.pop_front();
            else v.pop_back();
        } else {
            if(!v.empty()) v.pop_front();
            else b.pop_back();
        }
        flag = !flag;
    }

    if(!v.empty() and !b.empty() and v.front() < b.front()) {
        puts("YES");
        return 0;
    }
    if(!v.empty() and !b.empty() and v.front() > b.front()) {
        puts("NO");
        return 0;
    }
    if(v.empty()) return puts("NO"),0;
    if(b.empty() and !v.empty()) puts("YES");
    return 0;
}

