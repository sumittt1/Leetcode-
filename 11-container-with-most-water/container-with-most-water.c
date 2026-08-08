#include <stdio.h>
int maxArea(int* height, int heightsize)
 {
  int left= 0;
  
  int right= heightsize -1;
  int maxArea=0;

  while (left < right ){
    int width = right - left;
    int minheight;
    if (height[left] < height[right]){
        minheight=height[left];
    }
    else {
        minheight=height[right];
    }
    int area=width*minheight;

    if(area > maxArea){
        maxArea=area;
    }
     
    if (height[left]<height[right]){
        left++;
    }
    else{
        right--;
    }

    
   }
    
   return maxArea;
  
}  

