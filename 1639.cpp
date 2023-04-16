class Solution {
public:
    int mod=1e9+7;
    int f(int i,int j,string &target,vector<string>& words,vector<vector<int>>&dp,vector<vector<int>>&freq){
        if(j==target.size()){
            //  word is found            
            return 1;
        }
        if(i==freq.size()){
            // not found in words array
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int notpick=f(i+1,j,target,words,dp,freq);
        int pick=0;
        char ch=target[j];
        if(freq[i][ch-'a']!=0){
            int ways=freq[i][ch-'a'];
            int next=f(i+1,j+1,target,words,dp,freq);
            pick=(ways*(long long)next)%mod;
        }
        return dp[i][j]=(pick+(long long)notpick)%mod;
    }
    int numWays(vector<string>& words, string target) {
        int m=words.size(),n=words[0].size();
        // to store freq according to n; 
        vector<vector<int>>freq(n,vector<int>(26,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                char ch=words[i][j];
                freq[j][ch-'a']++;
            }
        }
        vector<vector<int>>dp(n,vector<int>(target.size(),-1));
        return f(0,0,target,words,dp,freq);
    }
};