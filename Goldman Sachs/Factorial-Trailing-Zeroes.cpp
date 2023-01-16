/*
Explanation:
The idea is to consider prime factors of a factorial n. A trailing zero is always produced by prime 
factors 2 and 5. If we can count the number of 5s and 2s, our task is done. Consider the following 
examples.
n = 5: There is one 5 and 3 2s in prime factors of 5! (2 * 2 * 2 * 3 * 5). So a count of trailing 0s is 1.
n = 11: There are two 5s and eight 2s in prime factors of 11! (2 8 * 34 * 52 * 7). So the count of 
trailing 0s is 2.

There is one more thing to consider. Numbers like 25, 125, etc have more than one 5. 
For example, if we consider 28! we get one extra 5 and the number of 0s becomes 6. Handling this is 
simple, first, divide n by 5 and remove all single 5s, then divide by 25 to remove extra 5s, and so on. 
Following is the summarized formula for counting trailing 0s.

Trailing 0s in n! = Count of 5s in prime factors of n!
                  = floor(n/5) + floor(n/25) + floor(n/125) + ....'

For more info refer https://www.geeksforgeeks.org/count-trailing-zeroes-factorial-number/
*/

class Solution {
public:
    int trailingZeroes(int n) {
        if(n==0) return n;
        int count=0;
        for(int i=5;n/i>=1;i*=5){
            count+=n/i;
        }
        return count;
    }
};