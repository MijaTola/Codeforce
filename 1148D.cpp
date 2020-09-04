#include <bits/stdc++.h>

using namespace std;

vector<pair<pair<int,int>, int > > v,b;

int main() {


    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x,y;
        cin >> x >> y;
        if(x < y) v.push_back({{x,y}, i});
        else b.push_back({{x,y}, i});
    }

    if(n == 1) {
        cout << "1\n1\n";
        return 0;
    }
    sort(v.rbegin(), v.rend());
    sort(b.begin(), b.end());

    int last = 0;
    int id = 0;
    int mx = 0;
    int c = 1;

    for (int i = 1; i < (int)v.size(); ++i) {
        if(v[i].first.first < v[i - 1].first.second) c++;
        else {
            if(c > mx) {
                mx = c;
                id = last;
            }
            c = 1;
            last = i;
        }
    }

    if(c > mx) {
        mx = c;
        id = last;
    }

    int mx1 = 0;
    c = 1;
    last = 0;

    for (int i = 1; i < (int)b.size(); ++i) {
        if(b[i].first.first > b[i - 1].first.second) c++;
        else {
            if(c > mx1) {
                mx1 = c;
                id = last;
            }
            c = 1;
            last = i;
        }
    }

    if(c > mx1) {
        mx1 = c;
        id = last;
    }

    if(mx > mx1) {
        cout << mx << "\n";
        for (int i = id; i < id + mx; ++i)
            cout << v[i].second + 1 << " ";
        cout << "\n";
    } else {
        cout << mx1 << "\n";
        for (int i = id; i < id + mx1; ++i)
            cout << b[i].second + 1 << " ";
        cout << "\n";

    }
    return 0;
}

