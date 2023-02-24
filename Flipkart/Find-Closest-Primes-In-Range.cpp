vector<long long> primes = {2};
const int N = 1000001; 
bool isPrime[N] = {}; 
class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        if(primes.size()==1){
            for(long long i=3;i<N;i+=2){
                if(!isPrime[i]){
                    primes.push_back(i);
                    for(long long j=i*i;j<N;j+=i){
                        isPrime[j]=true;
                    }
                }
            }
        }
        int num1=-1,num2=-1;
        int index = lower_bound(primes.begin(),primes.end(),left)-primes.begin();
        for(;index+1<primes.size() && primes[index+1]<=right;++index){
            if(num1==-1 || primes[index+1]-primes[index]<num2-num1){
                num1 = primes[index];
                num2 = primes[index+1];
                if(num2-num1<3) break;
            }
        }
        return {num1,num2};
    }
};