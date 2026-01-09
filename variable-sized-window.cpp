
// Problem 1 -  Minimum Size Subarray Sum

// Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

// Example 1:

// Input: target = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: The subarray [4,3] has the minimal length under the problem constraint.
// Example 2:

// Input: target = 4, nums = [1,4,4]
// Output: 1
// Example 3:

// Input: target = 11, nums = [1,1,1,1,1,1,1,1]
// Output: 0
 

// Constraints:

// 1 <= target <= 109
// 1 <= nums.length <= 105
// 1 <= nums[i] <= 104
 
// Follow up: If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log(n)).

// Approach 1 - Brute Force (Time Complexity-O(n^2))

// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {
//         int n = nums.size();

//         int len = INT_MAX;

//         for(int i=0;i<n;i++){

//             int sum = 0;
//             for(int j=i;j<n;j++){

//                 sum = sum + nums[j];
//                 if(sum >= target){
//                     len = min(len,j-i+1);
//                     break;//our task was of minimum length
//                 }
//             }
//         }

//         return (len == INT_MAX)?0:len;
//     }
// };


//Approach 2 - Time complexity of O(n)

// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {
//         int n = nums.size();

//         int len = INT_MAX;

//         int l = 0,r = 0;
//         int sum = 0;

//         while(r < n){

//             sum = sum + nums[r];

//             while(l <= r && sum >= target){
//                 len = min(len,r-l+1);
//                 sum -= nums[l];
//                 l++;
//             }

//             r++;
//         }
        
//         return (len == INT_MAX)?0:len;
//     }
// };



//Approach 3 - Time complexity of O(nlogn)

// class Solution {
// public:

//     int binarySearch(vector<int>& prefix,int low,int high,int target){

//         int sumToExclude = (low == 0)?0:prefix[low-1];
//         int ans = -1;
//         while(low <= high){

//             int mid = low + floor((high-low)/2);

//             if(prefix[mid] - sumToExclude >= target){
//                 ans = mid;
//                 high = mid-1;
//             }
//             else{
//                 low = mid+1;
//             }
//         }

//         return ans;
//     }
//     int minSubArrayLen(int target, vector<int>& nums) {
        
//         int n = nums.size();
//         int len = INT_MAX;

//         vector<int> prefix = nums;

//         for(int i=1;i<n;i++){

//             prefix[i] += prefix[i-1];
//         }

//         for(int i=0;i<n;i++){

//             int j = binarySearch(prefix,i,n-1,target);

//             if(j == -1) continue;

//             len = min(len, j-i+1);
//         }

//         return (len == INT_MAX)?0:len;
//     }
// };


// -------------------------------------------------------------------------------------------------------------

// Problem 2 - Number of Subarrays with Bounded Maximum

// Given an integer array nums and two integers left and right, return the number of contiguous non-empty subarrays such that the value of the maximum array element in that subarray is in the range [left, right].
// The test cases are generated so that the answer will fit in a 32-bit integer.

// Example 1:

// Input: nums = [2,1,4,3], left = 2, right = 3
// Output: 3
// Explanation: There are three subarrays that meet the requirements: [2], [2, 1], [3].
// Example 2:

// Input: nums = [2,9,2,5,6], left = 2, right = 8
// Output: 7
 
// Constraints:

// 1 <= nums.length <= 105
// 0 <= nums[i] <= 109
// 0 <= left <= right <= 109

// class Solution {
// public:
//     int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        
//         int n= nums.size();
//         int target = left-1;

//         //firstly count those subarrays whose ,maxiomum element is at maximum equal to maxi

//         int i = 0,j = 0;
//         int maxi = INT_MIN;
//         int tillLeftCnt= 0;

//         while(j < n){

//             maxi = max(maxi,nums[j]);

//             if(maxi > target){
//                 int len = j-i;
//                 maxi = INT_MIN;
//                 tillLeftCnt += ((long long)len*(len+1))/2; 
//                 i = j+1;
//             }
//             j++;
//         }

//         int len = j-i;
//         tillLeftCnt += ((long long)len*(len+1))/2; 

//         target = right;
//         i = 0,j = 0,maxi = INT_MIN;
//         int tillRightCnt = 0;
//         while(j < n){

//             maxi = max(maxi,nums[j]);

