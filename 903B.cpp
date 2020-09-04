#include <bits/stdc++.h>

using namespace std;

int h1,a1,c1,h2,a2;

string s[] = {"STRIKE", "HEAL"};
int main() {

    cin >> h1 >> a1 >> c1 >> h2 >> a2;
    
    vector<int> ans;

    while(h2 > 0) {
        if(h2 - a1 <= 0) {
            ans.push_back(0);
            break;
        } else if(h1 - a2 > 0) {
            h2 -= a1;
            h1 -= a2;
            ans.push_back(0);
        } else {
            h1 += c1;
            h1 -= a2;
            ans.push_back(1);
        }
    }

    cout << ans.size() << "\n";

    for (int x: ans)
        cout << s[x] << "\n";
    return 0;
}
