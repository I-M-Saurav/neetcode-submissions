class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0,curr=31;
        while(n>0){
            if(n&1){
                ans+=(1<<curr);
            }
            curr--;n=(n>>1);
        }
        return ans;
    }
};
