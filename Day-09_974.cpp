/*
974. Subarray Sums Divisible by K
Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]

Example 2:

Input: nums = [5], k = 9
Output: 0

 

Constraints:

    1 <= nums.length <= 3 * 104
    -104 <= nums[i] <= 104
    2 <= k <= 104

*/
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int total=0, ans=0;
        unordered_map<int, int>mp;
        mp[0]=1;
        for(auto it:nums)
        {
            total+=it;
            if(total<0)
            {
                int pos=abs(total)%k;
                total=k-pos;
            }
            total%=k;
            cout<<total<<" ";
            ans+=mp[total];
            mp[total]++;
        }
        return ans;
    }
};
