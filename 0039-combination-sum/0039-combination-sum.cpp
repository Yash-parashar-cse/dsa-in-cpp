class Solution {
public:
    set<vector<int>> s;

    void myFunction(vector<int>candidates, int index, int target, vector<int>& combination, vector<vector<int>>& ans){

        // Base cases
        if(target == 0){
            if(s.find(combination) == s.end()){
                ans.push_back({combination});
                s.insert(combination);
            }
        }

        if(index == candidates.size()) return;

        if(target < 0) return;

        // Inclusion step
        combination.push_back(candidates[index]);
        myFunction(candidates, index+1, target-candidates[index], combination, ans);

        // multiple inclusion step, the index remains same here
        myFunction(candidates, index, target-candidates[index], combination, ans);

        // Backtraking step before exclusion choice
        combination.pop_back();

        // Exclusion step
        myFunction(candidates, index+1, target, combination, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> combination;
        vector<vector<int>> ans;

        myFunction(candidates, 0, target, combination, ans);
        return ans;
    }
}; 