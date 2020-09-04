#include <bits/stdc++.h>

using namespace std;

char v[] = {'a', 'e', 'i', 'o', 'u'};
int main() {
    int k;
    cin >> k;
    
    int a = -1, b = -1;
    for (int i = 5; i <= k; ++i)
        for (int j = 5; j <= k; ++j)
            if(i * j == k) {
                a = i;
                b = j;
                break;
            }

    if(a == -1 or b == -1) return cout << "-1\n",0;
    
    int ini = -1;
    for (int i = 0; i < a; ++i) {
        int cur = (ini + 1) % 5;;
        ini++;
        for (int j = 0; j < b; ++j) {
            cout << v[cur];
            cur = (cur + 1) % 5;
        }
    }
    cout << "\n";
    return 0;
}

