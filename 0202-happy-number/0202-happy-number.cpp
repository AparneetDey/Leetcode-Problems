class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> st;

        int num = n;
        while(true) {
            int sum = 0;
            while(num > 0) {
                sum += pow(num%10, 2);
                num /= 10;
            }
            if(st.count(sum)) break;
            if(sum == 1) return true;
            num = sum;
            st.insert(num);
        }

        return false;
    }
};