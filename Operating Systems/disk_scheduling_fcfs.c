#include<stdio.h>
#include<stdlib.h>

void read_disk_partitions_in_queue(int *disk_partitions, int queue_size);

void calc_seek_times(int disk_range, int queue_size, int * disk_partitions, int pos);

int main() {

    int disk_range;
    printf("Enter the max range of disk:\n");
    scanf("%d", &disk_range);

    int queue_size;
    printf("Enter the size of queue request:\n");
    scanf("%d", &queue_size);

    int *disk_partitions = (int *) malloc (sizeof(int) * queue_size);

    printf("Enter the queue of disk partitions to be read\n");
    read_disk_partitions_in_queue(disk_partitions, queue_size);
    
    int pos;
    printf("Enter the initial head position:\n");
    scanf("%d", &pos);
    printf("\n");

    calc_seek_times(disk_range, queue_size, disk_partitions, pos);

    return 0;
}

void read_disk_partitions_in_queue(int *disk_partitions, int queue_size) {
    
    for(int i = 0; i < queue_size; ++i)
        scanf("%d", &disk_partitions[i]);
}

void calc_seek_times(int disk_range, int queue_size, int * disk_partitions, int pos) {

    float time = 0.0;

    for(int i = 0; i < queue_size; ++i) {
        
        int size_diff = pos - disk_partitions[i];
        
        if (pos < disk_partitions[i]) 
            size_diff = disk_partitions[i] - pos;

        if (size_diff > disk_range - size_diff)
            size_diff = disk_range - size_diff;

        printf("Disk head moves from %d to %d with seek %d\n", pos, disk_partitions[i], size_diff);
        time += size_diff;
        pos = disk_partitions[i];

    }

    printf("Total seek time is %d\n", (int)time);
    printf("Average seek time is %.6f\n\n", (float)(time / queue_size));

}
