#include <bits/stdc++.h>

using namespace std;

int n;
vector<tuple<int,int,int,int> > v,b,s;
vector<tuple<int,int> > ans;

long long dis(int i, int j) {
    int a = abs(get<0>(s[i]) - get<0>(s[j]));
    int b = abs(get<1>(s[i]) - get<1>(s[j]));
    int c = abs(get<2>(s[i]) - get<2>(s[j]));
    return a + b + c;

}
bool cmp(tuple<int,int> a, tuple<int,int> b) {
    return dis(get<0>(a), get<1>(a)) <  dis(get<0>(b), get<1>(b));
}

int main() {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x,y,z;
        cin >> x >> y >> z;
        v.emplace_back(x,y,z,i);
        s.emplace_back(x,y,z,i);
    }
    
    sort(v.begin(), v.end());
    
    int pos = 0;
    while(pos < n) {
        if(get<0>(v[pos]) == get<0>(v[pos + 1])) ans.emplace_back(get<3>(v[pos]), get<3>(v[pos + 1])), pos += 2;
        else b.emplace_back(get<1>(v[pos]), get<2>(v[pos]), get<0>(v[pos]), get<3>(v[pos])), pos++;
    }


    v = b;
    b.clear();
    sort(v.begin(), v.end());
    pos = 0;
    while(pos < (int)v.size()) {
        if(get<0>(v[pos]) == get<0>(v[pos + 1])) ans.emplace_back(get<3>(v[pos]), get<3>(v[pos + 1])), pos += 2;
        else b.emplace_back(get<1>(v[pos]), get<2>(v[pos]), get<0>(v[pos]), get<3>(v[pos])), pos++;
    }

    v = b;
    b.clear();
    sort(v.begin(), v.end());
    pos = 0;
    while(pos < (int)v.size()) {
        if(get<0>(v[pos]) == get<0>(v[pos + 1])) ans.emplace_back(get<3>(v[pos]), get<3>(v[pos + 1])), pos += 2;
        else b.emplace_back(get<1>(v[pos]), get<2>(v[pos]), get<0>(v[pos]), get<3>(v[pos])), pos++;
    }

    for (int i = 1; i < (int)b.size(); ++i) 
        ans.emplace_back(get<3>(v[i - 1]), get<3>(v[i]));
    
    sort(ans.begin(), ans.end(), cmp);
    for (auto tp: ans) 
        cout << get<0>(tp) + 1 << " " << get<1> (tp) + 1 << "\n";
        

    return 0;
}

