#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;
    while(t--) {
        string x,y;
        cin >> x >> y;
        if((int)x.size() < (int)y.size()) swap(x,y);
        vector<int> a,b;
        int dif = x.size() - y.size();
        for (int i = 0; i < (int)x.size(); ++i)
            if(x[i] == '1') a.push_back(i);

        for (int i = 0; i < (int)y.size(); ++i)
            if(y[i] == '1') b.push_back(i + dif);
    
        while(a.back() > b.back()) a.pop_back();
        
        cout << b.back() - a.back() << "\n";

    }
    return 0;
}

