//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        int n = x.size();
        stack <char> s;
        if(n==0){return true;}
        for(int i = 0 ;i < n; i++){
            if(x[i] == '{' || x[i] == '(' || x[i] == '['){
                s.push(x[i]);
            }
            else if((x[i] == '}' || x[i] == ')' || x[i] == ']' ) && s.empty() ){
                return false;
            }
            else if(x[i] == '}'){
                if(s.top() != '{'){return false;}
                s.pop();
            }
            else if(x[i] == ']'){
                if(s.top() != '['){return false;}
                s.pop();
            }
            else if(x[i] == ')'){
                if(s.top() != '('){return false;}
                s.pop();
            }
        }
        if(s.empty()){return true;}
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends
