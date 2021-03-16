bool checkPossibility(int* nums, int numsSize){
    bool sign = false;
   for(int i=0;i<numsSize-1;i++){
        if(nums[i]>nums[i+1]){
            if(sign){
                return false;
            }
            if(i>0&&i<numsSize-2 && nums[i]>nums[i+2]&&nums[i-1]>nums[i+1]){
            return false;
            }
        sign = true;
        }
    }
    return true;
}


bool checkPossibility(int* nums, int numsSize){
    int i,cnt=0;
    for (i=0;i<numsSize-1&&cnt<2;i++) {
        if (nums[i]>nums[i+1]){
            cnt++;
            if (i>0&&nums[i+1]<nums[i-1]){
                nums[i+1]=nums[i];
            }else{
                nums[i]=nums[i+1];
            }
        }
    }
    if(cnt<2)
    return true;
    else
    return false;
}