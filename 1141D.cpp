#include <bits/stdc++.h>

using namespace std;

int n;
string a,b;
queue<int> da[256];
queue<int> db[256];

int main() {
    cin >> n >> a >> b;

    for (int i = 0; i < n; ++i) {
        da[a[i]].push(i);
        db[b[i]].push(i);
    }

    vector<pair<int,int> > ans;
    for (char i = 'a'; i <= 'z'; i++) {
        while(!da[i].empty() and !db[i].empty()) {
            ans.push_back({da[i].front(),db[i].front()});
            da[i].pop();
            db[i].pop();
        }
    }

    for (char i = 'a'; i <= 'z'; i++) {
        while(!da[i].empty() and !db['?'].empty()) {
            ans.push_back({da[i].front(),db['?'].front()});
            da[i].pop();
            db['?'].pop();
        }

        while(!da['?'].empty() and !db[i].empty()) {
            ans.push_back({da['?'].front(),db[i].front()});
            da['?'].pop();
            db[i].pop();
        }
    }
    while(!da['?'].empty() and !db['?'].empty()) {
            ans.push_back({da['?'].front(),db['?'].front()});
            da['?'].pop();
            db['?'].pop();
        }
    cout << ans.size() << "\n";

    for (pair<int,int> p: ans)
        cout << p.first + 1<< " " << p.second + 1<< "\n";
    return 0;
}

