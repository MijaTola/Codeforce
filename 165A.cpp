#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int x[205],y[205]; 	
	for (int i = 0; i < n; ++i)
		cin >> x[i] >> y[i];
	int ans = 0;
	bool u,d,r,l;
	for (int f = 0; f < n; ++f)
	{
		u=false; d=false; r=false; l=false;
        for(int f1=0;f1<n;f1++)
        {
            if ((x[f1]>x[f])&&(y[f1]==y[f])) r=true;
            if ((x[f1]<x[f])&&(y[f1]==y[f])) l=true;
            if ((x[f1]==x[f])&&(y[f1]>y[f])) u=true;
            if ((x[f1]==x[f])&&(y[f1]<y[f])) d=true;
        }
        if ((u==d)&&(d==l)&&(l==r)&&(r==true)) ans++;
	}

	cout << ans << endl;
	return 0;
}