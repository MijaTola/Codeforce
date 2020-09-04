#include <bits/stdc++.h>

using namespace std;

vector<long long> square;
vector<pair<int,int> > sq;
vector<pair<int,int> > nsq;
int v[200010];
int a[200010];
int b[200010];

int main(){
    long long p = 0;
    while(p * p < INT_MAX) {
        square.push_back(p * p);
        p++;
    }
        
    int n;
    cin >> n;
    
    for (int i = 0; i < n; ++i) cin >> v[i];

    for (int i = 0; i < n; ++i) {
      int p=lower_bound(square.begin(),square.end(), v[i]) - square.begin();
        int mv = abs(v[i] - square[p]);
        if(p) mv = min(mv,(int)abs(v[i] - square[p - 1]));
        sq.push_back(make_pair(mv,i));
        a[i] = sq[i].first;
        if(square[p] == v[i]) {
            int cur = 0;
            while(sqrt(v[i]) * sqrt(v[i]) == v[i]){v[i]++; cur++;}
            nsq.push_back(make_pair(cur,i));
        }else nsq.push_back(make_pair(0,i));
        b[i] = nsq[i].first;
    }
    
    
    int cnt = 0;
    int cnts = 0;
    for (int i = 0; i < n; ++i) {
        cnts += sq[i].first;
        cnt += nsq[i].first;
    }
    sort(sq.begin(),sq.end());
    sort(nsq.begin(),nsq.end());
    int cur1 = 0;
    int cur2 = 0;
    int cur11 = 0;
    int cur22 = 0;
    for (int i = 0; i < n / 2; ++i) {
        cur1 += sq[i].first; //sq
        cur11 += b[sq[i].second]; //nsq
        cur2 += nsq[i].first; //nsq
        cur22 += a[nsq[i].second]; //sq
    }

    cout << cur11 << " " << cur22 << "\n";
    cur11 = abs(cnts - cur11);
    cur22 = abs(cnt - cur22);
    int ans1 = cur11 + cur1;
    int ans2 = cur22 + cur2;
    cout << min(ans1,ans2) << "\n";


    return 0;
}

