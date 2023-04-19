#include <stdio.h>
#include <stdlib.h>
#include "wrdfrq.h"
#include "hnode.h"

/* struct hnode* heap[] starting from 1*/

void percolateup(struct hnode* heap[], int index)
{
    int hole = index; // I rename index to whole for the sake of readability
    struct hnode* nodeptr = heap[index];
    int freq = nodeptr->wf.freq;
    while(hole > 1 && freq > heap[hole/2]->wf.freq) {
        heap[hole] = heap[hole/2];
        hole = hole/2;
    }
    heap[hole] = nodeptr;
}

void percolatedown(struct hnode* heap[], int* len, int index)
{
    int hole = index; // I rename index to whole for the sake of readability
    struct hnode* nodeptr = heap[index];
    int freq = nodeptr->wf.freq;
    int maxchild;
    // while hole has a parent
    while(hole <= *len/2) {

        if(2*hole+1 > *len) // if there's no right child then the left child is minimum
            maxchild = 2*hole;
        else
            maxchild = (heap[2*hole]->wf.freq >= heap[2*hole+1]->wf.freq) ? 2*hole : 2*hole+1;

        // no violiotion
        if(freq >= heap[maxchild]->wf.freq)
            break;

        // swap
        heap[hole] = heap[maxchild];
        hole = maxchild;
    }

    heap[hole] = nodeptr;

}

struct wrdfrq dequeuemin(struct hnode* heap[], int* len)
{
    struct hnode* minptr = heap[1];
    heap[1] = heap[*len];                          
    (*len)--; 
    percolatedown(heap, len, 1);
    return minptr->wf;
}

void heapsort(struct hnode* heap[], int* len, struct wrdfrq array[])
{
    for(int i = 0; i < *len; i++) {
        array[i] = dequeuemin(heap, len);
    }
}

struct hnode* hnalloc()
{
    struct hnode* node = malloc(sizeof(struct hnode));
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert(struct hnode* heap[], int *len, struct wrdfrq wf)
{
    struct hnode* node = hnalloc();
    node->wf = wf;
    heap[*len++] = node;
    percolateup(heap, *len);
}
