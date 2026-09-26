class Solution {
public:
    string frequencySort(string s) {
        int hash[256];
        for(int i=0;i<s.length();i++){
            hash[s[i]]++;
        }

        vector<pair<int,char>> arr;
        for(int i=0;i<256;i++){
            if(hash[i]!=0){
                arr.push_back({hash[i],i});
            }
        }
        sort(arr.rbegin(),arr.rend());
        string str="";
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr[i].first;j++){
                str+=char(arr[i].second);
            }
        }
        return str;
    }
};
