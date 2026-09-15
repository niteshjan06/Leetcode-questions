class Solution {
public:
    int countPrimes(int n) {
        // Fast I/O optimization
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if (n <= 2) return 0;
        vector<char> isPrime(n, true);
        
        
        int count = n / 2; 

        
        for (int i = 3; i * i < n; i += 2) {
            if (isPrime[i]) {
                
                for (int j = i * i; j < n; j += 2 * i) {
                    if (isPrime[j]) {
                        isPrime[j] = false;
                        count--; 
                    }
                }
            }
        }

        return count;
    }
};