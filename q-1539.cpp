#include <vector>

class Solution {
public:
    int findKthPositive(std::vector<int>& arr, int k) {
        int low = 0;
        int high = arr.size() - 1;
        
        // Binary search to find the window where the kth missing number resides
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Calculate how many numbers are missing before the current index
            int missing_count = arr[mid] - (mid + 1);
            
            if (missing_count < k) {
                low = mid + 1; // Look into the right half
            } else {
                high = mid - 1; // Look into the left half
            }
        }
        
        return low + k;
    }
};
