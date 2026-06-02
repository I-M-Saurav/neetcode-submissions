class Solution {
public:
    bool finds(long long mid, vector<int>& a, int h){
        int ans=0;
        for(auto i:a){
            ans+=(i+mid-1)/mid;
        }
        return h>=ans;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long long i=1,j=1e15,ans=1;
        while(i<=j){
            long long mid=(i+j)/2;
            if(finds(mid,piles,h)){
                j=mid-1;ans=mid;
            }
            else{
                i=mid+1;
            }
        } 
        return ans;
    }
};
