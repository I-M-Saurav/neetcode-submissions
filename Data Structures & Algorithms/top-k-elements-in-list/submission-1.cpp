class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        for(int i:nums){
            mp[i]++;
        }  
        vector<int> ans;
        vector<pair<int,int>> a;
        for(auto i:mp){
            a.push_back({i.second,i.first});
        }
        sort(a.begin(),a.end());
        for(int i=a.size()-1;i>=0;i--){
            ans.push_back(a[i].second);
        }
        while(ans.size()>k){
            ans.pop_back();
        }
        return ans;
        
    }
};
