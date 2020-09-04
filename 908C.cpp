#include <bits/stdc++.h>

using namespace std;

vector<double> v;
vector<double> ans;

double distance(double x, double y, double a, double b) {
    return sqrt((x - a)*(x - a) + (y - b) * (y - b));
}
int main(){
    int n, r;
    scanf("%d %d", &n, &r);

    while(n--) {
        int x;
        scanf("%d", &x);
        bool found = 0;
        double cur = 0.0;
        for (int i = v.size() - 1; i >= 0; i--){
            if(abs(x - v[i]) <= 2 * r) {
                double a = ans[i];
                double b = 10000000;
                double dx = v[i];
                double dy = ans[i];
                while(b - a > 0.000000001) {
                    double mid = (a + b) / 2.0;
                    double dist = distance(dx,dy,x,mid);
                    if(dist >= 2.0 * r) b = mid;
                    else a = mid;
                }
                cur = max(cur,b);
                found = 1;
            }
        }
        if(!found) {
            cur = r;
        }
        ans.push_back(cur);
        v.push_back(x);
    }

    for  (int i = 0; i < (int)ans.size(); ++i) {
        printf("%.11lf ", ans[i]);
    }
    return 0;
}
