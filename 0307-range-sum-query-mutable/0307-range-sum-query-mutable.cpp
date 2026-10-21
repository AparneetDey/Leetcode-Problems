class NumArray {
    vector<int> arr;
    vector<int> seg;
public:
    NumArray(vector<int>& nums) {
        arr = nums;
        int n = nums.size();
        seg.assign(4*n, 0);
        build(0, 0, n - 1);
    }

    int build(int ind, int l, int r) {
        if(l == r) {
            return seg[ind] = arr[l];
        }
        
        int mid = (l+r) / 2;
        int left = build(2*ind + 1, l, mid);
        int right = build(2*ind + 2, mid + 1, r);

        return seg[ind] = left + right;
    }
    
    void update(int index, int val) {
        arr[index] = val;
        updateSeg(0, 0, arr.size() - 1, index, val);
    }

    void updateSeg(int ind, int l, int r, int index, int val) {
        if(l == r) {
            seg[ind] = val;
            return;
        }

        int mid = (l+r) / 2;
        if(index <= mid) {
            updateSeg(2*ind + 1, l, mid, index, val);
        } else {
            updateSeg(2*ind + 2, mid+1, r, index, val);
        }

        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
        return;
    }
    
    int sumRange(int left, int right) {
        return sum(0, 0, arr.size() - 1, left, right);
    }

    int sum(int ind, int l, int r, int leftRange, int rightRange) {
        if(r < leftRange || rightRange < l) return 0;

        if(leftRange <= l && r <= rightRange) return seg[ind];

        int mid = (l+r) / 2;
        int left = sum(2*ind + 1, l, mid, leftRange, rightRange);
        int right = sum(2*ind + 2, mid + 1, r, leftRange, rightRange);

        return left + right;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */