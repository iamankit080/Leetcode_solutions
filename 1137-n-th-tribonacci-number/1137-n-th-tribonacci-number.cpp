class Solution {
public:
    int tribonacci(int n) {
     int fun[38];
        fun[0]=0;
        fun[1]=1;
        fun[2]=1;
        for(int i=3; i<=n; i++){
            fun[i]= fun[i-1] +fun[i-2] + fun[i-3];
        }return fun[n];
   
    }
};