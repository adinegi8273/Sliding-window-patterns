// Problem 1 -Find all anagrams in a string

// You have given 2 strings s and p and you must return vector of integers which are startiung indices of substrings which are anagrams of string p in string s.


// class Solution {
// public:
//     vector<int> findAnagrams(string s, string p) {
        
//         vector<int> alpha(26,0);

//         int n = s.size();
//         int m = p.size();

//         for(int i=0;i<m;i++){//O(M)
//             alpha[p[i] - 'a']++;
//         }

//         vector<int> temp_alpha;

//         vector<int> res;
//         for(int i=0;i<=n-m;i++){//O(N-M)
            
//             temp_alpha = alpha;
//             bool flag = true;
//             for(int j=i;j<i+m;j++){//O(M)
                
//                 if(temp_alpha[s[j]-'a'] > 0){
//                     temp_alpha[s[j] - 'a']--;
//                 }
//                 else{
//                     flag = false;
//                     break;
//                 }

//             }

//             if(flag == false) continue;

//             //it means that the sub-string s[i...i+m-1] is an anaglram of string p
//             res.push_back(i); 
//         }

//         return res;
//     }
// };

//A little optimal - Using sliding window

// class Solution {
// public:
//     vector<int> findAnagrams(string s, string p) {
        
//         int n = s.size();
//         int m = p.size();

//         int l = 0,r = 0;
        
//         vector<int> alpha(26,0);
//         vector<int> temp_alpha(26,0);

//         for(char ch:p){
            
//             alpha[ch-'a']++;
//         }

//         vector<int> res;
//         while(r < n){
            
//             temp_alpha[s[r]-'a']++;

//             if(r-l+1 > m){

//                 char charToRemove = s[l];
//                 temp_alpha[charToRemove - 'a']--;
//                 l++;
//             }

//             if(r-l+1 == m){
//                 //that means now we have to investigate whether this subrtring is an anagram or not
                
//                 bool flag = true;
//                 for(int i=0;i<26;i++){
//                     //now check whether the charcater and its freq is present in temp_alpha or not

//                     if(alpha[i] != temp_alpha[i]){
//                         flag = false;
//                         break;
//                     }
//                 }

//                 if(flag == true){
//                     //it mean that this substring whose starting index is l is an anagram of p
//                     res.push_back(l);
//                 }
//             }
//             r++;
//         }

//         return res;


        
//     }
// };

// ---------------------------------------------------------------------------------------------------------

// Problem 2- Minimum number opf k consequtive bit flips

// I have a binary integer array in one flip i can k-sized subarray flip the numbers ie 1->0 and 0->1.
// Determine minimum number of such operationss required to convert the binary array into all 1's at last.

// Approach 1 - Gave TLE

// int minKBitFlips(vector<int>& nums, int k) {
//         int n = nums.size();
        
//         int l = 0, r = k - 1;
//         int operations = 0;

//         // Sliding window
//         while (r < n) {
//             // If leftmost bit is 0, flip the window
//             if (nums[l] == 0) {
//                 for (int i = l; i <= r; i++) {
//                     nums[i] = 1 - nums[i];
//                 }
//                 operations++;
//             }
//             l++;
//             r++;
//         }

//         // Check remaining elements
//         for (int i = l; i < n; i++) {
//             if (nums[i] == 0) {
//                 return -1;
//             }
//         }

//         return operations;
// }


// Approach 2 - O(n) time optimal solution got Accepted

// int minKBitFlips(vector<int>& nums, int k) {
        
//         int n = nums.size();
//         priority_queue<int,vector<int>,greater<int>> pq;

//         int index = 0;

//         int res = 0;
//         while(index < n-k+1){

//             if(!pq.empty() && pq.top() < index){
//                 pq.pop();//remove the last effective index if it is smaller than index
//             }

//             int flip_cnt = pq.size();

//             int number = (nums[index] + flip_cnt)%2;

