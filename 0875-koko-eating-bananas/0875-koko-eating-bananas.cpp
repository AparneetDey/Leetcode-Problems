class Solution {
public:
    bool canEat(vector<int>& piles, int h, int eat) {
        for(int n : piles) {
            h -= (n + eat - 1) / eat;

            if(h < 0) return false;
        }

        if(h >= 0) return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int mx = *max_element(piles.begin(), piles.end());
        int mn = 1;

        int ans = 0;
        while(mn <= mx) {
            int mid = (mn + mx) / 2;

            if(canEat(piles, h, mid)) {
                mx = mid - 1;
                ans = mid;
            } else {
                mn = mid + 1;
            }
        }

        return ans;
    }
};