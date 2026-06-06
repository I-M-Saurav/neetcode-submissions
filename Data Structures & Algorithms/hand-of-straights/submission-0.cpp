class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize) return 0;
        sort(hand.begin(),hand.end());
        int curr = -1,ct=0;
        while(ct<n){
            int siz = 0;
            for(int i=0;i<n;i++){
                if(curr == -1 && hand[i] != -1){
                    curr = hand[i];hand[i] = -1;
                    siz++;ct++;
                }
                else if( curr != -1 && hand[i] == curr+1){
                    curr = hand[i]; hand[i] = -1;
                    siz++; ct++;
                }
                if(siz == groupSize) break;
            }
            if(siz!= groupSize) return 0;
            curr = -1;
        }
        return 1;
    }
};
