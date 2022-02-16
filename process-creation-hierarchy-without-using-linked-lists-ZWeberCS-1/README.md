# CS3100-Template-02a

## Homework objective
Implement process creation hierarchy without using linked lists

## Instruction
This template gives you starter code for CS 3100 programming project. In this project, you will implement the process creation hierarchy without using linked lists to avoid dynamic memory management as described in "2.3 The Process Control Block". 

The PCBs are simplified as follows:

* All PCBs are implemented as an array of size N.
* Each process is referred to by the PCB index, 0 through N-1.
* Each PCB is a structure consisting of four fields: `parent`: a PCB index corresponding to the process p's creator, `first_child`: a PCB index corresponding to p's first child, `younger_sibling`: a PCB index corresponding to the sibling of p created immediately following p, `older_sibling`: a PCB index corresponding to the sibling of p created immediately prior to p.

The necessary functions are simplified as follows:

`create2(PCB, numberOfPCBs, p)` represents the create function executed by process PCB[p]. The function creates a new child process PCB[q] of process PCB[p] by performing the following tasks:
* allocate a free PCB[q]
* record the parent's index, p, in PCB[q]
* update PCB[p]'s first child if PCB[q] is its first child
* otherwise, find PCB[q]'s older sibling, and the previous child's younger sibling, update their data values

`destroy2(PCB, numberOfPCBs, p)` represents the destroy function executed by process PCB[p]. The function recursively destroys all descendent processes (child, grandchild, etc.) of process PCB[p]. Note: PCB[p] should not be destroyed by this function.

Run the following commands to compile, clean up, and test the code:
* make
* make clean
* make test

## Your task
In this homework, you need to implement the two functions `create2(PCB, numberOfPCBs, p)` and `destroy2(PCB, numberOfPCBs, p)`.
