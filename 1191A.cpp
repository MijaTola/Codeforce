#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    map<int, char> cat;

    cat[1] = 'A';
    cat[3] = 'B';
    cat[2] = 'C';
    cat[0] = 'D';

    vector<pair<char, int> > v;
    for (int i = 0; i <= 2; ++i) {
        v.emplace_back(cat[(n + i) % 4], i);
    }

    sort(v.begin(), v.end());

    cout << v[0].second << " " << v[0].first << "\n";

    return 0;
}

