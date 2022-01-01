class Solution {
public:
    int smallestRepunitDivByK(int k) {
        
        if( !k%2 || !k%5) return -1;
        
        int remainder = 0;
        for(int counter = 1; counter<=k;counter++)
        {
            remainder = (remainder*10+1)%k;
            if(!remainder) return counter;
        }
        
        return -1;
        
    }
};