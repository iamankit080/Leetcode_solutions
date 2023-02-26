class Solution {
public:

int solve(int i ,int j,string word1, string word2)
{
 if(i<0) return j+1;
 if(j<0) return i+1;
int match=INT_MAX,insert=INT_MAX,deletee=INT_MAX,replace=INT_MAX;
    if(word1[i]==word2[j])  match=solve(i-1,j-1,word1,word2);
 else {insert= 1+ solve(i,j-1,word1,word2);
  deletee= 1+ solve(i-1,j,word1,word2);
  replace= 1+solve(i-1,j-1,word1,word2);}
  return min ({match,insert,deletee,replace});
      
}
    int minDistance(string word1, string word2) {
        int x=word1.size();
        int y=word2.size();
        vector<vector<int>> dp(x+1,vector<int> (y+1,0));
        for(int i=0;i<=x;i++){
            dp[i][0]=i;
  }
            for(int j=0;j<=y;j++){
             dp[0][j]=j;

             
            }
      

   for(int i=1;i<=x;i++){

  for(int j=1;j<=y;j++){
                int match=INT_MAX,insert=INT_MAX,deletee=INT_MAX,replace=INT_MAX;
    if(word1[i-1]==word2[j-1])  match=dp[i-1][j-1];
     else {
         insert= 1+ dp[i][j-1];
        deletee= 1+ dp[i-1][j];
        replace= 1+dp[i-1][j-1];}
         dp[i][j]= min ({match,insert,deletee,replace});
           
            }
        }
        return dp[x][y];
    }
};