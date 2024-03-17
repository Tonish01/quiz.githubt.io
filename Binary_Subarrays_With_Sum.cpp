/*

Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
Example 2:

Input: nums = [0,0,0,0,0], goal = 0
Output: 15
 

Constraints:

1 <= nums.length <= 3 * 104
nums[i] is either 0 or 1.
0 <= goal <= nums.length

*/

//------------------------------------------------------------------------SOLUTION----------------------------------------------------------------

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans=0;
        int n=nums.size();
        //BRUTE TLE for last case
        // for(int i=0;i<n;i++){
        //     int sum=0;
        //     for(int j=i;j<n;j++){
        //         sum+=nums[j];
        //         if(sum==goal)
        //         ans++;
        //     }
        // }
        // return ans;
        unordered_map<int,int>mp;
        mp[0]=1;
        int presum=0;
        for(auto i:nums){
            presum+=i;
            ans+=mp[presum-goal];
            mp[presum]++;
        }
        return ans;
    }
};