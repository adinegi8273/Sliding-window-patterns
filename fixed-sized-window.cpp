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