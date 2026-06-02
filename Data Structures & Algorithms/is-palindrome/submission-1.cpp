class Solution {
public:
    bool isPalindrome(string s) {
        string t;
        for(auto i:s){
            if((i>='0' && i<='9') || (i>='a' && i<='z')){
                t.push_back(i);
            }
            else if(i>='A' && i<='Z'){
                t.push_back(i+32);
            }
        }
        string t1=t;
        reverse(t.begin(),t.end());
        return t==t1;
    }
};
