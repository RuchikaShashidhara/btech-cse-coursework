#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper functions
static void intal_merge(char **, int, int, int); 
static void intal_merge_sort(char **, int, int); 

// Returns the sum of two intals.
char* intal_add(char* intal1, char* intal2) 
{
    //intal length calculations
    int intal1_len = strlen(intal1);
    int intal2_len = strlen(intal2);
    int max_res_len, min_res_len, intal1_diff, intal2_diff;    
    if(intal1_len > intal2_len)
        max_res_len = intal1_len;
    else
        max_res_len = intal2_len;    
    if(intal1_len < intal2_len)
        min_res_len = intal1_len;
    else
        min_res_len = intal2_len;  
    if(intal1_len >= intal2_len)
        intal1_diff = 0;
    else
        intal1_diff = intal2_len - intal1_len;
    if(intal2_len >= intal1_len)
        intal2_diff = 0;
    else
        intal2_diff = intal1_len - intal2_len;  
    int *res = (int *)calloc((max_res_len + 1), sizeof(int));
    int i, carry = 0;
    //adding commaon digits of intal1 and intal2
    for(i = max_res_len - 1; i >= max_res_len - min_res_len; i--)
    {
        int index1_num = (int)intal1[i - intal1_diff] - 48;
        int index2_num = (int)intal2[i - intal2_diff] - 48;
        int res_sum = index1_num + index2_num + carry;
        int res_index = res_sum % 10;
        res[i] = res_index;
        carry = (res_sum - res_index) / 10;
    }
    //adding remaining digits that were left out
    for(i = max_res_len - min_res_len - 1; i >= 0; i--) 
    {
        if(intal2_diff)
        {
            int index1_num = (int)intal1[i - intal1_diff] - 48;
            int res_sum = index1_num + carry;
            int res_index = res_sum % 10;
            res[i] = res_index;
            carry = (res_sum - res_index) / 10;
        }
        else 
        {
            int index2_num = (int)intal2[i - intal2_diff] - 48;
            int res_sum = index2_num + carry;
            int res_index = res_sum % 10;
            res[i] = res_index;
            carry = (res_sum - res_index) / 10;
        }
    }
    //adding the final carry if produced
    char *answer;
    int j = 0;
    if(carry) 
    {
        answer = (char *)calloc((max_res_len + 2), sizeof(char));
        answer[0] = (char)(carry + 48);
        j = 1;
    }
    else 
    {
        answer = (char *)calloc(max_res_len + 1, sizeof(char));
    }
    for(i = j; i < max_res_len + j; i++)
        answer[i] = (char)(res[i - j] + 48);
    free(res);
    //returning the sum of intal1 and intal2
    return answer;
}

// Returns the comparison value of two intals.
// Returns 0 when both are equal.
// Returns +1 when intal1 is greater, and -1 when intal2 is greater.
int intal_compare(char* intal1, char* intal2) 
{
    int intal1_len = strlen(intal1);
    int intal2_len = strlen(intal2);
    int i;
    //intal1 is greater
    if(intal1_len > intal2_len)
        return 1;
    //intal2 is greater    
    else if(intal1_len < intal2_len)
        return -1;
    //intal1 and intal2 have equal length    
    else
    {
        for(i= 0; i < intal1_len; i++) 
        {
            //intal1 is greater
            if((int)intal1[i] > (int)intal2[i])
                return 1;
            //intal2 is greater    
            else if((int)intal1[i] < (int)intal2[i])
                return -1;
        }
    }  
    //intal1 and intal2 are equal          
    return 0;    
}

