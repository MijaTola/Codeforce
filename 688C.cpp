#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> G[1000010];
int color[1000010];
vector<int> ans1;
vector<int> ans2;
queue<int> q;
int main(){
    for (int i = 0; i < 1000010; ++i) color[i] = -1;
    int n,m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i){
        int x,y; cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    
    bool flag = true;
    for (int i = 1; i <= n; ++i){
        if(color[i] == -1){
            q.push(i);
            color[i] = 0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for (int j: G[u]){
            if(color[j] == -1){
                color[j] = 1 - color[u];
                q.push(j);
            }else if(color[j] == color[u]){
                flag = false;
                break;
            }
        }
    }
        }
    }
    for (int i = 1; i <= n; ++i) 
        if(color[i] == 1) ans1.push_back(i);
        else if (color[i] == 0)  ans2.push_back(i);
    
    if(flag){
        cout << ans1.size() << endl;
        for (int i = 0; i < (int)ans1.size(); ++i) cout << ans1[i] << " ";
        cout <<endl << ans2.size() << endl;
        for (int i = 0; i < (int)ans2.size(); ++i) cout << ans2[i] << " ";
    }else cout << -1 << endl;
    return 0;
}
