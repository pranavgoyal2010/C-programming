# C-programming

This project creates several data structures in C language from scratch. Some advance data structures are built on top of other simpler data structures hence results in re-using code and exploiting the advantages of Object Oriented design.

Implementation of the above data structures is shown below. The below data structures are implemented with gcc commands. These commands create object files from source code files and link them together to form an executable. To avoid typing the commands all over again, Makefile is used. 

**1. Array List**

The object file (arrayM.o present in CI directory) contains the main method to invoke the functions of the array_list.c. arrayM.o is compiled with the source code object file (array_list.o) to create an executable which on execution gives the following results.

<img width="407" alt="image" src="https://user-images.githubusercontent.com/93623710/233679801-35ececcb-fee4-41dc-a20c-a24c6e9ad4e2.png">



**2. Linked List**

The object file (linkedM.o present in CI directory) contains the main method to invoke the functions of the linked_list.c. linkedM.o is compiled with the source code object file (linked_list.o) to create an executable which on execution gives the following results.

<img width="533" alt="image" src="https://user-images.githubusercontent.com/93623710/233682531-ac3040df-b998-46cc-854b-7729e4b3187f.png">


**3. Queue**

The object file (queueM.o present in CI directory) contains the main method to invoke the functions of queue.c. Queue is implemented with the help of a linked list. Hence object file of linked list (linked_list.o), queuM.o and queue.o (source code object file) are complied together to form an executable (queue). On executing queue, it gives the following results.

<img width="372" alt="image" src="https://user-images.githubusercontent.com/93623710/233687982-ec794614-29e9-4125-b8a4-f79cecc9b601.png">


**4. Stack**

The object file (stackM.o present in CI directory) contains the main method to invoke the functions of stack.c. Stack is implemented with the help of linked list. Hence object file of linked list (linked_list.o), stackM.o and stack.o (source code object file) are compiled together to foem an executable (stack). On executing stack, it gives the following results.

<img width="348" alt="image" src="https://user-images.githubusercontent.com/93623710/233689612-9952627a-9b2d-43cc-9789-4f971e82f64d.png">


**5. Binary Tree**

The source code of binary tree is bintree.c and its object file is bintree.o. The object file is compiled with intreeM.o to print in-order traversal, posttreeM.o to print post-order traversal, revtreeM.o to print reverse traversal, pretreeM.o to print pre-order traversal, bintreeM.o to print all the traversals of the binary tree and to check if an element is present or absent. The results of traversal are shown below.

<img width="534" alt="image" src="https://user-images.githubusercontent.com/93623710/233691470-a2d1aea0-0188-4f3f-aaa0-ef2e1d678f90.png">


**6. Breadth-First Search (BFS) and Depth-First Search (DFS)**

The source code for binary tree is bintree.c. It uses stack for DFS and queue for BFS. Hence object files for linked list, queue and stack is also included while compiling to create the executable. Compiling searchM.o with bintree.o (object file for bintree.c) gives results for both DFS and BFS. dfsM.o with bintree.o is for printing DFS only while bfsM.o with bintree.o is for printing BFS only. The results for all both DFS and BFS are shown. It shuffles the values in the tree before printing the DFS and BFS results the second time.

<img width="538" alt="image" src="https://user-images.githubusercontent.com/93623710/233695995-fda7cc15-d3ed-45a8-b3ac-81c61ffabaa3.png">


**7. Tree Map (Dictionary or HashMap)**

Dictionary consists of key value pairs. The source code for dictionary is dictionary.c and its object file is dictionary.o. Since it uses a binary tree for its underlying implementation, bintree.o is included in the library along with linked_list.o, queue.o and stack.o. array_list.o is also included for printing the key-value pairs as a list. These object files is compiled with dictionary.o and dictionaryM.o (conataining the main function) to test the dictionary functions. The results are as follows.

<img width="269" alt="image" src="https://user-images.githubusercontent.com/93623710/233702146-5a156c6f-9de6-4c18-82cd-544ff9e1ba3d.png">
<img width="283" alt="image" src="https://user-images.githubusercontent.com/93623710/233702303-609875de-87e5-4b98-8fea-c0d04bf34d23.png">
<img width="353" alt="image" src="https://user-images.githubusercontent.com/93623710/233702448-6984f256-e209-48a1-8bfe-6fe15a5dfdfb.png">

**8. Min Heaps**

Heaps is created with the help of array list. Hence object file of array list (array_list.o) is compiled with the object file of main function (heapM.o and rHeapM.o) used for testing the heap functionality. The executable gives the following results.
<img width="328" alt="image" src="https://user-images.githubusercontent.com/93623710/233704856-a520e1bc-51db-4cfa-937a-48c191d73833.png">

<img width="336" alt="image" src="https://user-images.githubusercontent.com/93623710/233704988-1e259e1c-ae9d-40e9-8d1b-97f837964fd1.png">