//             if(number == 0){
//                 //ye number after flipping zero ke equal ban jaega so we mustr flip hte k sized winsow from heere
//                 pq.push(index+k-1);//push tthe last effective index into min heap
//                 res++;
//             }

//             index++;
//         }

//         for(int index = n-k+1;index < n;index++){

//             if(!pq.empty() && index > pq.top()){
//                 pq.pop();
//             }

//             int flip_cnt = pq.size();

//             int number = (nums[index] + flip_cnt)%2;

//             if(number == 0){
//                 //but now you cant flip the k subarray so we will not able to achieve an array which contains all 1's
//                 return -1;
//             }
        
//         }

//         return res;
// }


// ------------------------------------------------------------------------------------------------------------

// Problem 3 - Number of subarrays of size k and average greater than or equal to threshold

// Given an array of integers arr and two integers k and threshold, return the number of sub-arrays of size k and average greater than or equal to threshold.
 
// Example 1:

// Input: arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4
// Output: 3
// Explanation: Sub-arrays [2,5,5],[5,5,5] and [5,5,8] have averages 4, 5 and 6 respectively. All other sub-arrays of size 3 have averages less than 4 (the threshold).
// Example 2:

// Input: arr = [11,13,17,23,29,31,7,5,2,3], k = 3, threshold = 5
// Output: 6
// Explanation: The first 6 sub-arrays of size 3 have averages greater than 5. Note that averages are not integers.
 

// Constraints:

// 1 <= arr.length <= 105
// 1 <= arr[i] <= 104
// 1 <= k <= arr.length
// 0 <= threshold <= 104


// class Solution {
// public:
//     int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        

//         int sum = 0;
//         int l = 0,r = 0;
//         int n = arr.size();
//         int res = 0;
//         while(r < n){
//             sum = sum + arr[r];

//             if(r-l+1 > k){
//                 sum = sum - arr[l];
//                 l++;
//             }
//             if(r-l+1 == k && sum >= threshold*k){
//                 res++;
//             }
//             r++;
//         }


//         return res;
//     }
// };

// -----------------------------------------------------------------------------------------------------------------------

// Problem 4 - Substrings of Size Three with Distinct Characters

// A string is good if there are no repeated characters.

// Given a string s​​​​​, return the number of good substrings of length three in s​​​​​​.

// Note that if there are multiple occurrences of the same substring, every occurrence should be counted.

// A substring is a contiguous sequence of characters in a string.

 

// Example 1:

// Input: s = "xyzzaz"
// Output: 1
// Explanation: There are 4 substrings of size 3: "xyz", "yzz", "zza", and "zaz". 
// The only good substring of length 3 is "xyz".
// Example 2:

// Input: s = "aababcabc"
// Output: 4
// Explanation: There are 7 substrings of size 3: "aab", "aba", "bab", "abc", "bca", "cab", and "abc".
// The good substrings are "abc", "bca", "cab", and "abc".
 

// Constraints:

// 1 <= s.length <= 100
// s​​​​​​ consists of lowercase English letters.


// class Solution {
// public:
//     int countGoodSubstrings(string s) {
        

//         int n = s.size();

//         if(n == 1 || n==2) return 0;//0 3 elngth subtrings
//         int count = 0;
//         for(int i=2;i<n;i++){
            
//             if((s[i-1] != s[i]) && (s[i-1] != s[i-2]) && (s[i] != s[i-2])){
//                 //this is a 3 length substring which conatins uniue characters
//                 count++;
//             }
//         }

//         return count;
//     }
// };


// ------------------------------------------------------------------------------------------------------------------

// Problem 4 - Alternating Groups I

// There is a circle of red and blue tiles. You are given an array of integers colors. The color of tile i is represented by colors[i]:
 
// colors[i] == 0 means that tile i is red.
// colors[i] == 1 means that tile i is blue.
// Every 3 contiguous tiles in the circle with alternating colors (the middle tile has a different color from its left and right tiles) is called an alternating group.

