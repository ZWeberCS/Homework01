#include <stdio.h>
#include <stdlib.h>
#include "process_control_block.h"
#define N 50

int DC = 0; //Global variable for delete recursion

void create2(struct pcb2 PCBArray[], int numberPCBs, int p);
void destroy2(struct pcb2 PCBArray[], int numberPCBs, int p);
void print2(struct pcb2 PCBArray[], int numberPCBs, int p);

int main(void)
{
    // an array to store N number of pcb structures
    struct pcb2 PCB[N];

    // initialize pcb structures
    for (int i = 0; i < N; i++)
    {
        PCB[i].parent = -1;             // -1 for parent means the spot is makred as free (green)
        PCB[i].first_child = -1;        // -1 means this attribute has not been assigned
        PCB[i].younger_sibling = -1;    // -1 means this attribute has not been assigned
        PCB[i].older_sibling = -1;      // -1 means this attribute has not been assigned
    }

    // assuming that PCB[0] is the only currently existing process, its parent is unknown (-2)
    PCB[0].parent = -2;

    // process 0 creates process 1, 2, 3, and 4
    create2(PCB, N, 0);
    create2(PCB, N, 0);
    create2(PCB, N, 0);
    create2(PCB, N, 0);
    print2(PCB, N, 0);

    // process 3 creates process 5, 6
    create2(PCB, N, 3);
    create2(PCB, N, 3);
    print2(PCB, N, 3);

    // process 5 creates process 7, 8, 9
    create2(PCB, N, 5);
    create2(PCB, N, 5);
    create2(PCB, N, 5);
    print2(PCB, N, 5);

    destroy2(PCB, N, 3);
    print2(PCB, N, 3);
    print2(PCB, N, 5);

    return 0;
}

void create2(struct pcb2 PCBArray[], int numberPCBs, int p)
{
    //TODO: create process p's child process
        //Steps:
            //Select free slot
            //To allocate a new PCB requires first the dynamic creation of the new data structure. 
            //Next, a free slot in the array is located (26) and made to point to the new PCB.

        //Select free slot
        int created = 0;
      for (int i = 0; (i < numberPCBs && created == 0); i++)
    {
        if (PCBArray[i].parent == -1)
        {
            PCBArray[i].parent = p;
            if (PCBArray[p].first_child == -1){
                PCBArray[p].first_child = i;
                }
            else if (PCBArray[p].first_child != i){
                PCBArray[i].older_sibling = i-1;
                PCBArray[i-1].younger_sibling = i;
            }
        created = 1;
        }
    }
}


void destroy2(struct pcb2 PCBArray[], int numberPCBs, int p)
{   
  
     //the initially call the recursive procedure on the first_child field of PCB[p]
     //call the recursive procedure on the younger sibling of PCB[q] (this continues until the youngest sibling is reached)
     // call the recursive procedure on each younger sibling’s first_child field
      // set all fields of the current process to -1 (parent, first_child, younger_sibling, older_sibling)
   //when it has no children and no younger sibling

     DC++;
    if (PCBArray[p].first_child == -1 && PCBArray[p].younger_sibling == -1){
        PCBArray[p].parent = -1;
        PCBArray[p].older_sibling = -1;
    }
    //when it has a child
    if (PCBArray[p].first_child != -1){

        destroy2(PCBArray, numberPCBs, PCBArray[p].first_child);
        PCBArray[p].first_child = -1;
        if (DC == 1) { return;}
    }
    //when it has a younger sibling
    if (PCBArray[p].younger_sibling != -1){

        destroy2(PCBArray, numberPCBs, PCBArray[p].younger_sibling);
        PCBArray[p].parent = -1;
        PCBArray[p].older_sibling = -1;
        PCBArray[p].younger_sibling = -1;
    }


        DC--;
}

void print2(struct pcb2 PCBArray[], int numberPCBs, int p)
{

    printf("PCB Index %d: ", p);
    if (PCBArray[p].parent != -1)
    {
        printf("Status: allocated; Parent PCB Index %d; ", PCBArray[p].parent);
        printf("Children Index(es):");
        int current = PCBArray[p].first_child;
        while ( current != -1)
        {
            printf(" %d", current);
            current = PCBArray[current].younger_sibling;
        }
        printf("\n");
    }
    else
    {
        printf("Status: free.\n");
    }
}

