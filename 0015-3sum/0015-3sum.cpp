class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {
            // Skip duplicate anchors to avoid duplicate triplets
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // Smallest element is positive -> no triplet can sum to 0
            if (nums[i] > 0) break;

            int left = i + 1, right = n - 1;
            int target = -nums[i];

            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum == target) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    // Skip duplicates on both pointers
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
                } else if (sum < target) {
                    left++;   // need a larger sum
                } else {
                    right--;  // need a smaller sum
                }
            }
        }
        return result;
    }
};