class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        vector<int> freq(100001, 0);

        long long sum = 0;
        long long ans = 0;

        int left = 0;
        int distinct = 0;

        for(int right = 0; right < nums.size(); right++) {

            // Add nums[right]
            if(freq[nums[right]] == 0) {
                distinct++;
            }

            freq[nums[right]]++;
            sum += nums[right];

            // Remove element if window > k
            if(right - left + 1 > k) {

                freq[nums[left]]--;
                sum -= nums[left];

                if(freq[nums[left]] == 0) {
                    distinct--;
                }

                left++;
            }

            // Check valid window
            if(right - left + 1 == k && distinct == k) {
                ans = max(ans, sum);
            }
        }

        return ans;
    }
};