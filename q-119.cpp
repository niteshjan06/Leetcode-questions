class Solution {
public:
    std::vector<int> getRow(int rowIndex) {
        std::vector<int> row;
        row.push_back(1); 
        
        long long current = 1; 
        
        for (int i = 1; i <= rowIndex; ++i) {
            current = current * (rowIndex - i + 1) / i;
            row.push_back(static_cast<int>(current));
        }
        
        return row;
    }
};