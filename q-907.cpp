class Solution {
public:

    void findNSE(vector<int> &nse, vector<int> &arr){
        stack<int> st;

        for(int i=arr.size()-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }

            nse[i]=st.empty()?arr.size():st.top();
            st.push(i);
        }
    }
    void findPSE(vector<int> &pse, vector<int> &arr){
        stack<int> st;

        for(int i=0;i<arr.size();i++)
        {
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }

            pse[i]=st.empty()?-1:st.top();
            st.push(i);
        }
    }

    int sumSubarrayMins(vector<int>& arr) {
       vector<int> nse(arr.size()); 
       vector<int> pse(arr.size()); 

       findNSE(nse,arr);
       findPSE(pse,arr);

        long long total=0;
        int mod=1e9+7;

        for(int i=0;i<arr.size();i++){
            int left=i-pse[i];
            int right=nse[i]-i;

            total=(total+(left*right*1LL*arr[i])%mod)%mod;
        }
        return total;
    }
};
