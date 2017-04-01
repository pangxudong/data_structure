int maxSubArray(int* nums, int numsSize) {
    int *S;
    S = (int*)malloc((numsSize+5) * sizeof(int) );
    int i,j;
    int best = nums[0];
    S[0] = 0;
    
    for (i=1; i<=numsSize; i++) {
        S[i] = S[i-1] + nums[i-1];
    }
    for (i=1; i<=numsSize; i++) {
        for (j=i; j<=numsSize; j++) {
            best = best > (S[j]-S[i-1]) ? best : (S[j]-S[i-1]);
        }
    }
    free(S);
    return best;
}
