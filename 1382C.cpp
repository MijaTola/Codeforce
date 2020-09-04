#include <bits/stdc++.h>

using namespace std;

void task1() {
    int n;
    string s,t;
    cin >> n >> s >> t;


    int pos = n - 1;

    auto flip = [&] (int r) {
        for (int i = 0; i <= r; ++i) {
            if(s[i] == '1') s[i] = '0';
            else s[i] = '1';
        }
        reverse(s.begin(), s.begin() + r + 1);
    };

    vector<int> ans;
    while(pos >= 0) {
        if(t[pos] != s[0]) {
            ans.push_back(pos);
            flip(pos);
        } else {
            ans.push_back(0);
            flip(0);
            ans.push_back(pos);
            flip(pos);
        }
        pos--;
    }

    cout << ans.size() << " ";
    for (int x: ans)
        cout << x + 1 << " ";
    cout << "\n";
}

void task2() {
    int n;
    string s,t;
    cin >> n >> s >> t;

    int pos = n - 1;

    vector<int> ans;

    bool turn = 0;
    int l = 0;
    int r = n - 1;

    while(pos >= 0) {
        if(!turn) {
            char val = s[l];
            if(t[pos] != val) {
                ans.push_back(pos);
            } else {
                ans.push_back(0);
                ans.push_back(pos);
            }
            turn = 1 - turn;
            l++;
        } else {
            char val = s[r] == '1' ? '0' : '1';
            if(t[pos] != val) {
                ans.push_back(pos);
            } else {
                ans.push_back(0);
                ans.push_back(pos);
            }
            turn = 1 - turn;
            r--;
        }
        pos--;
    }

    cout << ans.size() << " ";
    for (int x: ans)
        cout << x + 1 << " ";
    cout << "\n";
}
int main() {

    int t;
    cin >> t;

    while(t--) {
        task2();
    }
    return 0;
}

