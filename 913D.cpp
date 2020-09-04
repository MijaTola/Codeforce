#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int> > v;
int n,t,ans;
vector<pair<int,int> >cur;
vector<int> ansv;

bool find(int k) {
    cur.clear();
    for (int i = 0; i < n; ++i) {
        if(v[i].first >= k) {
            cur.push_back(make_pair(v[i].second,i));
        }
    }
    
    if((int)cur.size() < k){ cur.clear(); return 0;}

    sort(cur.begin(),cur.end());
    ans = 0;
    for (int i = 0; i < k; ++i){
        ans += cur[i].first;
    }
    if(ans > t){
         cur.clear();
         return 0;
    }
    ansv.clear();
    for (int i = 0; i < k; ++i) {
        ansv.push_back(cur[i].second);
    }
    return 1;
}
int main(){
    
    cin >> n >> t;

    for (int i = 0; i < n; ++i) {
        int x,y; cin >> x >> y;
        v.push_back(make_pair(x,y));
    }
    
    int a = 0;
    int b = n + 1;

    while(b - a > 1) {
        int mid = (a + b) / 2;
        if(find(mid)) a = mid;
        else b = mid;
    }
    
    cout << a << "\n";
    cout << ansv.size() << "\n";
    for (int i = 0; i < (int)ansv.size(); ++i) 
        cout << ansv[i] + 1 << " ";
    puts("");
    return 0;
}

