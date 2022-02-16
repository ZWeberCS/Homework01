
// this struct implements the pcb using linked list (thus, it needs dynamic memory management)
struct pcb
{
    int parent;                 // a PCB index corresponding to the process's creator, -1 means it is free
    struct Node * children;     // a pointer to a linked list, where each list element contains the PCB index of one child process

};

// this struct implements the list-free pcb (avoiding using linked list, thus, no dynamic memory management)
struct pcb2
{
    int parent;                 // a PCB index corresponding to the process p's creator, -1 means p has no parent or p has not been created
    int first_child;            // a PCB index corresponding to the first child of p, -1 means it has no first child
    int younger_sibling;        // a PCB index corresponding to the sibling of p created immediately following p
    int older_sibling;          // a PCB index corresponding to the sibling of p created immediately prior to p

};