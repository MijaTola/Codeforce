#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

set<int> s;
pair<int,int>  v[1010];

int main(){

        int n; cin >> n;

        for (int i = 0; i < n; ++i){
                int x; cin >> x;
                v[i] = {x,i};
        }

        sort(v,v+n);

        int d = v[n-1].first - v[0].first;
		
        if(d == 0) return  cout << "Exemplary pages." << endl,0;
        
     //  cout << v[n-1].first << " " << v[0].first << " " << d << endl;y
        v[n-1].first -= d/2;
        v[0].first += d/2;
      //  cout << v[n-1].first << " " << v[0].first << " " << d << endl;
        for (int i = 0; i < n; ++i){
			s.insert(v[i].first);
		}
        if(s.size() > 1) return cout << "Unrecoverable configuration." << endl,0;
        cout << d/2 << " ml. from cup #"<< v[0].second+1 << " to cup #"<< v[n-1].second+1 << "."<< endl;

        return 0;
}

