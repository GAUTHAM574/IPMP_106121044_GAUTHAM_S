//Solution one :
class Solution1
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        vector<int> res;
        priority_queue<int , vector<int>, greater<int> > hp ;
        for(int i = 0; i < k; i++){
            for(int j = 0; j < k; j++){hp.push(arr[i][j]);}
        }
        while(!hp.empty()){
            res.push_back(hp.top());
            hp.pop();
        }
        return res;
    }
};




// Solution Two :


class Solution2
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        vector<int> res;
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> > hp ;
        map<int,int> m;
        for(int i = 0; i < k; i++){
            hp.push({arr[i][0], i});
            m[i] = 0;
        }
        while(!hp.empty()){
            res.push_back(hp.top().first);
            int i = hp.top().second;
            m[i] ++;
            hp.pop();
            if( m[i] <= k-1){
                hp.push({arr[i][m[i]] , i});
            }
        }
        return res;
    }
};
