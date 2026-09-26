class Solution {
public:

    int findProfit(vector<int> &difficulty, vector<int> &profit, int target){
        int Profit=0;
        int low=0;
        int high=difficulty.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;

            if(difficulty[mid] > target){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        if(high==-1){
            Profit+=0;
        }else{
            Profit+=profit[high];
        }
        return Profit;
    }

    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {

        vector<pair<int,int>> jobs;

        for(int i=0;i<difficulty.size();i++){
            jobs.push_back({difficulty[i],profit[i]});
        }

        sort(jobs.begin(),jobs.end());

        for(int i=0;i<jobs.size();i++){
            difficulty[i]=jobs[i].first;
            profit[i]=jobs[i].second;
        }

        for(int i=1;i<profit.size();i++){
            profit[i]=max(profit[i],profit[i-1]);
        }

        int Profit=0;
        for(int i=0;i<worker.size();i++){
            Profit+=findProfit(difficulty,profit,worker[i]);
        }
        return Profit;
    }
};
