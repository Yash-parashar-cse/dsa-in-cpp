class Solution {
public:
    void myFunction(vector<int>& candidates, int target, int index, vector<int>& curr, vector<vector<int>>& ans){
        // base cases
        

        if(target == 0){
            ans.push_back({curr});
            return;
        }
        if(index == candidates.size() || target < 0) return;

        for(int i= index; i<candidates.size(); i++){
            if(i> index && candidates[i] == candidates[i-1]){
                continue;
            }

            // include
            curr.push_back(candidates[i]);
            myFunction(candidates, target-candidates[i], i+1, curr, ans);

            // backtrack and exclude 
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());

        myFunction(candidates, target, 0, curr, ans);
        return ans;
    }
};