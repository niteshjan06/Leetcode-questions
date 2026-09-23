class Solution {
public:
    int titleToNumber(string columnTitle) {
        int columnNumber=0;
        for(int i=0;i<columnTitle.length();i++){
            columnNumber*=26;
            columnNumber+=(columnTitle[i]-64);
        }
        return columnNumber;
    }
};
