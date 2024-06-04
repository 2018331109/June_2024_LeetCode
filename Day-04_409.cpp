/*
409. Longest Palindrome
Given a string s which consists of lowercase or uppercase letters, return the length of the longest
palindrome
 that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome.
*/
class Solution {
public:
    int longestPalindrome(string s) {
        vector<int>v(60, 0);
        for(auto it:s) v[it-'A']++;
        int mx=0, ans=0;
        for(int i=0;i<60;i++)
        {
            if(v[i]%2) mx=1;
            ans+=(v[i]/2)*2;
        }
        return ans+mx;
    }
};
