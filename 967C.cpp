#include <bits/stdc++.h>

using namespace std;

vector<int> ds,de;

pair<int,int> bs(int x) {
    int a = 0;
    int b = ds.size() - 1;
    //stairs
    int s;
    if(ds.size() != 0)  {
        while(b - a > 1) {
            int mid = (a + b) >> 1;
            if(ds[mid] >= x) b = mid;
            else a = mid;
        }
        if(abs(ds[b] - x) < abs(ds[a] - x)) s = b;
        else s = a;
    } else s = -1;
    a = 0;
    b = de.size() - 1;
    //elevators;

    int e;
    if(de.size() != 0) {
        while(b - a > 1) {
            int mid = (a + b) >> 1;
            if(de[mid] >= x) b = mid;
            else a = mid;
        }

        if(abs(de[b] - x) < abs(de[a] - x)) e = b;
        else e = a;
    } else e = -1;
    
    int s1 = -1;
    int e1 = -1;
    if(s != -1) s1 = ds[s];
    if(e != -1) e1 = de[e];
    return make_pair(s1,e1);
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n,m,s,e,v;
    cin >> n >> m >> s >> e >> v;

    for (int i = 0; i < s; ++i) {
        int x; cin >> x;
        ds.push_back(x);
    }

    for (int i = 0; i < e; ++i) {
        int x; cin >> x;
        de.push_back(x);
    }

    int q; cin >> q;

    while(q--) {
        int x,y,a,b;
        cin >> x >> y >> a >> b;
        pair<int,int> p = bs((y + b) / 2);
        //pair<int,int> p2 = bs(b);
        //pair<int,int> p3 = bs((y + b) / 2);
        long long d1 = 0;
        long long cs = p.first;
        long long ce = p.second;
        d1 = abs(cs - y) + abs(cs - b) + abs(x - a);

        long long plane = LLONG_MAX;
        if(x == a) {
            plane = abs(y - b );
        }
        if(cs == -1) d1 = LLONG_MAX;

        long long d2 = 0;
        int up = abs(x - a) / v;
        if(abs(x - a) % v != 0) up++;
        d2 = abs(ce - y) + abs(ce - b) + up;
        if(ce == -1) d2 = LLONG_MAX;
/*
        long long d3 = 0;
        cs = p2.first;
        ce = p2.second;
        d3 = abs(cs - y) + abs(cs - b) + abs(x - a);
        
        if(cs == -1) d3 = LLONG_MAX;

        long long d4 = 0;
        up = abs(x - a) / v;
        if(abs(x - a) % v != 0) up++;
        d4 = abs(ce - y) + abs(ce - b) + up;
        if(cs == -1) d4 = LLONG_MAX;
         
        long long d5 = 0;
        cs = p3.first;
        ce = p3.second;
        d5 = abs(cs - y) + abs(cs - b) + abs(x - a);
        
        if(cs == -1) d5 = LLONG_MAX;

        long long d6 = 0;
        up = abs(x - a) / v;
        if(abs(x - a) % v != 0) up++;
        d6 = abs(ce - y) + abs(ce - b) + up;
        if(cs == -1) d6 = LLONG_MAX;*/
        
        //long long ans = min(min(min(d1,d2),min(d3,d4)),min(d5,d6));
        cout << min(min(d1,d2),plane) << "\n";
    }
    return 0;
}

