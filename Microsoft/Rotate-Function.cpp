/*
Explanation:
Let the array elements be: [a b c d e].

Length of array represented by N = 5
Sum of elements of array represented by SUM = a + b + c + d + e

Now, as per the question :

F(0) = (0 * a) + (1 * b) + (2 * c) + (3 * d) + (4 * e) = 0 + b + 2c + 3d + 4e
F(1) = (1 * a) + (2 * b) + (3 * c) + (4 * d) + (0 * e) = a + 2b + 3c + 4d + 0
F(2) = (2 * a) + (3 * b) + (4 * c) + (0 * d) + (1 * e) = 2a + 3b + 4c + 0 + e

Now subtracting 2 equations,

F(1) - F(0) = a + b + c + d - 4e = a + b + c + d + e - 5e
Therefore, F(1) = F(0) + a + b + c + d + e - 5e = F(0) + SUM - N*e

F(2) - F(1) = a + b + c + e - 4d = a + b + c + d + e - 5d
Therefore, F(2) = F(1) + a + b + c + d + e - 5d = F(1) + SUM - N*d

Generalizing it, we get the following relation:

F(K) = F(K-1) + SUM - N * (( K-1)th element from end of array)
i.e. F(K) = F(K-1) + SUM - N * (array [N - 1 - (K-1)]) = F(K-1) + SUM - N * (array [N - K])

*/

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sum=0,maxFn,currentFn=0;
        for(int i=0;i<n;++i){
            sum+=nums[i];
            currentFn+=(i*nums[i]);
        }
        maxFn=currentFn;
        for(int i=1;i<n;++i){
            currentFn = currentFn+sum-(n*nums[n-i]);
            maxFn = max(maxFn,currentFn);
        }
        return maxFn;
    }
};