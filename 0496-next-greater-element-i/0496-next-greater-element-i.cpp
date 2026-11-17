class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        stack<int> st;
        unordered_map<int, int> mp;

        for(int n : nums2) {
            while(!st.empty() && st.top() < n) {
                mp[st.top()] = n;
                st.pop();
            }

            st.push(n);
        }

        vector<int> ans(n1, -1);
        for(int i=0; i<n1; i++) {
            ans[i] = mp[nums1[i]];
            if(ans[i] == 0) ans[i] = -1;
        }

        return ans;
    }
};