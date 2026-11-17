class Solution {
public:
    bool isPalindrome(string s) {
        string S;
        for(auto c : s) {
            if(isalnum(c)) {
                S.push_back(tolower(c));
            }
        }

        int n = S.size();
        if(n <= 1) return true;

        int i = n/2;
        int j;
        if(n % 2 == 0) j = i - 1;
        else j = i;

        while(i>=0 && j<n) {
            if(S[i] != S[j]) return false;
            i--;
            j++;
        }

        return true;
    }
};