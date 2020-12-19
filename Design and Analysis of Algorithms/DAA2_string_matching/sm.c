// Server file for the implementation of Naive algorithm for String Matching

// Find the offset of the first occurrence of the pattern in the given text
// Return -1 in case of no occurrences of the pattern.

#include<string.h>

int searchFirstOccurrence(char *pattern, char *text){
        int len_pattern = strlen(pattern);        
        int len_text = strlen(text);
        int i, j, ikey, index;
        i=j=ikey=0;
        for(i=0; i<len_text - len_pattern; i++){
                ikey = index = i;
                j=0;
                while(j != len_pattern){
                        if(pattern[j] != text[ikey]){
                                break;
                                
                        }
                        ikey++;
                        j++;                                    
                }                
                if(j == len_pattern){
                        return index;
                }
        }
        return -1;
        /*
        return strstr(text, pattern);
        */
}


// Find the offset of the last occurrence of the pattern in the given text
// Return -1 in case of no occurrences of the pattern.
int searchLastOccurrence(char *pattern, char *text){
        int len_pattern = strlen(pattern);        
        int len_text = strlen(text);
        int i, j, ikey, index;
        i=j=ikey=0;
        for(i=len_text - len_pattern ; i>= 0; i--){
                ikey = index = i;
                j=0;
                while(j != len_pattern){
                        if(pattern[j] != text[ikey]){
                                break;
                        } 
                        ikey++;
                        j++;                     
                }
                if(j == len_pattern){
                        return index;
                }
        }
        return -1; 
        /*
        char* rev_pattern[1000];
        char* rev_text[1000];
        rev_pattern = strrev(pattern);
        rev_text = strrrev(text);
        int len_pattern = strlen(pattern);
        int len_text = strlen(text);
        int i;
        i = strstr(rev_text, rev_pattern);
        retrun len_text - len_pattern -1;
        */  
}

// Find the number of occurrences of the pattern in the given text
int numOccurrences(char *pattern, char *text){
        int len_pattern = strlen(pattern);        
        int len_text = strlen(text);
        int i, j, ikey, count;
        i=j=ikey=count=0;
        for(i=0; i<len_text - len_pattern; i++){
                ikey = i;
                j=0;
                while(j != len_pattern){
                        if(pattern[j] != text[ikey]){
                                break;
                                
                        }
                        ikey++;
                        j++;                                    
                }                
                if(j == len_pattern){
                        count++;
                }
        }
        return count;
}

/*
// Find the length of longest prefix of the pattern that matches a substring of the text (not pattern)
int longestPrefix(char *pattern, char *text){
        int len_pattern = strlen(pattern);        
        int len_text = strlen(text);
        int i, j, ikey, max;
        i=j=ikey=max=0;
        for(i=0; i<len_text - len_pattern; i++){
                ikey = i;
                for(j=0; j< len_pattern; j++){
                        if(pattern[j] != text[i]){
                                break;                                
                        }
                } 
                if(j>max)
                        max = j;                               
        }
        return max;
}

// Count the number of characters compared while finding all occurences of the pattern in the given text
// Characters must be matched from left to right
int charactersCompared(char *pattern, char *text){
        int len_pattern = strlen(pattern);        
        int len_text = strlen(text);
        int i, j, ikey, count;
        i=j=ikey=count=0;
        for(i=0; i<len_text - len_pattern; i++){
                ikey = i;
                while(j != len_pattern){
                        if(pattern[j] == text[ikey]){
                                ikey++;
                                j++;
                        }  
                        count++;  
                        if(text[ikey] == '\0'){
                                return count;
                        }                    
                }
                j=0;                
        }
        return count;
}
*/

int longestPrefix(char *pattern, char *text)
{
int n=strlen(text);
int m=strlen(pattern);
int max=0;
int i,j;
for(i=0;i<n-m;i++)
{
for(j=0;j<m;j++)
if(pattern[j]!=text[i+j])
break;
if(j>max)
max=j;
}
return max;
}

int charactersCompared(char *pattern, char *text)
{
    int l_text = strlen(text);
    int l_pattern = strlen(pattern);
    int charCMP = 0;
    for(int i=0;i<=l_text - l_pattern; ++i)
    {
        int j = i;
        int k=0;
        while(k<l_pattern)
        {
            ++charCMP;
            if(text[j]!=pattern[k])
                break;
            j++;
            k++;
        }
    }
    return charCMP;
}
