#include <vector>

class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        
        vector<int> bit_counts(30, 0);
        
        for (int num : nums) {
            for (int i = 0; i < 30; ++i) {
                if ((num >> i) & 1) {
                    bit_counts[i]++;
                }
            }
        }
        
        long long total_sum = 0;
        
        for (int step = 0; step < k; ++step) {
            long long current_num = 0;
            for (int i = 0; i < 30; ++i) {
                if (bit_counts[i] > 0) {
                    current_num |= (1 << i);
                    bit_counts[i]--; 
                }
            }
            long long square = (current_num * current_num) % MOD;
            total_sum = (total_sum + square) % MOD;
        }
        
        return total_sum;
    }
};
