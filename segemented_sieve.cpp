#include<bits/stdc++.h>
using namespace std;
vector<int>primes(1000001,1);
void sieve()
{
	int n = primes.size();
	primes[0] = primes[1] = 0;
	for(int i = 2;i*i<n;i++)
	{
		if(primes[i]==1)
		{
			for(int j = 2*i;j<n;j+=i)
			{
				//cout << j << " ";
				primes[j] = 0;
			}
		}
	}
}

void segmented_Seive(vector<int>&s_sieve,vector<int>&pr,int l)
{
	for(auto i:pr)
	{
		int x = (l/pr[i])*pr[i];
		if(x < l)
		{
			x += i;
		}
		//cout << x << endl;
		// if(x <= 1)
		// {
		// 	x = pr[i]+pr[i];
		// }
		// else if(l%pr[i])
		// {
		// 	x = (x*pr[i])+pr[i];
		// }
		// else
		// {
		// 	x = x*pr[i];
		// }
		//cout << i << " " << x << endl;
		for(int j = max(i*i,x);j<s_sieve.size();j+=i)
		{
			//cout << x << " " << j << "*" << j+l << endl;
			s_sieve[j-l] = 0;
			//cout << j-l << endl;
		}
	}
}

int main()
{
	sieve();
	int l,r;
	cin >> l >> r;
	
	vector<int>s_sieve(r-l+1,1);
	vector<int>pr;
	for (int i = 2; i * i <= r; i++) {
		//cout << i << " ";
		if (primes[i] == 1) {
			pr.push_back(i);
			//cout << i << endl;
		}
	}
	
	segmented_Seive(s_sieve,pr,l);
	for(int i=max(l,2);i<r;i++)
	{
		//cout << i << " " << primes[i] << " " << s_sieve[i-l] << endl;
		if(s_sieve[i-l])
		{
			cout << i << " ";
		}
	}
}