// Returns the difference (obviously, nonnegative) of two intals.
char* intal_diff(char* intal1, char* intal2) 
{
    //intal length calculations
    int big_check = intal_compare(intal1, intal2);
    if (big_check == 0) 
    {
        char *ans = (char *)calloc(1, sizeof(char));
        ans[0] = '0';
        return ans;
    }
    //finding the larger and smaller number of the intals      
    char *smaller_num;
    char *larger_num;
    if(big_check == 1)
        larger_num = intal1;
    else
        larger_num = intal2;
    if(big_check == -1)
        smaller_num = intal1;
    else
        smaller_num = intal2;       
    int larger_num_len = strlen(larger_num);
    int smaller_num_len = strlen(smaller_num);
    int diff_in_length = larger_num_len - smaller_num_len;
    int *res = (int *)calloc(larger_num_len + 1, sizeof(int));
    int carry = 0, i;
    //finding the difference between the current digits of 
    //larger num - smaller number
    for(i = larger_num_len - 1; i >= diff_in_length; i--) 
    {
        int apply_carry = 0;
        if((int)larger_num[i] - carry < (int)smaller_num[i - diff_in_length]) 
            apply_carry = 1;
        res[i] = (int)larger_num[i] - (int)smaller_num[i - diff_in_length] - carry + 10 * apply_carry;
        carry = apply_carry;
    }
    //accouting of intals of differnent length and carry/borrow
    for (i = diff_in_length - 1;  i >= 0; i--) 
    {
        if ((int)larger_num[i] == 48 && carry == 1) 
        {
            res[i] = 9;
        }
        else 
        {
            res[i] = (int)larger_num[i] - carry - 48;
            carry = 0;
        }
    }
    //removing the preceding 0's if present
    int answer_len = 0;
    int first_nonzero_digit;
    for(first_nonzero_digit = 0; first_nonzero_digit < larger_num_len && res[first_nonzero_digit] == 0; first_nonzero_digit++);
    answer_len = larger_num_len - first_nonzero_digit;
    char *answer = (char *)calloc(answer_len + 1, sizeof(char));
    for(i = 0; i < answer_len; i++) 
        answer[i] = (char)(res[i + first_nonzero_digit] + 48);
    free(res);
    //returning the absolute value of the difference of intal1 and intal2
    return answer;    
}

// Returns the product of two intals.
char* intal_multiply(char* intal1, char* intal2) 
{
    //intal length calculations
    char *sum = (char *)calloc(2, sizeof(char));
    sum[0] = '0';
    int intal1_len = strlen(intal1);
    int intal2_len = strlen(intal2);
    if(intal1_len == 1 && intal1[0] == '0')
        return sum;
    if(intal2_len == 1 && intal2[0] == '0')
        return sum;
    int i, j;
    for(i = intal1_len - 1; i >= 0; i--) 
    {
        int *product = (int *)calloc(intal2_len + 1, sizeof(int));
        int carry = 0;
        int digit = (int)(intal1[i]) - 48;
        //multiplying each digit of intal2 and shiting the digits
        for(j = intal2_len - 1;  j >= 0; j--) 
        {
            int temp = ((int)(intal2[j]) - 48) * digit + carry;
            product[j] = temp % 10;
            carry = temp / 10;
        }
        char *res;
        //accounting for the carry into res, if occured
        if(carry) 
        {
            res = (char *)calloc(intal2_len + intal1_len - i + 1, sizeof(char));
            res[0] = (char)(carry + 48);
            carry = 1;
        }
        else 
        {
            res = (char *)calloc(intal2_len + intal1_len - i + 1, sizeof(char));
        }
        //accounting for the digits remaining after shifting
        for(j = carry; j < carry + intal2_len + intal1_len - 1 - i; j++) 
        {
            if(j < (carry + intal2_len))
                res[j] = (char)(product[j - carry] + 48);
            else
                res[j] = '0';
        }
        char *temp = intal_add(res, sum);
        free(sum);
        free(res);
        sum = temp;
        free(product);
    }
    //returning the product of intal1 and intal2
    return sum;
}

