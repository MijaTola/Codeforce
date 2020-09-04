#include <bits/stdc++.h>

using namespace std;

bool p[1010];
vector<int> primes;

void build() {
    for (int i = 2; i * i < 1010; ++i) {
        for (int j = i + i; j < 1010; j += i) {
            p[j] = 1;
        }
    }

    for (int i = 2; i < 1010; ++i)
        if(!p[i]) primes.push_back(i);
}

vector<pair<int,int> > ans;

int main() {

    build();


    int x;
    cin >> x;

    int cur = -1;
    for (int y: primes) {
        if(y - x > 0 and !p[y - x + 2]) {
            cur = y - x;
            break;
        }
    }
    if(cur == -1) return cout << "-1\n",0;
    for (int i = 0; i < x; i++)
        ans.push_back({i, (i + 1) % x});
    
    for (int i = 0; i < cur; ++i) {
        ans.push_back({0, i + 2});
    }
    cout << ans.size() << "\n";
    for (auto p: ans)
        cout << p.first + 1<< " " << p.second + 1 << "\n";
    return 0;
}

