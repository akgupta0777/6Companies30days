class Solution {
public:
    
    char transform(int num)
    {
        if (num >= 0 && num <= 9)
            return (char)(num + '0');
        else
            return (char)(num - 10 + 'A');
    }
    
    string convertToBase(int num,int base,string& result){
        int index = 0;
        
        while (num > 0) {
            result.push_back(transform(num % base));
            index++;
            num /= base;
        }
        reverse(result.begin(), result.end());
        return result;
    }
    
    bool isPalindrome(string str){
        int i=0;
        int j = str.size();
        
        for(int i=0;i<j/2;++i)
        {
            if(str[i] != str[j-i-1]){
                return false;
            }
        }
        return true;
    }
    
    bool isStrictlyPalindromic(int n) {
        for(int i = 2;i<=n-2;++i){
            string converted;
            converted = convertToBase(n,i,converted);
            if(!isPalindrome(converted))
                return false;
        }
        return true;
    }
};