class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {

            // Skip duplicates
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // Pruning
            if ((long long)nums[i] + nums[i + 1] +
                nums[i + 2] + nums[i + 3] > target)
                break;

            if ((long long)nums[i] + nums[n - 3] +
                nums[n - 2] + nums[n - 1] < target)
                continue;

            for (int j = i + 1; j < n - 2; j++) {

                // Skip duplicates
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                // Pruning
                if ((long long)nums[i] + nums[j] +
                    nums[j + 1] + nums[j + 2] > target)
                    break;

                if ((long long)nums[i] + nums[j] +
                    nums[n - 2] + nums[n - 1] < target)
                    continue;

                int l = j + 1;
                int r = n - 1;

                while (l < r) {

                    long long sum = (long long)nums[i]
                                  + nums[j]
                                  + nums[l]
                                  + nums[r];

                    if (sum == target) {

                        ans.push_back({
                            nums[i],
                            nums[j],
                            nums[l],
                            nums[r]
                        });

                        l++;
                        r--;

                        // Skip duplicate left values
                        while (l < r && nums[l] == nums[l - 1])
                            l++;

                        // Skip duplicate right values
                        while (l < r && nums[r] == nums[r + 1])
                            r--;
                    }
                    else if (sum < target) {
                        l++;
                    }
                    else {
                        r--;
                    }
                }
            }
        }

        return ans;
    }
};