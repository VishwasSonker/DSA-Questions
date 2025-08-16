int maximum69Number (int num) {
    int digits[5], n = 0;
    int temp = num;

    // store digits in reverse order
    while (temp > 0) {
        digits[n++] = temp % 10;
        temp /= 10;
    }

    // traverse from most significant digit
    for (int i = n-1; i >= 0; i--) {
        if (digits[i] == 6) {
            digits[i] = 9;
            break;
        }
    }

    // rebuild number
    int result = 0;
    for (int i = n-1; i >= 0; i--) {
        result = result * 10 + digits[i];
    }

    return result;
}