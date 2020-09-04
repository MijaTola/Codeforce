#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <climits>
#include <map>
#include <set>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <deque>
#include <string> 
#include <sstream>
#include <cstdlib>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main() {
    string s; cin >> s;
    int freq = 1;
    int used = 0;
    putchar(s[0]);
    for (int i = 1; i < s.size(); i++) {
        if (s[i-1] == s[i]) {
            freq++;
            if (used <= 0 && freq == 2) {
                used = 2;
                cout << s[i];
            }
        }
        else {
            freq = 1;
            used--;
            cout << s[i];
        }
    }
    cout << "\n";
    return 0;
}
