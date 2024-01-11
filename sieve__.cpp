#include<bits/stdc++.h>
using namespace std;
void sieve(int n,vector<int>&p)
{
	p[0] = p[1] = 0;
	for(int i = 2;i*i<=n;i++)
	{
		if(p[i]==1)
		{
			for(int j = 2*i;j<=n;j+=i)
			{
				p[j] = 0;
			}
		}
	}
}
int main()
{
	int n;
	cin >> n;
	vector<int>primes(n+1,1);
	sieve(n,primes);
	for(int i = 210;i<=234;i++)
	{
		//cout << primes[i] << endl;
		if(primes[i]==1)
		{
			cout << i << " ";
		}
	}
}