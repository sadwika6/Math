#include<bits/stdc++.h>
using namespace std;
int mod = 1e9+7;
int expo(int a,int b)
{
	if(b==0)
	{
		return 1;
	}
	if(b&1)
	{
		return a*expo(a,b-1);
	}
	else
	{
		a = a*a;
		return expo(a,b/2);
	}
}
int inverse(int b)
{
	return expo(b,mod-2);
}
int main()
{
	int a,b;
	cin >> a >> b;
	int res = 1;
	cout << expo(a,b)<<endl;
	cout << inverse(b);
}