#include <bits/stdc++.h>

using namespace std;

int m[1010][1010];

int main() {


    int n;
    cin >> n;
    int ini = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            m[i][j] = ini++;
    }

    for (int j = 0; j < n; j += 2) {
        for (int i = n / 2; i < n; ++i)
            swap(m[i][j], m[i - (n / 2)][j + 1]);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << m[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
