class Solution {
public:
    void helper(int index,int dots,string ip,string s,unordered_set<string>& IPs){
        if(dots<0) return ;
        if(dots==0){
            if(index==s.size()){
                cout<<ip<<"\n";
                IPs.insert(ip);
                return ;
            }
        }

        for(int i=1;i<4;++i){
            if(index+i>s.size()) break;
            string sub = s.substr(index,i);
            if((sub[0]=='0' && sub.size()>1) || (stoi(sub)>255)) continue;
            helper(index+i,dots-1,ip+sub+(dots==1?"":"."),s,IPs);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        unordered_set<string> IPs;
        helper(0,4,"",s,IPs);
        vector<string> result(IPs.begin(),IPs.end());
        return result;
    }
};