#include <bits/stdc++.h>

using namespace std;

int parents[30];
void init(){
	for (int i = 0; i < 30; ++i)
		parents[i] = i;
}

int find(int x){
	if(parents[x] == x) {
        return x;
    }
	else return parents[x] = find(parents[x]);
}

bool sameC(int x,int y){
	return find(x) == find(y);
}

void Union(int x,int y){
	int px = find(x);
	int py = find(y);
    parents[px] = py;
}

set<pair<int,int> > ans;
int main(){
    int n; cin >> n;
    string a,b;
    cin >> a >> b;
    init();
    for (int i = 0; i < n; ++i) {
        int da = a[i] - 'a';
        int db = b[i] - 'a';
        if(a[i] == b[i]) continue;
        if(!sameC(da,db)) {
            Union(da,db);
            ans.insert({max(da,db),min(da,db)});
        }
    }   
    cout << ans.size() << "\n";
    for (pair<int,int> s: ans)
        cout << (char)(s.first + 'a') << " " << (char)(s.second + 'a') << "\n";
    return 0;
}

