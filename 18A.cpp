#include <bits/stdc++.h>

using namespace std;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int x[4]; int y[4];
bool ver(int a,int b,int c){
	if(a == 0 || b == 0 || c == 0) return false;
    if(a == b + c || b == a + c || c == a + b) return true;
    else return false;
}
int dist(int x1,int x2,int y1,int y2){
	return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	for (int i = 1; i <= 3; ++i)
		cin >> x[i] >> y [i];

	int a = dist(x[1],x[2],y[1],y[2]);
	int b = dist(x[2],x[3],y[2],y[3]);
	int c = dist(x[1],x[3],y[1],y[3]);

	if(ver(a,b,c)){cout << "RIGHT"; return 0;}

	for (int i = 1; i <= 3; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			int t = x[i]+dx[j];
			int r = y[i]+dy[j];
			if(i == 1){
				 a = dist(t,x[2],r,y[2]);
				 b = dist(x[2],x[3],y[2],y[3]);
				 c = dist(t,x[3],r,y[3]);
			}else if(i == 2){
				 a = dist(x[1],t,y[1],r);
				 b = dist(t,x[3],r,y[3]);
				 c = dist(x[1],x[3],y[1],y[3]);
			}else if(i == 3){
				 a = dist(x[1],x[2],y[1],y[2]);
				 b = dist(x[2],t,y[2],r);
				 c = dist(x[1],t,y[1],r);
			}
			if(ver(a,b,c)){cout << "ALMOST"; return 0;}
		}
	}
	cout << "NEITHER";
	return 0;
}