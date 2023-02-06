class Solution {
public:
    string fractionToDecimal(long numerator, long denominator) {
        if(numerator == 0) return "0";
        unordered_map<long,long> remainders;
        string result;
        //Sign parity checking.
        if(numerator<0 ^ denominator<0) result+='-';
        //Converting to positives both numerator and denominator
        numerator = labs(numerator),denominator = labs(denominator);
        long remainder = numerator%denominator;
        result += to_string(numerator/denominator);
        // In case if it denominator perfectly divides numerator 
        if(remainder==0) return result;
        result+='.';
        for(remainder;remainder;remainder%=denominator){
            // If same remainder is cycling again enclose () and return
            if(remainders.count(remainder)){
                result.insert(remainders[remainder],1,'(');
                result+=")";
                return result;
            }
            // Otherwise keep track of remainders and add the remainder quotient to string.
            remainders[remainder] = result.size();
            remainder*=10;
            result+=to_string(remainder/denominator);
        }
        return result;   
    }
};