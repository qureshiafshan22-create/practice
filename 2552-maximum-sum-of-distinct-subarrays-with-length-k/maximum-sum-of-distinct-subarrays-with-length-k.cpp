class Solution { 
public: 
    long long maximumSubarraySum(vector<int>& nums, int k) { 

        long long sum = 0; 
        unordered_set<int> st; 
        long long result = 0; 
 
        int i = 0, j = 0; 
        int n = nums.size(); 

        while(j < n) { 

            //incase if there is j present already in set 
            while(st.count(nums[j])) { 
                sum -= nums[i]; 
                st.erase(nums[i]); 
                i++; 
            } 
 
            //agr nhi present h j in the set then 
            sum += nums[j]; 
            st.insert(nums[j]); 

            //agr sare element hi unique h in window and window size bhii ho gya pura then 
            if(j - i + 1 == k) { 
                result = max(sum, result); 

                sum -= nums[i]; 
                st.erase(nums[i]); 
                i++; 
            } 

            j++; 
        } 

        return result;
    } 
};