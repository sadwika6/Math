#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int>vc(1000,0);
	vc[0] = 1;
	int sz = 1;
	int s = 0;
	int c = 0;
	for(int i=1;i<=n;i++)
	{
		int k = i;
		c = 0;
		for(int j=0;j<sz;j++)
		{
			int s = (i*vc[j])+c;
			vc[j] = s%10;
			c = s/10;
		}
		if(c)
		{
			
			vc[sz]=c;
			sz+=1;
		}
	}
	for(int i=0;i<sz;i++)
	{
		cout << vc[i] << " ";
	}
}