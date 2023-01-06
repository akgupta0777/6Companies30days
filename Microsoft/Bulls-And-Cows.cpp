/*
Explanation:
The statement says that bull is a character which matches exactly to the guess position in secret.
and Cows are character which are not in correct position but can be rearranged to form the secret.
If we know the appearance of a character in secret appears before or not we can solve this problem easily

Example 
secret = "1807"
guess = "7810"
Output = "1A3B" (1 bull and 3 Cows)

We can use a freq array to know appearance of a character.

How ?
We will increment count in secret string character in hope of finding the same character that decrements this count
in the guess string.
Similarly we will decrement count in guess string character in hope of finding the same character that increments this count
in the secret string.
In the above Example
'1' is the character in secret string that will be decremented by '1' in guessing string.

Algorithm
Create a vector to store frequencies of characters.
Run a loop until secret length to process all characters.
If we found two same characters at same positions increment bulls.
Else check if the secret character is found by guessing character or vice versa, If yes then increment cows.
Finally construct the string in the order of given output.
Return output string. 
*/

class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> freq(10,0);
        string hint;
        int bulls=0,cows=0;

        for(int i=0;i<secret.size();++i){
            if(guess[i]==secret[i]){
                bulls++;
            }else {
                if(freq[secret[i]-'0']++ < 0) cows++;
                if(freq[guess[i]-'0']-- > 0) cows++;
            }
        }
        hint=to_string(bulls)+"A"+to_string(cows)+"B";
        return hint;
    }
};