//             if(maxi > target){
//                 int len = j-i;
//                 maxi = INT_MIN;
//                 tillRightCnt += ((long long)len*(len+1))/2; 
//                 i = j+1;
//             }
//             j++;
//         }

//         len = j-i;
//         tillRightCnt += ((long long)len*(len+1))/2;

//         return tillRightCnt - tillLeftCnt;
//     }
// };

// -----------------------------------------------------------------------------------------------------------

// Problem 3 - Max Consecutive Ones III

// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

// Example 1:

// Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
// Output: 6
// Explanation: [1,1,1,0,0,1,1,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
// Example 2:

// Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
// Output: 10
// Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 
// Constraints:

// 1 <= nums.length <= 105
// nums[i] is either 0 or 1.
// 0 <= k <= nums.length

// //Approach 1 - O(n^2) TLE

// class Solution {
// public:
//     int longestOnes(vector<int>& nums, int k) {
        

//         int n = nums.size();
//         int maxi = INT_MIN;
//         for(int i=0;i<n;i++){

//             int cnt = k;
//             int j;
//             for(j=i;j<n;j++){
                
//                 if(nums[j] == 0 && cnt == 0) break;
                
//                 if(nums[j] == 0) cnt--;
//             }

//             maxi = max(maxi, j-i);
//         }

//         return maxi;
//     }

// };


//Approach 2 - Optimal O(n) using sliding window just find out the maximum lenegth window where the number of 0's at max is k

// class Solution {
// public:
//     int longestOnes(vector<int>& nums, int k) {
        


//         int l = 0,r = 0;
//         int cntZeroes = 0;

//         int n = nums.size();
//         int maxi = INT_MIN;
//         while(r < n){

//             if(nums[r] == 0) cntZeroes++;

//             if(l <= r && cntZeroes>k){

//                 if(nums[l] == 0) cntZeroes--;
//                 l++;
//             }

//             //you will always have the window which has 0's less than or equal to k
//             maxi = max(maxi, r-l+1);
//             r++;
//         }

//         return maxi;

//     }
// };


// --------------------------------------------------------------------------------------------------------------

// Problem 4 - Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit

// Given an array of integers nums and an integer limit, return the size of the longest non-empty subarray such that the absolute difference between any two elements of this subarray is less than or equal to limit.

// Example 1:

// Input: nums = [8,2,4,7], limit = 4
// Output: 2 
// Explanation: All subarrays are: 
// [8] with maximum absolute diff |8-8| = 0 <= 4.
// [8,2] with maximum absolute diff |8-2| = 6 > 4. 
// [8,2,4] with maximum absolute diff |8-2| = 6 > 4.
// [8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
// [2] with maximum absolute diff |2-2| = 0 <= 4.
// [2,4] with maximum absolute diff |2-4| = 2 <= 4.
// [2,4,7] with maximum absolute diff |2-7| = 5 > 4.
// [4] with maximum absolute diff |4-4| = 0 <= 4.
// [4,7] with maximum absolute diff |4-7| = 3 <= 4.
// [7] with maximum absolute diff |7-7| = 0 <= 4. 
// Therefore, the size of the longest subarray is 2.
// Example 2:

// Input: nums = [10,1,2,4,7,2], limit = 5
// Output: 4 
// Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5.
// Example 3:

// Input: nums = [4,2,2,2,4,4,2,2], limit = 0
// Output: 3
 

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 109
// 0 <= limit <= 109


// class Solution {
// public:
//     int longestSubarray(vector<int>& nums, int limit) {
        

//         int maxi = INT_MIN;

//         int n= nums.size();

//         int l = 0,r = 0;

//         map<int,int> mpp;//use ordered map to get the minimum and the maximum element
//         while(r < n){

//             mpp[nums[r]]++;
//             auto it = mpp.end();
//             it--;
//             while(l<r && it->first - mpp.begin()->first > limit){

//                 mpp[nums[l]]--;
//                 if(mpp[nums[l]] == 0) mpp.erase(nums[l]);
//                 l++;
//                 it = mpp.end();//may be the maximum elemnet iterator may chnagde
//                 it--;
//             }

//             maxi = max(maxi, r-l+1);
//             r++;
//         }

//         return maxi;
//     }
// };


// ------------------------------------------------------------------------------------------------------------

// Problem 5 - Maximum Erasure Value

// You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements.
// Return the maximum score you can get by erasing exactly one subarray.
// An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).

