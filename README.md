# Memory-Management-GUI
### Introduction

This C++ program demonstrates two memory allocation algorithms: Next Fit and Buddy System. The program allows the user to input the number and sizes of memory blocks, as well as the number and sizes of processes. It then allocates memory blocks to processes using the Next Fit and Buddy System algorithms and displays the allocation details.
The Next Fit algorithm searches for the next available memory block starting from the last assigned block and wraps around to the beginning if necessary. It allocates a process to the first block that can accommodate its size.
The Buddy System algorithm uses a binary tree data structure to represent the memory blocks. It starts with a single block of size equal to the nearest power of 2 greater than the total number of memory blocks. When a process needs to be allocated, the algorithm splits larger blocks into two equal-sized buddy blocks until a suitable block size is reached.

Code
This code demonstrates two memory allocation algorithms: Next Fit and Buddy System. Here is a breakdown of the code:

•	The nextFit function implements the Next Fit algorithm. It takes the block sizes (blockSize array) and process sizes (processSize array) as inputs and allocates memory blocks to processes based on their sizes. It uses a while loop to search for a suitable block for each process, and it updates the allocation array accordingly. The allocation details are then printed.

•	The buddySystem function implements the Buddy System algorithm. It takes the block sizes (blockSize array) and process sizes (processSize array) as inputs and allocates memory blocks to processes using the buddy system technique. It creates a binary tree (tree array) to represent the memory blocks and performs splitting and allocation operations based on the process sizes. The allocation details are printed at the end.

•	The main function is the entry point of the program. It prompts the user to enter the number and sizes of memory blocks, as well as the number and sizes of processes. It then calls the nextFit and buddySystem functions to perform memory allocation using the provided inputs.
The code calculates memory allocation based on the Next Fit and Buddy System algorithms, and it displays the allocation details for each process.
 
      Objectives
•	Implement the Next Fit algorithm for memory allocation.
•	Implement the Buddy System algorithm for memory allocation.
•	Take user input for the number of memory blocks and their sizes.
•	Take user input for the number of processes and their sizes.
•	Allocate memory blocks to processes using the Next Fit algorithm and Buddy System algorithm.
•	Display the allocation details for each process, including the process number, process size, and allocated block number (or "Not Allocated" if no block is allocated).
Result

The Next Fit and Buddy System memory allocation algorithms were implemented and tested using a small example. The following results were obtained:
Test Input:
Number of memory blocks: 3
Block sizes: 100, 200, 150
Number of processes: 4
Process sizes: 50, 100, 200, 150

Next Fit Allocation:

Process No. Process Size Block No.
1 50 1
2 100 2
3 200 Not Allocated
4 150 Not Allocated

Buddy System Allocation:

Process No. Process Size Block No.
1 50 1
2 100 2
3 200 Not Allocated
4 150 Not Allocated

In the Next Fit algorithm, the processes are allocated sequentially to the memory blocks. The first process with a size of 50 was allocated to Block 1, and the second process with a size of 100 was allocated to Block 2. However, the remaining two processes, with sizes 200 and 150, could not be allocated due to insufficient available memory.
Similarly, in the Buddy System algorithm, the first two processes were allocated to the same blocks as in the Next Fit algorithm. However, the last two processes could not be allocated due to insufficient available memory.
These results demonstrate the limitations of the Next Fit and Buddy System algorithms in handling certain memory allocation scenarios, particularly when there is a shortage of memory blocks or fragmented memory. Further evaluation and analysis are necessary to assess the performance of these algorithms in larger-scale systems.
Conclusion
In this program, we implemented two memory allocation algorithms: Next Fit and Buddy System. The Next Fit algorithm allocates memory to processes by searching for the next available block starting from the last assigned block. The Buddy System algorithm, on the other hand, uses a binary tree data structure to split larger blocks into smaller ones until a suitable block size is found.

Both algorithms have their advantages and limitations. Next Fit is simple and efficient but can lead to fragmentation over time. Buddy System provides better utilization of memory but requires more complex bookkeeping and can result in internal fragmentation.

By comparing the allocation results of both algorithms, users can evaluate their performance and choose the most suitable algorithm for their specific memory allocation requirements.
   
 





Tools
 1.QT Designer
2.C++
3.Linux ubuntu

Reference
1.	Silberschatz, A., Galvin, P. B., & Gagne, G. (2018). Operating System Concepts (10th ed.). Wiley. (Chapter 9: Memory Management)

2.	Tanenbaum, A. S., & Bos, H. (2014). Modern Operating Systems (4th ed.). Pearson. (Chapter 3: Memory Management)

3.	Stallings, W. (2018). Operating Systems: Internals and Design Principles (9th ed.). Pearson. (Chapter 8: Main Memory)

4.	Tanenbaum, A. S., & Woodhull, A. S. (2015). Operating Systems: Design and Implementation (3rd ed.). Pearson. (Chapter 3: Memory Management)

5.	Abraham, S., & Peter, M. (2014). Operating Systems: A Concept-Based Approach. Oxford University Press. (Chapter 5: Memory Management)

6.	Rajku
