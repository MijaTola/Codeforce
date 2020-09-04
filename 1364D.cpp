#include <bits/stdc++.h>

using namespace std;

vector<int> v[100005],s;
int sq,dep[100005];
bool marked[100005];

void dfs(int node) {
	s.push_back(node);
	dep[node]=s.size();
	for (int u:v[node])
	{
		if (!dep[u])
		dfs(u);
		else if (dep[node]-dep[u]+1==sq)
		{
			printf("2\n%d\n",dep[node]-dep[u]+1);
			for (int i=dep[u]-1;i<dep[node];i++)
			printf("%d ",s[i]);
			exit(0);
		}
	}
	if (!marked[node])
	{
		for (int u:v[node])
		marked[u]=1;
	}
	s.pop_back();
}

//finding cyclea
int main() {

	int n,m,k;
	scanf("%d%d%d",&n,&m, &k);
    sq = k;

	while (m--){
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}

    //should work
	dfs(1);
	printf("1\n");
	for (int i=1; i <= n and sq;i++)
	{
		if (!marked[i] and sq)
		{
			printf("%d ",i);
			sq--;
		}
	}
}
