class Solution
{
    public:
    //Function to insert heap.
    priority_queue<int> a, b;
    void insertHeap(int &x)
    {
        a.push(x);
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        int temp = a.top();
        a.pop();
        b.push(0 - temp);
        if( b.size() > a.size() ){
            int temp = b.top();
            b.pop();
            a.push(0 - temp);
        } 
    }
    
    //Function to return Median.
    double getMedian()
    {
        if( a.size() == b.size() ){
            return ((double)a.top() - (double)b.top() )/2;
        }
        return a.top();
    }
};
