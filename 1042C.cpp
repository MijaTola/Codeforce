#include <bits/stdc++.h>

using namespace std;

vector<int> pos;
vector<int> neg;
vector<int> zer;
vector<pair<int,int> > nn;
int main() {
    int n;
    scanf("%d", &n);
    int zeros = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        if(x > 0) pos.push_back(i + 1);
        if(x < 0) nn.push_back(make_pair(x,i));
        if(x == 0) {
            zeros++;
            zer.push_back(i + 1);
        }
    }
    sort(nn.rbegin(),nn.rend());
    for (int i = 0; i < (int)nn.size(); ++i)
        neg.push_back(nn[i].second + 1);
    
    if(zeros > 1) {
        int p = zer[0];
        for (int i = 0; i < (int)zer.size(); ++i) 
            if(zer[i] != p)cout << 1 << " " << zer[i] << " " << p << "\n";
        zeros = 1;
        zer.clear();
        zer.push_back(p);
        if(pos.size() == 0 and neg.size() == 0) return 0;
    }
    bool flag = 0;
    if(zeros and (int)neg.size() % 2 != 0) {
        cout << 1 << " " << neg[0] << " " << zer[0] << "\n";
        vector<int> h = neg;
        neg.clear();
        for (int i = 1; i < (int)h.size(); ++i)
            neg.push_back(h[i]);
        if(zeros == 1 and neg.size() == 0 and pos.size() == 0) 
            return 0;
    }
    
    if(zeros == 1 and (int) neg.size() % 2 == 0) {
        cout << 2 << " " << zer[0] << "\n";
        int p = -1;
        if(pos.size())p = pos[0];
        else p = neg[0];
        for (int i = 0; i < (int)pos.size(); ++i) 
            if(pos[i] != p) cout << 1 << " " << pos[i] << " " << p << "\n";
        
        for (int i = 0; i < (int)neg.size(); ++i) 
            if(neg[i] != p) cout << 1 << " " << neg[i] << " " << p << "\n";
        return 0;
    }

    if(zeros == 0 and (int) neg.size() % 2 != 0) {
        cout << 2 << " " << neg[0] << "\n";
        int p = -1;
        if(pos.size()) p = pos[0];
        else p = neg[1];
        for (int i = 0; i < (int)pos.size(); ++i) 
            if(pos[i] != p)cout << 1 << " " << pos[i] << " " << p << "\n";
        
        for (int i = 1; i < (int)neg.size(); ++i) 
            if(neg[i] != p) cout << 1 << " " << neg[i] << " " << p << "\n";
        return 0;
    }
    
    if(zeros == 0 and (int) neg.size() % 2 == 0) {
         for (int i = 0; i < (int)pos.size(); ++i) 
            if(pos[i] != 1) cout << 1 << " " << pos[i] << " " << 1 << "\n";
        
        for (int i = 0; i < (int)neg.size(); ++i) 
            if(neg[i] != 1) cout << 1 << " " << neg[i] << " " << 1 << "\n";

        for (int i = 0; i < (int)zer.size(); ++i) 
            if(zer[i] != 1) cout << 1 << " " << zer[i] << " " << 1 << "\n";
        return 0;
    }

    return 0;
}

