/*
633. Sum of Square Numbers
Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.

 

Example 1:

Input: c = 5
Output: true
Explanation: 1 * 1 + 2 * 2 = 5

Example 2:

Input: c = 3
Output: false

 

Constraints:

    0 <= c <= 231 - 1

*/
// O(n) solution
#define ll long long
class Solution
{
public:
    bool judgeSquareSum(int c){
         
        for(ll i=0;i<=sqrt(c);i++){
            ll rm=c-(i*i);
            ll sq=sqrt(rm);
            if(sq*sq==rm){
                return true;
            }
        }
        return false;
    }
};
//Two Pointer:
#define ll long long
class Solution
{
public:
    bool judgeSquareSum(int c){
        ll r=sqrt(c), l=0;
        while(l<=r){
                ll lr=(l*l)+(r*r);
            if(lr==c){
                return true;
            }
            if(lr<c){
                l++;
            }
            else{
                r--;
            }
        }
        return false;
    }
};

