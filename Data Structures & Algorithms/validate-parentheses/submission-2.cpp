class Solution {
public:
    bool isValid(string s) {
        stack<char> t;
        for(auto i:s){
            if(i=='(' || i=='{' || i=='[') t.push(i);
            else{
                if(t.empty()) return 0;
                if(i== ')'){
                    if(t.top()!='(') return 0;
                    t.pop();
                }
                else if(i=='}'){
                    if(t.top()!='{') return 0;
                    t.pop();
                }
                else{
                    if(t.top()!='[') return 0;
                    t.pop();

                }
            }
        }
        if(!t.empty()) return 0;
        return 1;
    }
};
