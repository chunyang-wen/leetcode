class Solution {
public:
    bool canJump(int A[], int n) {
        // if (!A) return true;
         if(n<2)return true;
     int level=0,currentMax=0,i=0,nextMax=0;

     while(currentMax-i+1>0){       //nodes count of current level>0
         level++;
         for(;i<=currentMax;i++){   //traverse current level , and update the max reach of next level
            nextMax=max(nextMax,A[i]+i);
            if(nextMax>=n-1)return true;   // if last element is in level+1,  then the min jump=level 
         }
         currentMax=nextMax;
     }
     return 0;
    }
};