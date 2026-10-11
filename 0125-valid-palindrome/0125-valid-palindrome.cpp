class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";

        for(auto c : s) {
            if(isalnum(c)) {
                temp += tolower(c);
            }
        }

        string rev = temp;
        reverse(rev.begin(), rev.end());

        if(temp == rev) return true;
        return false;
    }
};