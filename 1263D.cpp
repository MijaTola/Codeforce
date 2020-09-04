#include <bits/stdc++.h>

using namespace std;

string x;
int p[2000000];

void ini() {
    for (int i = 0; i < 2000000; ++i) {
        p[i] = i;
    }
}

int find(int x) {return p[x] == x ? x : p[x] = find(p[x]);}

void merge(int x, int y) {p[find(y)] = find(x);}


int main() {
    ini();
    int n;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        cin >> x;
        for (char c: x) {
            int val = (c - 'a') + 200010;
            merge(val, i);
        }
    }

    set<int> ans;

    for (int i = 0; i < n; ++i) {
        ans.insert(find(i));
    }
    cout << ans.size() << "\n";
    return 0;
}