// Returns intal1 mod intal2.
char* intal_mod(char* intal1, char* intal2) 
{
    char *intal1_num = (char *)calloc(strlen(intal1) + 1, sizeof(char));
    int i;
    for(i = 0; i < strlen(intal1); i++) 
        intal1_num[i] = intal1[i];
    char *intal2_num;
    do{
        int check = intal_compare(intal1_num, intal2);
        if(check == 0) 
        {
            char *answer = (char *)calloc(2, sizeof(char));
            answer[0] = '0';
            free(intal1_num);
            //returning intal1 mod intal2
            return answer;
        }
        else if (check == -1) 
        {
            //intal1 is smaller than intal2
            return intal1_num;
        }
        else 
        {
            //performing repeated subtractions until 0 <= intal1 <= intal2
            int intal1_len = strlen(intal1_num);
            int intal2_len = strlen(intal2);
            intal2_num = (char *)calloc(1 + intal2_len, sizeof(char));
            for(int i = 0; i < intal2_len; i ++) 
                intal2_num[i] = intal2[i];
            if(intal1_len > intal2_len) 
            {

                intal2_num = (char *)calloc(intal1_len + 1, sizeof(char));
                for(int i = 0; i < intal1_len; i++) 
                {
                    if(i < intal2_len)
                        intal2_num[i] = intal2[i];
                    else
                        intal2_num[i] = '0';    
                }
                check = intal_compare(intal1_num, intal2_num);
                if(check == -1) 
                    intal2_num[intal1_len - 1] = '\0';
            }
            char *temp = intal_diff(intal1_num, intal2_num);
            free(intal1_num);
            free(intal2_num);            
            intal1_num = temp;
        }        
    } while(1);
}

// Returns intal1 ^ intal2.
char* intal_pow(const char* intal1, unsigned int n) 
{
    int intal1_len = strlen(intal1); 
    char *answer;
    int i; 
    //intal1 ^ 1      
    if(n == 1) 
    {
        answer = (char *)calloc(intal1_len + 1, sizeof(char));
        for(i = 0; i < intal1_len; i++) 
            answer[i] = intal1[i];
    }
    //intal1 ^ 0
    else if(n == 0)
    {
        answer = (char *)calloc(2, sizeof(char));
        answer[0] = '1';
    }
    //intal1 ^ n
    else
    {
        char *part1;
        char *part2;
        //n is even
        if(n % 2 == 0) 
        {
            //calculation of a^n = (a^n/2)*(a^n/2)
            part1 = intal_pow(intal1, n / 2);
            part2 = part1;
            answer = intal_multiply(part1, part1);        
            free(part1);
        }
        //n is odd
        else 
        {        
            //calculation of a^n = (a^(n-1)/2)*(a^(n+1)/2)
            part1 = intal_pow(intal1, (n - 1) / 2);
            part2 = intal_pow(intal1, (n + 1) / 2);
            answer = intal_multiply(part1, part2);
            free(part1);
            free(part2);   
        }
    }   
    //returning intal1 ^ n
    return answer;
}

// Returns Greatest Common Devisor of intal1 and intal2.
char* intal_gcd(const char* intal1, const char* intal2)
{
    //Euclid's algorithm
    //finding lengths and storing new intal1 and intal2 for caluculations
    int intal1_len = strlen(intal1);
    int intal2_len = strlen(intal2);
    char *intal1_num = (char *)calloc(intal1_len + 1, sizeof(char));
    char *intal2_num = (char *)calloc(intal2_len + 1, sizeof(char));
    int i;
    for(i = 0; i < intal1_len; i++) 
        intal1_num[i] = intal1[i];
    for(i = 0; i < intal2_len; i++) 
        intal2_num[i] = intal2[i];
    //base case        
    if(strcmp(intal1_num, "0") * strcmp(intal2_num, "0") == 0) 
    {
        char *answer = (char *)calloc(2, sizeof(char));
        answer[0] = '0';
        return answer;
    }
    //calculation of gcd(intal1, intal2) = gcd(intal2, intal_mod(intal1, intal2))
    char* mod = intal_mod(intal1_num, intal2_num);
    if(strcmp(mod, "0") == 0)     
        return intal2_num;
    char *temp = intal_mod(intal1_num, intal2_num);
    char *answer = intal_gcd(intal2_num, temp);
    free(temp);
    free(intal1_num);
    free(intal2_num);
    free(mod);
    //returning gcd(intal1, intal2)
    return answer;
}

// Returns nth fibonacci number.
char* intal_fibonacci(unsigned int n) 
{
    char *num0 = (char *)calloc(2, sizeof(char));        
    char *num1 = (char *)calloc(2, sizeof(char));
    char *num2 = (char *)calloc(2, sizeof(char)); 
    num0[0] = '0';      
    num1[0] = '1';
    num2[0] = '1';
    //base cases
    if(n == 0)
        return num0;
    else if(n == 1) 
        return num1;
    else if(n == 2)
        return num2;
    //calculations of Fn = Fn-1 + Fn-2 i.e. num3 = num1 + num2
    else
    {
        char *num3;    
        int i;    
        for(i = 3; i <= n; i++) 
        {
            num3 = intal_add(num1, num2);
            free(num1);
            num1 = num2;
            num2 = num3;
        }
        free(num1);
        //returning the nth fibonacci number
        return num3;
    }        
}

