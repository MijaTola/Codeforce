#include <bits/stdc++.h>

using namespace std;

char ans[110];
int main() {
    int n; 
    cin >> n;
    vector<pair<string,int> > v;
    vector<string> bi;
    for (int i = 0; i < 2 * n - 2; ++i) {
        string x;
        cin >> x;
        v.push_back({x,i});
        if((int)x.size() == n - 1)
            bi.push_back(x);
    }

    vector<pair<string,int> > a;
    vector<pair<string,int> > b;
    unordered_set<string> s;
    for (int i = 0; i < 2 * n - 2; ++i) {
        bool flag = 1;
        for (int j = 0; j < (int)v[i].first.size(); ++j) {
            flag &= v[i].first[j] == bi[0][j];
        }

        if(flag and !s.count(v[i].first)) {
            a.push_back(v[i]);
            s.insert(v[i].first);
        }else b.push_back(v[i]);
    }

    if((int)a.size() == (2 * n - 2) / 2) {
        string total = bi[0] + bi[1][bi[1].size() - 1];
        if(total.find(bi[0]) == string::npos or total.find(bi[1]) == string::npos) goto go;
        bool flag = 1;

        int p = total.size() - 1;
        for (int i = bi[1].size() - 1; i >= 0; i--) {
            flag &= total[p] == bi[1][i];
            p--;
        }

        char ss = 'S';
        char pp = 'P';
        if(!flag) {
            ss = 'P';
            pp = 'S';
        }
        for (int i = 0; i < (int)a.size(); ++i) 
            ans[a[i].second] = pp;

        for (int i = 0; i < (int)b.size(); ++i) 
            ans[b[i].second] = ss;

        for (int i = 0; i < 2 * n - 2; ++i)
            cout << ans[i];
        cout << "\n";
        return 0;
    }
    go:
    a.clear();
    b.clear();
    s.clear();
    
    swap(bi[0],bi[1]);
    for (int i = 0; i < 2 * n - 2; ++i) {
        bool flag = 1;
        for (int j = 0; j < (int)v[i].first.size(); ++j) {
            flag &= v[i].first[j] == bi[0][j];
        }

        if(flag and !s.count(v[i].first)) {
            a.push_back(v[i]);
            s.insert(v[i].first);
        }else b.push_back(v[i]);
    }

    if((int)a.size() == (2 * n - 2) / 2) {
        string total = bi[0] + bi[1][bi[1].size() - 1];
    

        bool flag = 1;

        int p = total.size() - 1;
        for (int i = bi[1].size() - 1; i >= 0; i--) {
            //cout << total[p] << " " << bi[1][i] << " ||||\n";
            flag &= total[p] == bi[1][i];
            p--;
        }

        char ss = 'S';
        char pp = 'P';
        if(!flag) {
            ss = 'P';
            pp = 'S';
        }
        for (int i = 0; i < (int)a.size(); ++i) 
            ans[a[i].second] = pp;

        for (int i = 0; i < (int)b.size(); ++i) 
            ans[b[i].second] = ss;

        for (int i = 0; i < 2 * n - 2; ++i)
            cout << ans[i];
        cout << "\n";
    }
    return 0;
}

