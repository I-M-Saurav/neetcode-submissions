class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        int ans1 = 1;
        if (beginWord == endWord)
            return ans1;
        unordered_set<string> s;
        for (auto& i : wordList) {
            s.insert(i);
        }
        if (!s.count(endWord))
            return 0;
        queue<string> q;
        q.push(beginWord);
        // unordered_set<string> ans;
        // ans.insert(beginWord);
        // int n = wordList.size();
        while (!q.empty()) {
            int curr = q.size();
            while (curr--) {
                string str = q.front();
                q.pop();
                int siz = str.length();
                for (int i = 0; i < siz; i++) {
                    char original = str[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == original)
                            continue;
                        str[i] = c;
                        if (s.count(str)) {
                            if (str == endWord) {
                                return ans1 + 1;
                            } else {
                                q.push(str);
                            }
                            s.erase(str);
                        }
                        // c++;
                        str[i] = original;
                    }
                }
            }
            ans1++;
        }
        return 0;
    }
};