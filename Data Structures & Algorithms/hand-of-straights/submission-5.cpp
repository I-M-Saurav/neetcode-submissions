class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize) return 0;
        // sort(hand.begin(),hand.end());
        // int curr = -1,ct=0;
        // while(ct<n){
        //     int siz = 0;
        //     for(int i=0;i<n;i++){
        //         if(curr == -1 && hand[i] != -1){
        //             curr = hand[i];hand[i] = -1;
        //             siz++;ct++;
        //         }
        //         else if( curr != -1 && hand[i] == curr+1){
        //             curr = hand[i]; hand[i] = -1;
        //             siz++; ct++;
        //         }
        //         if(siz == groupSize) break;
        //     }
        //     if(siz!= groupSize) return 0;
        //     curr = -1;
        // }
        // return 1; // O(n^2) solution using constructive algorithm
        set<int> q;
        int maxi = *max_element(hand.begin(), hand.end());
        vector<int> hash(maxi+2);
        for(int i=0;i<n;i++){
            q.insert(hand[i]);
            hash[hand[i]]++;
        }
        while(!q.empty()){
            int x = *q.begin();
            for(int i = x; i< x+groupSize; i++){
                if(hash[i] == 0) return 0;
                hash[i]--;
                if(hash[i] == 0){
                    if(*q.begin() != i) return 0;
                    q.erase(q.begin());
                }
            }

        }
        return 1;// this is the optimal solution using minheap logic in O(nlog(n)).
    }
};
