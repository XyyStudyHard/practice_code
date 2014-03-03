class Solution 
{

	public:
    
	int climbStairs(int n) 
	{
        
		vector<int> c(n + 1);
        
		int i;
        
		if (n <= 2) 
           
 			return n;
        
		c[1] = 1;
        
		c[2] = 2;
        
		for (vector<int>::iterator iter = c.begin() + 3; iter != c.end(); iter++)
            
			*iter = *(iter - 1) + *(iter - 2);
        
		return c[n];
    
	}

};