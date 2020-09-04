#include <bits/stdc++.h>

using namespace std;

int A[200010];
int main(){
    
    string x; cin >> x;
    stack<char> t;
    
    A[x.size() - 1] = x[x.size() - 1] - 'a';

    for (int i = x.size() - 2; i >= 0; i--) 
        A[i] = min(A[i + 1], x[i] - 'a');
    
    string u = "";
    int pos = 0;
    for (int i = 0; i < (int)x.size(); ++i) {
        int cur = x[i] - 'a';
        while(!t.empty() and t.top() <= (char)(A[i] + 'a')) {
            u += t.top();
            t.pop();
        }
        if(cur == A[i]) {
            u += x[i];
        } else t.push(x[i]);
    }
    while(!t.empty()) {
        u += t.top();t.pop();
    }
    cout << u << "\n";
    return 0;
}
