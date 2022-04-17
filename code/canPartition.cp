/*C++ Implementation of Partition equal subset sum.*/ 
#include<bits/stdc++.h> 
using namespace std; 
bool partition(vector<int>nums,int sum)
{
    int n=nums.size();
    /**/
    int dp[n+1][sum+1];
    memset(dp,0,sizeof(dp));
    /*Set all cells of first column as 1.*/
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            /*update answer for each row.*/
            if(nums[i-1]<=j)
            {
                dp[i][j]=dp[i-1][j]||dp[i-1][j-nums[i-1]];
            }
            else dp[i][j]=dp[i-1][j];
        }
    }
    /*return the result.*/
    return dp[n][sum];
}
bool canPartition(vector<int>& nums) 
{
    int sum=0;
    for(int i=0;i<nums.size();i++)
    {
        sum+=nums[i];
    }
    if(sum%2!=0)
    {
        return 0;
    }
    return partition(nums,sum/2);   
}
int main() 
{ 
    /*input values.*/ 
    int n;  
    cin>>n;  
    vector<int> inp; 
    for(int i=0;i<n;i++) 
    { 
       int x; 
       cin>>x; 
       inp.push_back(x); 
    }  
    /*call the function.*/
    bool flag=canPartition(inp);
    /*print the answer.*/
    if(flag)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0; 
}