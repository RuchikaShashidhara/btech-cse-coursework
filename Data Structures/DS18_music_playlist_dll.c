#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>

typedef struct song {
	char name[20];
	char artist[20];
	char genre[20];
	int duration;
	struct song *plink;
	struct song *nlink;	
} Song;

Song* getSong();
void swap(int *a, int *b);
void randomize(int arr[], int n);
void displaySong(Song *temp);
void displayList(Song* head1);
void insert_in_Front(Song **head);
void insert_at_End(Song **head);
void insertAtPos(int pos, Song **head);
void delFront(Song **head);
void delEnd(Song **head);
void delAtPos(int pos, Song **head);
void playfromBegining(Song *head1);
void playfromEnd(Song *head1);
void playfromPosition(int pos,Song **head);
void skipPlay(Song *head1);
void shufflePlay(Song *head1);
void playArtist(char ch2[],Song *head1);
void playGenre(char ch2[],Song *head1);


int main(){
	int ch,ch1,N,i,pos;
	char ch2[20];
	Song* head=NULL;
	Song* front=NULL, *rear=NULL;

	do{
		printf("1.Insertion of N Songs into the Playlist\n2.Insertion\n3.Deletion\n4.Display\n5.Play the songs by reference\n6.Play the songs by recommendation\n7.EXIT\n");
		printf("Enter your choice 1-7\n");
		scanf("%d",&ch);
		switch(ch){
			case 1: printf("Enter no. of songs\n");
				scanf("%d",&N);
				for(i=0;i<N;i++)
					insert_at_End(&head);
				displayList(head);
				break;
			case 2: printf("1.Insert At Front\n2.Insert At End\n3.Insert At Position\nEnter your choice\n");
				scanf("%d",&ch1);
				switch(ch1){
					case 1: insert_in_Front(&head);
						break;
					case 2: insert_at_End(&head);
						break;
					case 3: printf("Enter the position\n");
						scanf("%d",&pos);
						insertAtPos(pos, &head);
						break;
				}
				break;
			case 3: printf("1.Delete At Front\n2.Delete At End\n3.Delete At Position\nEnter your choice\n");
				scanf("%d",&ch1);
				switch(ch1){
					case 1: delFront(&head);
						break;
					case 2: delEnd(&head);
						break;
					case 3: printf("Enter the position\n");
						scanf("%d",&pos);
						delAtPos(pos,&head);
						break;
				}
				break;
			case 4: displayList(head);
				break;
			case 5: printf("1.Play from begining\n2.Play from the end backwards\n3.Play from a Position\n4.Skip Play\n5.Shuffle Play\nEnter your choice\n");
				scanf("%d",&ch1);
				switch(ch1){
					case 1: playfromBegining(head);
						break;
					case 2: playfromEnd(head);
						break;
					case 3: printf("Enter the position\n");
						scanf("%d",&pos);
						playfromPosition(pos,&head);
						break;
					case 4: skipPlay(head);
						break;
					case 5: shufflePlay(head);
						break;
				}
				break;
			case 6: printf("1.Play by Artist\n2.Play by Genre\n");
				scanf("%d",&ch1);
				switch(ch1){
					case 1: printf("Enter the Artist\n");
						scanf("%s",ch2);
						playArtist(ch2,head);
						break;
					case 2: printf("Enter the Genre\n");
						scanf("%s",ch2);
						playGenre(ch2,head);
						break;
				}
				break;
			case 7: break;
			default: printf("Invalid Input\n");
		}
	}while(ch != 7);
	return 0;
}

Song* getSong(){
	Song* newSong = (Song*)calloc(sizeof(Song), 1);
	newSong->plink=NULL;
	newSong->nlink=NULL;
	printf("Enter the Song's Name:\n");
	scanf("%s",newSong->name);
	printf("Enter its Main Artist:\n");
	scanf("%s",newSong->artist);
	printf("Enter its Genre:\n");
	scanf("%s",newSong->genre);
	printf("Enter the duration of the song:\n");
	scanf("%d",&newSong->duration);
	return newSong;
}

void displaySong(Song *temp){
	printf("Name: %s\n",temp->name);
	printf("Main Artist: %s\n",temp->artist);
	printf("Genre: %s\n",temp->genre);
	printf("Duration: %d\n",temp->duration);
}

void insert_in_Front(Song **head){
	Song *newSong = getSong();
	if((*head) == NULL){
		(*head) = newSong;
		return;
	}
	newSong->nlink = (*head);
	(*head)->plink = newSong;
	(*head) = newSong;
}

void insert_at_End(Song **head){
	Song* newSong = getSong();
	Song*temp = (*head);
	if((*head) == NULL){
		(*head) = newSong;
		return;
	}
	while(temp->nlink != NULL){
		temp = temp->nlink;
	}
	temp->nlink = newSong;
	newSong->plink = temp;
}

void insertAtPos(int pos, Song **head){
	int i;
	Song *newSong = getSong();
	Song *temp = (*head);
	if((*head) == NULL){
		(*head) = newSong;
		return;
	}
	for(i=1;i<pos-1;i++){
		temp=temp->nlink;
	}
	newSong->nlink = temp->nlink;
	newSong->plink = temp;
	temp->nlink->plink = newSong;
	temp->nlink = newSong;
}

void delFront(Song **head){
	Song *temp = (*head);
	if(temp == NULL){
		printf("Empty\n");
		return;
	}
	(*head) = temp->nlink;
	(*head)->plink = NULL;
	displaySong(temp);
	free(temp);
}

void delEnd(Song **head){
	Song* temp = (*head);
	if(temp == NULL){
		printf("Empty\n");
		return;
	}
	while(temp->nlink != NULL){
		temp = temp->nlink;
	}
	temp->plink->nlink = NULL;
	displaySong(temp);
	free(temp);
}

