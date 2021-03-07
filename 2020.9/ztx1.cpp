#include <iostream>
#include <vector>
#include<bits/stdc++.h>  
using namespace std;

long long s[500100][6][2];
int main()
{
	int n,i,j;
	long long ans;
	cin >> n;
	vector<int> v;
	for (i = 0; i < n; i++)
	{
		int value;
		cin >> value;
		v.push_back(value);
	}
	memset(s,128,sizeof(s)); 
	s[0][0][0] = 0;
	for (i = 1; i <= n; i++)
	{
		for (j = 0; j <= 3; j++)
		{
			
			if(s[i - 1][j][0]>s[i - 1][j][1])
			{
				s[i][j][0]=s[i - 1][j][0];
			}
			else 
			    s[i][j][0]=s[i - 1][j][1];
			if (j >= 1)
			{
						if((s[i - 1][j - 1][0] + v[i-1])>(s[i - 1][j - 1][1] + v[i-1]))
						{
							s[i][j][1]=s[i - 1][j - 1][0] + v[i-1];
						}
						else 
						    s[i][j][1]=s[i - 1][j - 1][1] + v[i-1];
			}
			if(s[i][j][1]>(s[i - 1][j][1] + v[i-1]) )
			{
				s[i][j][1]=s[i][j][1];
			}
			else 
			    s[i][j][1]=s[i - 1][j][1] + v[i-1];

			
		}
	}
	if(s[n][3][0]> s[n][3][1] )
	{
		ans=s[n][3][0];
	}
	else 
	 ans= s[n][3][1];

	cout << ans << endl;

	return 0;
}
