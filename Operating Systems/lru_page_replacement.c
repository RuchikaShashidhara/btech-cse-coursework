#include <stdio.h>
#include <stdlib.h>

int canfindLRU(int val, int* frame, int size);

int main() {

	int page_size, frame_size, position, page_fault = 0, flag = 0;
	
	printf("\n Enter the length of the reference String: ");
	scanf("%d", &page_size);
	
	int *refs = (int *) malloc (sizeof(int) * page_size);
	
	int *temp = (int *) malloc (sizeof(int) * page_size);

	printf(" Enter the reference string: ");
	for (int i = 0; i < page_size; i++)
		scanf("%d", &refs[i]);
	
	printf(" Enter the number of frames: ");
	scanf("%d", &frame_size);
	
	int *frames = (int *) malloc (sizeof(int) * frame_size);
	
	for (int i = 0; i < frame_size; i++)
		frames[i] = -1;
	
		
	printf("\n The Page Replacement Process is\n");
	
	for (int i = 0; i < page_size; i++) {
	
		if (canfindLRU(refs[i], frames, frame_size) == 1)
			printf(" %d  %d  %d\n", frames[0], frames[1], frames[2]);
		
		else {
			++page_fault;
			
                  	flag = canfindLRU(-1, frames, frame_size);
                  	
			if (flag == -1) {
				for (int j = 0; j < frame_size; j++) {
					
					if (frames[j] == -1) {
						frames[j] = refs[i];
						break;
					}
				}
			}
			
            		else {
                  		for(int j = 0; j < frame_size; j++)
                        		temp[j] = 0;
              
                 		for (int j = i - 1,  k = 1; k <= frame_size - 1; k++, j--) {
                        		
                        		for (int l = 0; l < frame_size; l++) {
                              			if (frames[l] == refs[j]) 
                                    			temp[l] = 1;
                        		}
                  		}
                  		
                          	for (int j = 0; j < frame_size; j++) {
                                	if (temp[j] == 0)
                                		position = j;
                          	}
                          	
			        frames[position] = refs[i];
		        }
		        
		        if (page_fault == 1)  
			        printf(" %d %d %d -- PF No. %d\n", frames[0], frames[1], frames[2], page_fault);
			
			else if (page_fault == 2) 
			        printf(" %d  %d %d -- PF No. %d\n", frames[0], frames[1], frames[2], page_fault);
			
			else 
			        printf(" %d  %d  %d -- PF No. %d\n", frames[0], frames[1], frames[2], page_fault);
			
		}
	
	}
	
	printf("\n The number of Page faults using LRU is %d\n\n", page_fault);
	
	return 0;
}

int canfindLRU(int val, int* frame, int size) {

	int flag = 0;

	for (int i = 0; i < size; i++) {
		if (frame[i] == val)
			flag = 1;	
        }
        
	if(flag == 1 && val == -1)
		return -1;
	else
		return flag;
}

