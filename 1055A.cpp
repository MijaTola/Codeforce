#include <bits/stdc++.h>

using namespace std;

int a[1010];
int b[1010];

int main() {
    int n,s;
    cin >> n >> s;

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i < n; ++i)
        cin >> b[i];
    s--;
    if(a[0]) {
        for (int i = 0; i < n; ++i) {
            if(i == s and a[i]) return cout << "YES\n",0;
            if(b[i] and a[i]) {
                for (int j = i; j >= 0; j--) 
                    if(j == s and b[j]) return cout << "YES\n",0;
            }
        }
    } else if(s == 0) return puts("YES");
    puts("NO");
    return 0;
}

