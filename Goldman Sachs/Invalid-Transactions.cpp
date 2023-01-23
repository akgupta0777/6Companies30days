/*
Explanation:
Its Brute Force since constraints are low but a ideal solution will be a Object Oriented One. Try to solve
it by OOP.
*/

class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        int n = transactions.size();
        vector<string> invalid;
        vector<int> time(n),money(n);
        vector<string> name(n),city(n);
        vector<bool> add(n,false);
        for(int i=0;i<n;++i){
            string x;
            stringstream ss(transactions[i]);
            int count = 0;
            while(!ss.eof() && count++ < 4){
                getline(ss,x,',');
                if(count==1){
                    name[i]=x;
                }else if(count==2){
                    time[i]=stoi(x);
                }else if(count==3){
                    money[i]=stoi(x);
                }else{
                    city[i]=x;
                }
            }
        }
        for(int i=0;i<n;++i){
            if(money[i]>1000) add[i]=true;
            for(int j=i+1;j<n;++j){
                if(name[i]==name[j] && abs(time[i]-time[j])<=60 && city[i]!=city[j]){
                    add[i] = add[j] = true;
                }
            }
        }

        for(int i=0;i<n;++i){
            if(add[i])
                invalid.push_back(transactions[i]);
        }
        return invalid;
    }
};