// Returns the factorial of n.
char* intal_factorial(unsigned int n) 
{
    char *answer = (char *)calloc(2, sizeof(char));
    answer[0] = '1';
    //base case
    if(n <= 1)
        return answer;
    //calculation of n * factorial(n -1)    
    int digits = 0;
    int temp = n;
    while(temp > 0) 
    {
        digits++;
        temp /= 10;
    }
    char* num = (char *)calloc(1 + digits, sizeof(char));
    int i = digits - 1;
    for(temp = n; temp > 0;temp /= 10, i--)  
        num[i] = (temp % 10 + 48);
    char* new_answer = intal_factorial(n-1);
    free(answer);
    answer = intal_multiply(new_answer, num);
    free(new_answer);
    free(num);
    //returning factorial(n)
    return answer;
}

// Returns the Binomial Coefficient C(n,k).
char* intal_bincoeff(unsigned int n, unsigned int k) 
{
    if(k > n/2)
        k = n - k;
    //creating a table to calculate C(n,k) using DP    
    char **table = (char **)calloc(k + 2, sizeof(char *));
    int i;
    for(i = 0; i <= k;  i++) 
    {
        char *num_0 = (char *)calloc(2, sizeof(char));
        num_0[0] = '0';
        table[i] = num_0;
    }
    char *num_1 = (char *)calloc(2, sizeof(char));
    num_1[0] = '1';
    table[0] = num_1;
    //filling the table 
    for(int i = 1; i <= n;  i++) 
    {
        int depth = n - i, j;
        int start_index = k - depth, end_index = k;
        if(start_index < 1)
            start_index = 1;
        if(end_index > i)
            end_index = i;
        for(j = end_index; j >=start_index; j--) 
        {
            char *temp = intal_add(table[j], table[j-1]);
            free(table[j]);
            table[j] = temp;
        }
    }
    char *answer = (char *)calloc(strlen(table[k]) + 1, sizeof(char));
    strcpy(answer, table[k]);
    for(int i = 0; i < k+1;  i++)
        free(table[i]);
    free(table);
    //returning the value of table[k]
    return answer;
}

// Returns the offset of the largest intal in the array.
int intal_max(char **arr, int n) 
{
    int max_index = 0, i;
    for(i = 0; i < n; i++) 
    {
        //updating the index of the larger number
        if(intal_compare(arr[i], arr[max_index]) == 1) 
            max_index = i;
    }
    //returning the offset of the largest number
    return max_index;
}

// Returns the offset of the smallest intal in the array.
int intal_min(char **arr, int n) 
{
    int min_index = 0, i;
    for(i = 0; i < n; i++) 
    {
        //updating the index of the smaller number
        if(intal_compare(arr[i], arr[min_index]) == -1) 
            min_index = i;
    }
    //returning the offset of the smallest number
    return min_index;
}

// Returns the offset of the first occurrence of the key intal in the array.
int intal_search(char **arr, int n, const char* key) 
{
    //Linear Serch algorithm of any intal array
    int key_len = strlen(key), i;
    char *num = (char *)calloc(key_len + 1, sizeof(char));
    for(i = 0; i < key_len; i++)     
        num[i] = key[i];
    for(i = 0; i < n; i++) 
    {
        if(intal_compare(arr[i], num) == 0) 
        {
            free(num);
            //returning the offset of the first occurence of key intal
            return i;
        }
    }
    free(num);
    //returning -1 as the key is not found
    return -1;
}

