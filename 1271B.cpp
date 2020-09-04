#include <bits/stdc++.h>

using namespace std;

int n;
string s;
int v[210];

int main() {
    cin >> n >> s;
     
    vector<int> ans;

    for (int i = 0; i < n; ++i) 
        v[i] = s[i] == 'B';

    for (int i = 0; i < n - 1; ++i) 
        if(!v[i]) {
            v[i] = 1 - v[i], v[i + 1] = 1 - v[i + 1];
            ans.push_back(i);
        }
    
    int a = 0, b = 0;
    for (int i = 0; i < n; ++i)
        if(v[i]) a++;
        else b++;

    if(a % 2 == 0) {
        for (int i = 0; i < a; i += 2) {
            ans.push_back(i);
            v[i] = 1 - v[i], v[i + 1] = 1 - v[i + 1];
        }
        
        cout << ans.size() << "\n";
        for (int x: ans)
            cout << x + 1<< " ";
        cout << "\n";
        return 0;
    } 

    if(b % 2 == 0) {
        for (int i = a; i < n; i += 2) {
            v[i] = 1 - v[i], v[i + 1] = 1 - v[i + 1];
            ans.push_back(i);
        }

        cout << ans.size() << "\n";

        for (int x: ans)
            cout << x + 1<< " ";
        cout << "\n";
        
        return 0;
    }
    cout << "-1\n";
    return 0;
}

