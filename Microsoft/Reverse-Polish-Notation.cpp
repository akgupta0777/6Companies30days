/*
Explanation:
we are given polish notation in form  of array like
["2","1","+","3","*"]
we can observe that an operator ("+","-","*","/") needs two operands to perform the operation.
Those operands should be the last two before the operator.
For this type of situation A stack is ideal so we used stack.
Stack is used to store only integers not the operators.

Algorithm:
Run a loop to process all tokens.
Check the token
  - If token is operator("+","-","*","/") 
    - Then pop two operands from the stack.
    - Do the required operation ("+","-","*","/").
    - Finally push the result of operation on the stack.
  - Else
    - Simply push that token as string.
Finally we have the last token left in our stack which is our result.
Return the result.
*/



class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> st;
        set<string> operators = {"+","-","*","/"};
        int n = tokens.size();
        long a,b;
        for(int i=0;i<n;++i){
            if(!operators.count(tokens[i])){
                st.push(stoi(tokens[i]));
            }else{
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();
                if(tokens[i]=="+"){
                    st.push(a+b);
                }else if(tokens[i]=="-"){
                    st.push(b-a);
                }else if(tokens[i]=="/"){
                    st.push(b/a);
                }else{
                    st.push(a*b);
                }
            }
        }
        return st.top(); 
    }
};