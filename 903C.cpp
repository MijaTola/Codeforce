#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> v(n);

    for (int &x: v)
        cin >> x;

    sort(v.begin(), v.end());

    vector<int> b;

    for (int i = v.size() - 1; i >= 0; i--) {
        bool flag = 0;
        for (int j = 0; j < (int) b.size(); ++j) {
            if(v[i] < b[j]) {
                b[j] = v[i];
                flag = 1;
                break;
            }
        }
        if(!flag) b.push_back(v[i]);
    }

    cout << b.size() << "\n";
    return 0;
}

