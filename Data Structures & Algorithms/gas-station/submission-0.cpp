class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // same as interviewbit question 
        int sum1=0,sum2=0, n=gas.size();
        for(int i=0;i<n;i++){
            sum1+=gas[i];sum2+=cost[i];
        }
        if(sum1<sum2){
            return -1;
        }
        int index=0;sum1=0,sum2=0;
        for(int i=0;i<n;i++){
            sum1+=gas[i];sum2+=cost[i];
            if(sum1<sum2){
                sum1=0,sum2=0;index=i+1;
            }
        }
        return index;
    }
};
