#include<stdio.h>
int maxTurbulenceSize(int* arr, int arrSize){
    int right=0,left=0,max=1;
    while(right<arrSize-1){
        if(right==left){
            if(arr[right]==arr[right+1])
            left++;
            right++;
        }
        else{
            if((arr[right]>arr[right+1])&&(arr[right-1]<arr[right]))
            right++;
            else if(arr[right]<arr[right+1]&&arr[right-1]>arr[right])
            right++;
            else
            left=right;
        }
        max=(right-left+1)>max?(right-left+1):max;
    }
    return max;
}//窗口滑动，选定三个连续的子数组作为滑动的窗口大小//