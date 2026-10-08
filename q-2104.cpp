class Solution {
public:

    void findNSE(vector<int> &nse, vector<int> &arr)
    {
        stack<int> st;

        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            nse[i]=st.empty()?arr.size():st.top();
            st.push(i);
        }
    }

    void findPSE(vector<int> &pse, vector<int> &arr)
    {
        stack<int> st;

        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            pse[i]=st.empty()?-1:st.top();
            st.push(i);
        }
    }

    long long sumSubarrayMins(vector<int> &arr) {
  
        vector<int> nse(arr.size());
        vector<int> pse(arr.size());

        findNSE(nse,arr);
        findPSE(pse,arr);

        long long total=0;

        for(int i=0;i<arr.size();i++){
            long long left=i-pse[i];
            long long right=nse[i]-i;

            total+=left*right*1LL*arr[i];
        }
        return total;
    }

    //--------------------------------------------------------------------------------------------------------------------
    void findNGE(vector<int> &nge, vector<int> &arr)
    {
        stack<int> st;

        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]<=arr[i]){
                st.pop();
            }
            nge[i]=st.empty()?arr.size():st.top();
            st.push(i);
        }
    }

    void findPGE(vector<int> &pge, vector<int> &arr)
    {
        stack<int> st;

        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()]<arr[i]){
                st.pop();
            }
            pge[i]=st.empty()?-1:st.top();
            st.push(i);
        }
    }

    long long sumSubarrayMaxis(vector<int> &arr) {
  
        vector<int> nge(arr.size());
        vector<int> pge(arr.size());

        findNGE(nge,arr);
        findPGE(pge,arr);

        long long total=0;
        
        for(int i=0;i<arr.size();i++){
            long long left=i-pge[i];
            long long right=nge[i]-i;

            total=total+(left*right*1LL*arr[i]);
        }
        return total;
    }

    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxis(nums)-sumSubarrayMins(nums);
    }
};