// Returns the offset of the first occurrence of the key intal in the SORTED array.
int intal_binsearch(char **arr, int n, const char* key) 
{
    //Binary Serach algorithm for a sorted intal array
    int key_len = strlen(key), i;
    char *num = (char *)calloc(key_len + 1, sizeof(char));
    for(i = 0; i < key_len; i ++ ) 
        num[i] = key[i];
    int left_index = 0, right_index = n - 1, mid_index, check;
    while(left_index <= right_index) 
    {
        mid_index = left_index + (right_index - left_index) / 2;
        check = intal_compare(arr[mid_index], num);
        if(check == 0) 
        {
            //key intal found in left half part 
            if(mid_index > 0 && intal_compare(arr[mid_index - 1], num) == 0)
            {
                right_index = mid_index - 1;
            }
            //first occurence of key intal is found
            else
            {
                    free(num);
                    //returning the offset of the first occurence of key intal
                    return mid_index;
            }
        }
        //key intal found in right half part
        else if(check == -1)                
            left_index = mid_index + 1;
        //key intal found in left half part
        else  
            right_index = mid_index - 1;
    }
    free(num);
    //returning -1 as the key is not found
    return -1;
}

// Helper function to merge arrays for merge sort of intals.
static void intal_merge(char **arr, int left_index, int mid_index, int right_index) 
{
    int i, j, k; 
    int left_arr_len = mid_index - left_index + 1; 
    int right_arr_len =  right_index - mid_index; 
    char **left_arr = (char **)calloc(left_arr_len + 1, sizeof(char *));
    char **right_arr = (char **)calloc(right_arr_len + 1, sizeof(char *));
    for(i = 0; i < left_arr_len; i++) 
        left_arr[i] = arr[left_index + i];
    for(j = 0; j < right_arr_len; j++) 
        right_arr[j] = arr[mid_index + j + 1];
    i = 0; 
    j = 0; 
    k = left_index; 
    //merging the intals of left_arr and right_arr through the first pass
    while(i < left_arr_len && j < right_arr_len) 
    {
        int check = intal_compare(left_arr[i], right_arr[j]);
        if(check < 1) 
        { 
            arr[k] = left_arr[i];
            i++; 
        } 
        else
        { 
            arr[k] = right_arr[j];
            j++; 
        } 
        k++; 
    }
    //merging the remaining intals of left_arr 
    while(i < left_arr_len) 
    { 
        arr[k] = left_arr[i];
        i++; 
        k++; 
    }   
    //merging the remaining intals of right_arr
    while(j < right_arr_len) 
    { 
        arr[k] = right_arr[j];
        j++; 
        k++; 
    } 
}

// Helper function - wrapper for merge sort of intals.
static void intal_merge_sort(char **arr, int left_index, int right_index) 
{    
    if(left_index < right_index) 
    {
        int mid_index = left_index + (right_index - left_index) / 2;
        //sorting the left half of the array
        intal_merge_sort(arr, left_index, mid_index);
        //sorting the right half of the array
        intal_merge_sort(arr, mid_index + 1, right_index);
        //merging the left and right halves of the array
        intal_merge(arr, left_index, mid_index, right_index);
    }
}

// Sorts the array of n intals.
void intal_sort(char **arr, int n) 
{
    //sorting the array using Merge Sort Algorithm
    intal_merge_sort(arr, 0, n - 1);
}

// Coin-Row Problem - Dynamic Programming Solution
// The goal is to pick up the maximum amount of money subject to the constraint that
// no two coins adjacent in the initial row can be picked up.
char* coin_row_problem(char **arr, int n) 
{
    //Solving using DP by calaculating the max sum including the previous element
    //and the max sum excluding the previous element
    char *sum_prev_included = arr[0];
    char *sum_prev_excluded = (char *)calloc(2, sizeof(char));    
    char *new_sum_prev_excluded = (char *)calloc(2, sizeof(char));
    sum_prev_excluded[0] = '0';
    char *temp;
    int i;
    //iterating through the array to find the max sums
    for(i = 1; i < n; i++) 
    {  
        if(intal_compare(sum_prev_included, sum_prev_excluded) == 1)
            temp = sum_prev_included;
        else
            temp = sum_prev_excluded; 
        new_sum_prev_excluded = temp;
        temp = intal_add(sum_prev_excluded, arr[i]);         
        sum_prev_included = temp;
        sum_prev_excluded = new_sum_prev_excluded;
    }
    int res = intal_compare(sum_prev_included, sum_prev_excluded);
    //returning max(sum_prev_included, sum_prev_excluded)
    if(res == 1) 
    {
        free(sum_prev_excluded);
        return sum_prev_included;
    }
    free(sum_prev_included);
    return sum_prev_excluded; 
}
