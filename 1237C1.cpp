#include <bits/stdc++.h>

using namespace std;

vector<pair<pair<int,int>, int> > v;
set<pair<int,int> > sx,sy,sz;
vector<pair<int,int> > ans;
bool vis[50010];

long long dis(pair<pair<int,int>, int> a, pair<pair<int,int>, int> b) {
    return abs(a.first.first - b.first.first) + abs(a.first.second - b.first.second) + abs(a.second - b.second);
}


int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x,y,z;
        cin >> x >> y >> z;
        v.push_back({{x,y}, z});
        sx.insert({x, i});
        sy.insert({y, i});
        sz.insert({z, i});
    }
    
    for (int i = 0; i < n; ++i) {
        if(vis[i]) continue;
        auto x = sx.lower_bound({v[i].first.first, i});
        auto l = sx.lower_bound({v[i].first.first, i});
        auto r = sx.lower_bound({v[i].first.first, i});
        l--,r++;
        
        int flag = 0;
        long long a1 = 1e10;

        if((*l).first != n and dis(v[(*x).second], v[(*l).second]) < a1) {
            flag = -1;
            a1 = dis(v[(*x).second], v[(*l).second]);
        }
        
        if((*r).first != n and dis(v[(*x).second], v[(*r).second]) < a1) {
            flag = 1;
            a1 = dis(v[(*x).second], v[(*r).second]);
        }

        auto xy = sy.lower_bound({v[i].first.second, i});
        auto ly = sy.lower_bound({v[i].first.second, i});
        auto ry = sy.lower_bound({v[i].first.second, i});
        ly--,ry++;

        int flagy = 0;
        long long a2 = 1e10;

        if((*ly).first != n and dis(v[(*xy).second], v[(*ly).second]) < a2) {
            flagy = -1;
            a2 = dis(v[(*xy).second], v[(*ly).second]);
        }

        if((*ry).first != n and dis(v[(*xy).second], v[(*ry).second]) < a2) {
            flagy = 1;
            a2 = dis(v[(*xy).second], v[(*ry).second]);
        }

        auto xz = sy.lower_bound({v[i].second, i});
        auto lz = sy.lower_bound({v[i].second, i});
        auto rz = sy.lower_bound({v[i].second, i});
        lz--,rz++;

        int flagz = 0;
        long long a3 = 1e10;

        if((*lz).first != n and dis(v[(*xz).second], v[(*lz).second]) < a3) {
            flagz = -1;
            a3 = dis(v[(*xz).second], v[(*lz).second]);
        }

        if((*rz).first != n and dis(v[(*xz).second], v[(*rz).second]) < a2) {
            flagz = 1;
            a3 = dis(v[(*xz).second], v[(*rz).second]);
        }
        
        if(a1 <= a2 and a1 <= a3) {
            if(flag == -1) {
                vis[((*x).second)] = 1;
                vis[((*l).second)] = 1;
                ans.push_back({(*x).second, (*l).second});
                sx.erase(x);
                sy.erase({v[(*x).second].first.second, i});
                sz.erase({v[(*x).second].second, i});
                sx.erase(l);
                sy.erase({v[(*l).second].first.second, i});
                sz.erase({v[(*l).second].second, i});
            } else {
                vis[((*x).second)] = 1;
                vis[((*r).second)] = 1;
                ans.push_back({(*x).second, (*r).second});
                sx.erase(x);
                sy.erase({v[(*x).second].first.second, i});
                sz.erase({v[(*x).second].second, i});
                sx.erase(r);
                sy.erase({v[(*r).second].first.second, i});
                sz.erase({v[(*r).second].second, i});

            }
            continue;
        }

        if(a2 <= a1 and a2 <= a3) {
            if(flagy == -1) {
                vis[((*xy).second)] = 1;
                vis[((*ly).second)] = 1;
                ans.push_back({(*xy).second, (*ly).second});
                sx.erase(xy);
                sy.erase({v[(*xy).second].first.second, i});
                sz.erase({v[(*xy).second].second, i});
                sx.erase(ly);
                sy.erase({v[(*ly).second].first.second, i});
                sz.erase({v[(*ly).second].second, i});
            } else {
                vis[((*xy).second)] = 1;
                vis[((*ry).second)] = 1;
                ans.push_back({(*xy).second, (*ry).second});
                sx.erase(xy);
                sy.erase({v[(*xy).second].first.second, i});
                sz.erase({v[(*xy).second].second, i});
                sx.erase(ry);
                sy.erase({v[(*ry).second].first.second, i});
                sz.erase({v[(*ry).second].second, i});
            }
            //cout << "hre\n";
            //return 0;
            continue;
        }

        if(a3 <= a1 and a3 <= a2) {
            if(flagz == -1) {

                vis[((*xz).second)] = 1;
                vis[((*lz).second)] = 1;
                ans.push_back({(*xz).second, (*lz).second});
                sx.erase(xz);
                sy.erase({v[(*xz).second].first.second, i});
                sz.erase({v[(*xz).second].second, i});
                sx.erase(lz);
                sy.erase({v[(*lz).second].first.second, i});
                sz.erase({v[(*lz).second].second, i});
            } else {
                vis[((*xz).second)] = 1;
                vis[((*rz).second)] = 1;
                ans.push_back({(*xz).second, (*rz).second});
                sx.erase(xz);
                sy.erase({v[(*xz).second].first.second, i});
                sz.erase({v[(*xz).second].second, i});
                sx.erase(rz);
                sy.erase({v[(*rz).second].first.second, i});
                sz.erase({v[(*rz).second].second, i});
            }
            continue;
        }

    }
    
    for (auto a: ans)
        cout << a.first + 1 << " " << a.second + 1 << "\n";
    return 0;
}