void delAtPos(int pos, Song **head){
	int i;
	Song *temp = *head;
	if(temp == NULL){
		printf("Empty\n");
		return;
	}
	for(i=1;i<pos;i++){
		temp = temp->nlink;
	}
	temp->nlink->plink = temp->plink;
	temp->plink->nlink = temp->nlink;
	displaySong(temp);
	free(temp);
}


void displayList(Song* head1){
	Song *temp = head1;
	int count =0;
	int tottime = 0;
	while(temp->nlink != NULL){
		printf("[Name: %s | Artist: %s | Genre: %s | Duration: %d min]<-->\n",temp->name,temp->artist,temp->genre,temp->duration);
		tottime += temp->duration;
		temp = temp->nlink;
		count++;
	}
	count++;
	tottime += temp->duration;
	printf("[Name: %s | Artist: %s | Genre: %s | Duration: %d min]\n",temp->name,temp->artist,temp->genre,temp->duration);
	printf("No. of songs in the playlist: %d-->\n", count);
	printf("Time taken to play all the songs: %d min\n\n", tottime);
}

void playfromBegining(Song *head1){
	Song *temp = head1;
	int count = 0;
	int tottime = 0;
	while(temp->nlink != NULL){
		printf("Song being played: %s\n", temp->name);
		printf("Song plays for %d min\n", temp->duration);
		tottime += temp->duration;
		temp = temp->nlink;		
		count ++;
	}
	count ++;
	tottime += temp->duration;
	printf("Last song being played: %s\n", temp->name);
	printf("Song plays for %d min\n", temp->duration);
	printf("Total number of %d songs played for %d min\n", count, tottime);
}

void playfromEnd(Song *head1){
	Song *tail = head1;
	int count = 0;
	int tottime = 0;
	while(tail->nlink != NULL){
		tail = tail->nlink;
	}
	while(tail != head1){
		printf("Song being played: %s\n", tail->name);
		printf("Song plays for %d min\n", tail->duration);
		tail = tail->plink;
		tottime += tail->duration;
		count ++;
	}
	count ++;
	tottime += tail->duration;
	printf("First song being played: %s\n", tail->name);
	printf("Song plays for %d min\n", tail->duration);
	printf("Total number of %d songs played for %d min\n", count, tottime);
}

void playfromPosition(int pos,Song **head){
	int i;
	Song *temp = *head;
	for(i=1;i<pos;i++){
		temp = temp->nlink;
	}
	playfromBegining(temp);
}

void skipPlay(Song *head1){
	Song *temp = head1;
	int count = 0;
	int songcount = 0;
	int tottime = 0;	
	while(temp->nlink != NULL){
		if(count%2==0){
			printf("Song being played: %s\n", temp->name);
			printf("Song plays for %d min\n", temp->duration);
			tottime += temp->duration;
			songcount ++;
		}
			temp = temp->nlink;	
			count ++;	
	}
	if(count%2==0){
		count ++;
		tottime += temp->duration;
		printf("Last song being played: %s\n", temp->name);
		printf("Song plays for %d min\n", temp->duration);
	}
	printf("Total number of %d songs played for %d min\n", songcount, tottime);
}

void swap(int *a, int *b){ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 

void randomize(int arr[], int n){ 
    srand ( time(NULL) ); 
    int i;
    for (i=n-1; i>0; i--) { 
        int j = rand() % (i+1); 
        swap(&arr[i], &arr[j]); 
    } 
} 

void shufflePlay(Song *head1){
	Song *tail = head1;
	int count = 0;
	int tottime = 0;
	int i,j;
	while(tail->nlink != NULL){
		tail = tail->nlink;
		count++;
		tottime += tail->duration;
	}
	count++;
	tottime += tail->duration;
	int arr[count];
	for(i=0; i<count; i++){
		arr[i] = i;
	}
	randomize(arr, count);
	for(i=0; i<count; i++){
		Song *temp = head1;
		for(j=0; j<arr[i]; j++){
			temp = temp->nlink;
		}
		printf("Song being played: %s\n", temp->name);
		printf("Song plays for %d min\n", temp->duration);		
	}
	printf("Total number of %d songs played for %d min\n", count, tottime);
}

void playArtist(char ch2[],Song *head1){
	Song *temp = head1;
	int count = 0;
	int tottime = 0;
	
	while(temp->nlink != NULL){
		if(strcmp(ch2,temp->artist)==0){
			printf("Song being played: %s\n", temp->name);
			printf("Song plays for %d min\n", temp->duration);
			tottime += temp->duration;
			count ++;
		}
		temp = temp->nlink;			
	}
	if(strcmp(ch2,temp->artist)==0){
		count ++;
		tottime += temp->duration;
		printf("Last song being played: %s\n", temp->name);
		printf("Song plays for %d min\n", temp->duration);
	}
	printf("Total number of %d songs played for %d min\n", count, tottime);
}

void playGenre(char ch2[],Song *head1){
	Song *temp = head1;
	int count = 0;
	int tottime = 0;
	
	while(temp->nlink != NULL){
		if(strcmp(ch2,temp->genre)){
			printf("Song being played: %s\n", temp->name);
			printf("Song plays for %d min\n", temp->duration);
			tottime += temp->duration;			
		}
		count ++;
		temp = temp->nlink;			
	}
	if(strcmp(ch2,temp->genre)){
		count ++;
		tottime += temp->duration;
		printf("Last song being played: %s\n", temp->name);
		printf("Song plays for %d min\n", temp->duration);
	}
	printf("Total number of %d songs played for %d min\n", count, tottime);
}

