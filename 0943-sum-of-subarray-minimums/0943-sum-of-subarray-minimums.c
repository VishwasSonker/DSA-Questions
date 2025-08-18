#define MOD 1000000007

int sumSubarrayMins(int* arr, int arrSize) {
    long long result = 0;
    int *left = (int*)malloc(arrSize * sizeof(int));
    int *right = (int*)malloc(arrSize * sizeof(int));
    
    // Monotonic increasing stack for left
    int *stack = (int*)malloc(arrSize * sizeof(int));
    int top = -1;
    
    for (int i = 0; i < arrSize; i++) {
        while (top >= 0 && arr[stack[top]] > arr[i]) top--;
        if (top == -1)
            left[i] = i + 1;
        else
            left[i] = i - stack[top];
        stack[++top] = i;
    }
    
    // Reset stack for right
    top = -1;
    for (int i = arrSize - 1; i >= 0; i--) {
        while (top >= 0 && arr[stack[top]] >= arr[i]) top--;
        if (top == -1)
            right[i] = arrSize - i;
        else
            right[i] = stack[top] - i;
        stack[++top] = i;
    }
    
    // Contribution
    for (int i = 0; i < arrSize; i++) {
        long long contrib = (long long)arr[i] * left[i] * right[i];
        result = (result + contrib) % MOD;
    }
    
    free(left);
    free(right);
    free(stack);
    return (int)result;
}