// Example 1:

// Input: nums = [4,2,4,5,6]
// Output: 17
// Explanation: The optimal subarray here is [2,4,5,6].
// Example 2:

// Input: nums = [5,2,1,2,5,2,1,2,5]
// Output: 8
// Explanation: The optimal subarray here is [5,2,1] or [1,2,5].

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 104

//Approach 1 - O(n) time and space O(1)

// class Solution {
// public:
//     int maximumUniqueSubarray(vector<int>& nums) {
        
//         int l = 0,r = 0;
//         int n = nums.size();
//         int res = 0;
//         unordered_map<int,int> mpp;
//         int sum = 0;
//         while(r < n){
            
//             sum = sum + nums[r];
//             while(l<=r && mpp.count(nums[r])){
    
//                 mpp[nums[l]]--;
//                 sum = sum - nums[l];
//                 if(mpp[nums[l]] == 0) mpp.erase(nums[l]);
//                 l++;
//             }

//             //here we have come which means nums[r] is absent in the map
//             mpp[nums[r]]++;
//             res = max(res,sum);
            
//             r++;
//         }

//         return res;
//     }
// };


// Approach 2 - O(n) time and O(n) space

// class Solution {
// public:
//     int maximumUniqueSubarray(vector<int>& nums) {
        
//         int n = nums.size();
//         unordered_map<int,int> mpp;

//         vector<int> prefix = nums;

//         for(int i=1;i<n;i++){
//             prefix[i] += prefix[i-1];
//         }

//         int l = 0,r = 0;
//         int res = INT_MIN;

//         while(r < n){

//             int sum = prefix[r];

//             if(mpp.count(nums[r]) && l <= mpp[nums[r]]){
//                 //so must remove the sum i.e. collected till mpp[nums[r]] using prefix array directly
//                 sum  -= prefix[ mpp[nums[r]] ];
//                 l = mpp[nums[r]]+1;
//             }
//             else{
//                 //map does contain it
//                 if(l != 0) sum -= prefix[l-1];
//             }

//             mpp[nums[r]] = r;
//             res = max(res, sum);
//             r++;
//         }


//         return res;
//     }
// };

// --------------------------------------------------------------------------------------------------------------

// Problem 6 - Maximize the Confusion of an Exam

// A teacher is writing a test with n true/false questions, with 'T' denoting true and 'F' denoting false. He wants to confuse the students by maximizing the number of consecutive questions with the same answer (multiple trues or multiple falses in a row).
// You are given a string answerKey, where answerKey[i] is the original answer to the ith question. In addition, you are given an integer k, the maximum number of times you may perform the following operation:
// Change the answer key for any question to 'T' or 'F' (i.e., set answerKey[i] to 'T' or 'F').
// Return the maximum number of consecutive 'T's or 'F's in the answer key after performing the operation at most k times.

// Example 1:

// Input: answerKey = "TTFF", k = 2
// Output: 4
// Explanation: We can replace both the 'F's with 'T's to make answerKey = "TTTT".
// There are four consecutive 'T's.
// Example 2:

// Input: answerKey = "TFFT", k = 1
// Output: 3
// Explanation: We can replace the first 'T' with an 'F' to make answerKey = "FFFT".
// Alternatively, we can replace the second 'T' with an 'F' to make answerKey = "TFFF".
// In both cases, there are three consecutive 'F's.
// Example 3:

// Input: answerKey = "TTFTTFTT", k = 1
// Output: 5
// Explanation: We can replace the first 'F' to make answerKey = "TTTTTFTT"
// Alternatively, we can replace the second 'F' to make answerKey = "TTFTTTTT". 
// In both cases, there are five consecutive 'T's.

// Constraints:

// n == answerKey.length
// 1 <= n <= 5 * 104
// answerKey[i] is either 'T' or 'F'
// 1 <= k <= n


// Approach 1 - Brute force O(n^2) - Gave me a TLE
// class Solution {
// public:
//     int maxConsecutiveAnswers(string answerKey, int k) {
        
//         int res = INT_MIN;

//         int n= answerKey.size();

//         for(int i=0;i<n;i++){

//             int true_cnt = 0,false_cnt = 0;
//             for(int j=i;j<n;j++){

