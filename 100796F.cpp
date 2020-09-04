#include <iostream>

using namespace std;
typedef long long ll;
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		double x,y;
		scanf("%lf %lf",&x,&y);
		x--;
		double a = x/(x+1);
		double b = y/(y+1);
		double ans = b-a;
		printf("%.12lf \n",ans);
	}
	return 0;
}
