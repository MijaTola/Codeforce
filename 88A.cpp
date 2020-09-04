#include <bits/stdc++.h>

using namespace std;
int check(string s)
{
	if(s=="C")
		return 0;
	if(s=="C#")
		return 1;
	if(s=="D")
		return 2;
	if(s=="D#")
		return 3;
    if(s=="E")
		return 4;
    if(s=="F")
		return 5;
    if(s=="F#")
		return 6;
    if(s=="G")
		return 7;
    if(s=="G#")
		return 8;
    if(s=="A")
		return 9;
    if(s=="B")
		return 10;
	if(s=="H")
		return 11;
	return -100500;
}
int a[3];string s;
int main()
{
    for (int i = 0; i < 3; ++i)
    {
    	cin >>s;
    	a[i]=check(s);
    }
    for (int i = 0; i < 12; ++i)
    {
    	if( ((12+a[1]-a[0])%12==4)&&((12+a[2]-a[1])%12==3)&&((12+a[2]-a[0])%12==7) )
    	{
    		cout <<"major";
    		return 0;
    	}
    	if( ((24+a[1]-a[0])%12==3)&&((24+a[2]-a[1])%12==4)&&((24+a[2]-a[0])%12==7) )
    	{
    		cout <<"minor";
    		return 0;
    	}
    	next_permutation(a,a+3);
    }
    cout <<"strange";
	return 0;
}