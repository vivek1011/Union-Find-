/*
Initially everybody is owner of itself.
If you want to chane the ownership then call unionfun function and it will merge two sets
and make their common parent.
Now you can find out the ownership using find function. 
Problem Link - https://www.codechef.com/problems/DISHOWN
*/
#include<bits/stdc++.h>
using namespace std;
int par[10002];
int find(int x)
{
	if(x==par[x])
		return x;
	return (par[x] = find(par[x]));
}
void unionfun(int x, int y)
{
	int parent1 = find(x);
	int parent2 = find(y);
	if(parent2!=parent1)
		par[parent2] = parent1;
}
int main()
{
	for(int i =1; i<=100;i++) // means everybody is parent of itself 
		par[i] = i ;
	unionfun(1, 2);
	unionfun(1, 3);
	cout<<par[3]<<endl;
	return 0;
}
