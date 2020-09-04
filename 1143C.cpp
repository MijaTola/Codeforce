#include <bits/stdc++.h>

using namespace std;

int parent[100010];
int respect[100010];
int child[100010];
bool is[100010];
int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        int p,c;
        cin >> p >> c;
        parent[i] = p;
        child[p]++;
        respect[p] += c;
        is[i] = c;
    }

    priority_queue<int> q;

    vector<int> ans;
    for (int i = 1; i <= n; ++i) 
        if(is[i] and respect[i] == child[i] and parent[i] != -1) 
            ans.push_back(i);

    sort(ans.begin(), ans.end());

    if(ans.size() == 0) return puts("-1"),0;

    for (int x: ans)
        cout << x << " ";
    cout << "\n";
    return 0;
}
