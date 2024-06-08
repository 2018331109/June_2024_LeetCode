/*
846. Hand of Straights
Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.

Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.

 

Example 1:

Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]

Example 2:

Input: hand = [1,2,3,4,5], groupSize = 4
Output: false
Explanation: Alice's hand can not be rearranged into groups of 4.

 

Constraints:

    1 <= hand.length <= 104
    0 <= hand[i] <= 109
    1 <= groupSize <= hand.length
*/
// O(nlogn + n*m) solution:
class Solution {
public:
    int n, m;
    bool check(vector<int>& hand, int m, int i)
    {
        int x=hand[i], cnt=1;
        hand[i]=-1, i+=1;
        while(i<n and cnt<m)
        {
            if(hand[i]==x+1) cnt++, x++, hand[i]=-1;
            i++;
        }
        if(cnt==m) return true;
        return false;
    }
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        n=hand.size(), m=groupSize;
        if(n%m != 0) return false;
        sort(hand.begin(), hand.end());
        for(int i=0;i<n;i++)
        {
            if(hand[i]!=-1) 
            {
                if(!check(hand, m, i)) return false;
            }
        }
        return true;
    }
};

//using map:
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int m) {
        int n=hand.size();
        if(n%m!=0) return false;

        map<int, int>mp;
        for(auto it:hand) mp[it]++;
        while(!mp.empty())
        {
            int now=mp.begin()->first;
            for(int i=0;i<m;i++)
            {
                if(mp[now+i]==0) return false;
                mp[now+i]--;
                if(mp[now+i]==0) mp.erase(now+i);
            }
        }
        return true;
    }
};

