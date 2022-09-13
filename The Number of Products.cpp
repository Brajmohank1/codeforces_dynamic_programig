/*
problem statement - https://codeforces.com/contest/1215/problem/B

*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main()
{
    ll n;
    cin>>n;
    std::vector<ll> arr(n)  ;
    
    vector<vector<ll>> dp(n,vector<ll>(2,0));
    
    for(int i = 0 ; i < n ; i++) cin>>arr[i];
    
    if(arr[0] > 0) dp[0][0] = 1;
    else dp[0][1] = 1;
    
    
    for(int i = 1 ; i < n ;i++){
        
        if(arr[i] > 0){
            dp[i][0] = dp[i-1][0] + 1;
            dp[i][1] = dp[i-1][1];
        
        }else{
             
           
            
            dp[i][0] = dp[i-1][1];
            dp[i][1] = 1 + dp[i-1][0];
            
        }}
    
    
    ll pos = 0 , neg = 0;
    
    for(int i = 0 ; i < n ; i++){
        
        pos += dp[i][0];
        neg += dp[i][1];
    }

    std::cout << neg<< " " << pos<< std::endl;
    return 0;
}
