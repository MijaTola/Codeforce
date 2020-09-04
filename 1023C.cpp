#include <bits/stdc++.h>

using namespace std;

int v[200010];
int main(){
    
    int n,k;
    cin >> n >> k;
    string s; cin >> s;
        
    stack<int> st;
    for (int i = 0; i < (int)s.size(); ++i) {
        if(s[i] == '(') st.push(i);
        else {
            int pos = st.top();
            v[pos] = i;
            st.pop();
        }
    }
    
    int p = 0;
    while(k and p < n) {
        int ini = p;
        int fin = v[p];
        int total = fin - ini + 1;
        if(total > k) {
            p++;
            continue;
        }
        k -= total;
        for (int i = ini; i <= fin; ++i)
            cout << s[i];
        p += total;
    }
    cout << "\n";
    return 0;
}

