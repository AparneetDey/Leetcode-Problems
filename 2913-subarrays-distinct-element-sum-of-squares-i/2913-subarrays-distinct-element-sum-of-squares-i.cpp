class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        vector<int> dist;

        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                unordered_set<int> st;
                for(int k=i; k<=j; k++) {
                    st.insert(nums[k]);
                }
                dist.push_back(st.size());
            }
        }

        int ans = 0;
        for(auto n : dist) {
            cout<<n<<endl;
            ans += n * n;
        }

        return ans;
    }
};