// Return the number of alternating groups.

// Note that since colors represents a circle, the first and the last tiles are considered to be next to each other.

 

// Example 1:

// Input: colors = [1,1,1]

// Output: 0

// Example 2:

// Input: colors = [0,1,0,0,1]

// Output: 3
 

// Constraints:

// 3 <= colors.length <= 100
// 0 <= colors[i] <= 1


// class Solution {
// public:
//     int numberOfAlternatingGroups(vector<int>& colors) {
        
//         int n = colors.size();
//         int cnt = 0;

//         for(int i=1;i<n-1;i++){
//             //considering these indices as the middle elements
//             if(colors[i] != colors[i-1] && colors[i] != colors[i+1]) cnt++;
//         }

//         //checking for 0 index as middle possible or not
//         if(colors[1] != colors[0] && colors[0] != colors[n-1]) cnt++;

//         //checking for n-1 index as middle possible or not
//         if(colors[n-1] != colors[n-2] && colors[n-1] != colors[0]) cnt++;

//         return cnt;
//     }
// };


// ---------------------------------------------------------------------------------------------------------------------

// Problem 5 - 3439. Reschedule Meetings for Maximum Free Time I

// You are given an integer eventTime denoting the duration of an event, where the event occurs from time t = 0 to time t = eventTime.
// You are also given two integer arrays startTime and endTime, each of length n. These represent the start and end time of n non-overlapping meetings, where the ith meeting occurs during the time [startTime[i], endTime[i]].
// You can reschedule at most k meetings by moving their start time while maintaining the same duration, to maximize the longest continuous period of free time during the event.
// The relative order of all the meetings should stay the same and they should remain non-overlapping.
// Return the maximum amount of free time possible after rearranging the meetings.
// Note that the meetings can not be rescheduled to a time outside the event.

// Example 1:

// Input: eventTime = 5, k = 1, startTime = [1,3], endTime = [2,5]

// Output: 2

// Reschedule the meeting at [1, 2] to [2, 3], leaving no meetings during the time [0, 2].

// Example 2:

// Input: eventTime = 10, k = 1, startTime = [0,2,9], endTime = [1,4,10]

// Output: 6

// Reschedule the meeting at [2, 4] to [1, 3], leaving no meetings during the time [3, 9].

// Example 3:

// Input: eventTime = 5, k = 2, startTime = [0,1,2,3,4], endTime = [1,2,3,4,5]

// Output: 0

// Explanation:

// There is no time during the event not occupied by meetings.

 

// Constraints:

// 1 <= eventTime <= 109
// n == startTime.length == endTime.length
// 2 <= n <= 105
// 1 <= k <= n
// 0 <= startTime[i] < endTime[i] <= eventTime
// endTime[i] <= startTime[i + 1] where i lies in the range [0, n - 2].


// class Solution {
// public:
//     int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        

//         vector<int> free;
//         int n = startTime.size();
//         int prev = 0;
//         for(int i=0;i<n;i++){

//             int gap = startTime[i] - prev;
//             prev = endTime[i];
//             free.push_back(gap);
//         }
//         if(eventTime - endTime[n-1] > 0){
//             free.push_back(eventTime - endTime[n-1]);
//         }
//         //now iof i want to maximize this free time i must find the maximum sum of k+1 sized window or subarray opf free
//         k = k+1; 
//         int maxSum = INT_MIN;
//         int sum = 0;

//         int l = 0,r = 0;

//         while(r < free.size() && r<k){
//             sum = sum + free[r];
//             r++;
//         }
//         maxSum = max(maxSum,sum);
//         while(r<free.size()){
            
//             sum = sum + free[r];
//             sum = sum - free[l];

//             maxSum = max(maxSum,sum);
//             l++;
//             r++;
//         }

//         return maxSum;
        
//     }
// };