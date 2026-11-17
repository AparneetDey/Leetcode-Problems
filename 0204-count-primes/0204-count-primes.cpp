class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;

        vector<bool> prime(n, true);
        long long p = 2;
        prime[0] = prime[1] = false;

        while(p*p < n) {
            if(prime[p]) {
                cout<<p<<endl;
                for(long long i=p*p; i<n; i+=p) prime[i] = false;
            }
            p++;
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            if(prime[i]) ans++;
        }

        return ans;
    }
};