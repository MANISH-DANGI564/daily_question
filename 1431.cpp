class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n=candies.size();
        vector<bool>res(n,false);
        int maxi=0;
        for(auto x:candies){
            maxi=max(maxi,x);
        }
        for(int i=0;i<n;i++){
            if(candies[i]+extraCandies>=maxi){
                res[i]=true;
            }
        }
        return res;
    }
};