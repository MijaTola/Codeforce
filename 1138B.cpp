#include <bits/stdc++.h>

using namespace std;

int n;
string x,y;
vector<int> a,b,c,d;

int main() {
    cin >> n >> x >> y;
    
    for (int i = 0; i < n; ++i) {
        if(x[i] != y[i] and x[i] == '1') a.push_back(i);
        if(x[i] != y[i] and y[i] == '1') b.push_back(i);
        if(x[i] == y[i] and y[i] == '1') c.push_back(i);
        if(x[i] == y[i] and y[i] == '0') d.push_back(i);
    }
    
    
    return 0;
}