//                 if(answerKey[j] == 'T') true_cnt++;
//                 else false_cnt++;
//                 if(min(true_cnt,false_cnt) > k) break;

//                 res = max(res,j-i+1);
//             }
//         }

//         return res;
//     }
// };


// Approach 2 - Optimal O(n) using sliding window
// class Solution {
// public:
//     int maxConsecutiveAnswers(string answerKey, int k) {
        
//         int res = INT_MIN;

//         int n= answerKey.size();

//         int true_cnt = 0,false_cnt = 0;
//         int l = 0,r = 0;

//         while(r < n){

//             if(answerKey[r] == 'T') true_cnt++;
//             else false_cnt++;

//             while(l<r && min(true_cnt,false_cnt) > k){
//                 if(answerKey[l] == 'T') true_cnt--;
//                 else false_cnt--;
//                 l++;
//             }

//             //here you come that means min(true_cnt,false_cnt) <= k means this window i can have all of one parity may be all true or all false
//             res = max(res, r-l+1);
//             r++;
//         }

//         return res;
//     }
// };

// --------------------------------------------------------------------------------------------------------------------

// Problem 7 - Count the Number of Good Subarrays

// Given an integer array nums and an integer k, return the number of good subarrays of nums.
// A subarray arr is good if there are at least k pairs of indices (i, j) such that i < j and arr[i] == arr[j].
// A subarray is a contiguous non-empty sequence of elements within an array.

// Example 1:

// Input: nums = [1,1,1,1,1], k = 10
// Output: 1
// Explanation: The only good subarray is the array nums itself.
// Example 2:

// Input: nums = [3,1,4,3,2,2,4], k = 2
// Output: 4
// Explanation: There are 4 different good subarrays:
// - [3,1,4,3,2,2] that has 2 pairs.
// - [3,1,4,3,2,2,4] that has 3 pairs.
// - [1,4,3,2,2,4] that has 2 pairs.
// - [4,3,2,2,4] that has 2 pairs.
 

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i], k <= 109

// class Solution {
// public:
//     long long countGood(vector<int>& nums, int k) {
        
//         long long res = 0;

//         int l = 0,r = 0;

//         int n= nums.size();
        
//         unordered_map<int,int> mpp;

//         long long cnt = 0;
//         while(r < n){

//             cnt = cnt + mpp[nums[r]];
//             mpp[nums[r]]++;

//             while(l <= r && cnt >= k){
//                 mpp[nums[l]]--;
//                 res = res + (n-r);
//                 if(mpp[nums[l]] == 0) mpp.erase(nums[l]);
//                 cnt = cnt - mpp[nums[l]];
//                 l++;
//             }
//             r++;
//         }
//         return res;
//     }

// };


// ---------------------------------------------------------------------------------------------------------------

// Problem 8 - Shortest Subarray With OR at Least K II

// You are given an array nums of non-negative integers and an integer k.
// An array is called special if the bitwise OR of all of its elements is at least k.
// Return the length of the shortest special non-empty subarray of nums, or return -1 if no special subarray exists.

// Example 1:

// Input: nums = [1,2,3], k = 2
// Output: 1
// Explanation:
// The subarray [3] has OR value of 3. Hence, we return 1.

// Example 2:

// Input: nums = [2,1,8], k = 10
// Output: 3
// Explanation:
// The subarray [2,1,8] has OR value of 11. Hence, we return 3.

// Example 3:

// Input: nums = [1,2], k = 0
// Output: 1
// Explanation:
// The subarray [1] has OR value of 1. Hence, we return 1.

// Constraints:

// 1 <= nums.length <= 2 * 105
// 0 <= nums[i] <= 109
// 0 <= k <= 109

// class Solution {
// public:
//     long long countGood(vector<int>& nums, int k) {
        
//         long long res = 0;

//         int l = 0,r = 0;

//         int n= nums.size();
        
//         unordered_map<int,int> mpp;

//         long long cnt = 0;
//         while(r < n){

//             cnt = cnt + mpp[nums[r]];
//             mpp[nums[r]]++;

//             while(l <= r && cnt >= k){
//                 mpp[nums[l]]--;
//                 res = res + (n-r);
//                 if(mpp[nums[l]] == 0) mpp.erase(nums[l]);
//                 cnt = cnt - mpp[nums[l]];
//                 l++;
//             }
//             r++;
//         }
//         return res;
//     }

// };