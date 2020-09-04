#include <bits/stdc++.h>

using namespace std;

int main() {

    int l;
    cin >> l;   

    stack<pair<int, long long> > s;
    s.push({1, 0});
    bool flag = 1;

    while(l--) {
        string c;
        cin >> c;
        
        flag &= s.top().second < ((1LL << 32));
        
        if(c == "add")  {
            auto p = s.top();
            s.pop();
            s.push({p.first, p.second + p.first});
        }

        if(c == "for") {
            int x;
            cin >> x;
            s.push({x, 0});
        }

        if(c == "end") {
            auto p = s.top();
            s.pop();
            auto pp = s.top();
            s.pop();
            s.push({pp.first, pp.second + pp.first * p.second});
        }
    }
    if(flag and s.top().second < ((1LL << 32) ))cout << s.top().second << "\n";
    else cout << "OVERFLOW!!!\n";
    return 0;
}
