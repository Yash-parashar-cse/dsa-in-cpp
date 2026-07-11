class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int total = 0;

        vector<int> left_max(n,0);
        vector<int> right_max(n,0);

        left_max[0] = height[0];
        right_max[n-1] = height[n-1];

        for(int i=1;i<n;i++){
            left_max[i] = max(height[i], left_max[i-1]);
        }
        for(int j=n-2;j>=0;j--){
            right_max[j]  = max(height[j], right_max[j+1]);
        }
        for(int k=0;k<n;k++){
            total += min(left_max[k],right_max[k] ) - height[k];
        }
        return total;
    }
};