/*
problem link - https://codeforces.com/contest/414/problem/B
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
 ll dp[2007][2007];
    ll mode = 1e9 + 7;
    
    vector<int> v[2007];
int main()
{
    ll n,k;
    std::cin >> n>>k;
     memset(dp , 0 , sizeof(dp));
    	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			if(i%j==0)	v[i].push_back(j);
    for(int i = 1 ; i <= n ; i++) dp[1][i] = 1;
    
    for(int i = 1 ; i <= k ; i++) dp[i][1] = 1;
    
    for(int i = 2 ; i <= k ; i++) {
        
        for(int j = 2 ; j <= n ; j++){
            
            
            for(int t = 0; t < v[j].size() ; t++){
                
               
                    dp[i][j]= (dp[i][j] + dp[i-1][v[j][t]]) % mode;
             
             
            }
        }
    }
    
     ll ans = 0;
     
     for(int i = 1 ; i <= n ; i++) ans = (ans + dp[k][i])%mode;
     
     
     std::cout << ans << std::endl;

    return 0;
}
