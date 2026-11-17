class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;

        if(s.size() != t.size()) return false;

        for(int i=0; i<s.size(); i++) {
            mp1[s[i]]++;
            mp2[t[i]]++;
        }

        for(auto [c, f] : mp1) {
            int f2 = mp2[c];
            if(f != f2) return false;
        }

        return true;
    }
};