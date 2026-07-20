class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0;

     int  i=1 ;
     int j= x;
      int mid=0;

      
     while(i<=j){

        mid= i+(j-i)/2;
        if(mid ==x/mid ){
           return mid;
        }
        else if( mid >x/mid){
            j= mid-1;

        }
        else{
            i= mid +1;
        }

     }

   return j;
        
    }
};