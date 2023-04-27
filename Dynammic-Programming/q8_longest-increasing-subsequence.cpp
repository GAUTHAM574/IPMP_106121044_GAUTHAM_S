class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), res =1;
        int arr[n];
        for(int i = 0; i < n; i++){
            arr[i] = 1;
            int temp = 0;
            for(int j = 0; j < i; j++){
                if(nums[i] >nums[j]){
                    temp = max(temp, arr[j]);
                }
            }
            arr[i] = 1 + temp;
            res = max(res, arr[i]);
        }
        return res;
    }
};
