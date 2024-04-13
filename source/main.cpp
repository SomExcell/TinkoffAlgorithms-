#include <iostream>
#include <algorithm>
#include <vector>

std::vector<char>obr(300,'.');
 
void removeBrackets(int left,int right,int count,const std::string &string,std::string &answer,std::vector<std::vector<int>> &dp){
    
    if(left > right)return;
    
    if(left == right){
        answer[right] = '/';
        return;
    }
    
    if(dp[left][right] == dp[left][right-1]+1){
        
        answer[right] = '/';
        
        removeBrackets(left,right-1,count,string,answer,dp);
        
        return;
    }
    
    for(int a = left;a<right;++a){
                 
        if(obr[string[right]] == string[a]){
            
            if(a == left){
                
                if(dp[left][right] == dp[left+1][right-1]){
                
                    removeBrackets(left+1,right-1,count,string,answer,dp);
                    return;
                }
                
            }
            else if(dp[left][right] == dp[left][a-1] + dp[a][right]){
                
                removeBrackets(left,a-1,count,string,answer,dp);
                removeBrackets(a,right,count,string,answer,dp);
                return;              
            }
        }
    }
}
 
 
 
 
int main() 
{
    std::string string;
    std::cin >> string;
    
    int count = string.size();
    std::vector<std::vector<int>> dp(count,std::vector<int>(count));
    
    obr[')'] = '(';
    obr[']'] = '[';
    obr['}'] = '{';
     
    for(int i = 0;i < count; ++i)
    {
        dp[i][i] = 1;
    }
     
    for(int i = 1;i<=count;++i)
    {
         
        for(int j = 0;j<count;++j)
        {
             
            if(j + i >= count){break;}
             
            int l = j;
            int r = j+i;
             
            dp[l][r] = dp[l][r-1] + 1;
             
            for(int a = l;a<r;++a)
            {
                if(obr[string[r]] == string[a])
                {
                    if(a == l)
                    {
                        dp[l][r] = std::min(dp[l][r],dp[l+1][r-1]);
                    }
                    else 
                    {
                        dp[l][r] = std::min(dp[l][r],dp[l][a-1] + dp[a][r]);
                    }
                }
            }
        }
    }
         
    
    std::string answer(count,'.');
    //answer.resize(count,'.');
    
    removeBrackets(0,count-1,count,string,answer,dp);
    
    for(int i = 0;i<count;++i)
    {
        if(answer[i] == '.')
        {
            std::cout << string[i];
        }
    }
    
    
    
    return 0;
}