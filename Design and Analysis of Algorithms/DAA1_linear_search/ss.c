//Server file for the implementation of Sequential Search

//Find the offset of the first occurrence of the key in an array of integers
//Return -1 in case of no occurrences of the key.
int searchFirstOccurrence(int arr[], int n, int key){
        int i;
        for(i=0; i<n; i++){
                if(arr[i] == key){
                        return i;       //if key is found i th position, i.e. the first occurrence of key in arr, return i
                }
        }
        return -1;                      //if key is not found in arr, i.e. no occurrences, return -1
}        

//Find the offset of the last occurrence of the key in an array of integers
//Return -1 in case of no occurrences of the key.
int searchLastOccurrence(int arr[], int n, int key){
        int i;
        for(i=n-1; i>=0; i--){
                if(arr[i] == key){
                        return i;       //if key is found (n-i) th position, i.e. the first occurrence of key in arr, return i
                }
        }
        return -1;                      //if key is not found in arr, i.e. no occurrences, return -1
}

//Find the number of occurrences of the key in an array of integers
int numOccurrences(int arr[], int n, int key){
        int i, count;
        count = 0;                      //initializes the count variable that counts the number of occurrences to zero
        for(i=0; i<n; i++){
                if(arr[i] == key){      
                        count++;        //whenever the key is found, count is incremented
                }
        }
        return count;                   //the total number of occurrences of the key i returned, i.e. count is returned          
}
