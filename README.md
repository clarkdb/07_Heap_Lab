07_HeapLab
==============

Implement a heap in C++

Requirements
------------

1. `add` and `remove` should be O(log n), except for `grow` which can be O(n)
2. Do not leak memory

Reading
=======
"Open Data Structures," Chapter 10, just the intro and section 1. http://opendatastructures.org/ods-cpp/10_Heaps.html

Questions
=========

#### 1. Which of the above requirements work, and which do not? For each requirement, write a brief response.

1. Add and remove are O(log n) because the trickleDown and bubbleUp need to run and grow is 0(n) because it needs to create a new array with the elements already present with a larger size.
2. There is no memory leak.

#### 2. Exercises 10.1 and 10.2 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html

10.1
When adding 7 to the heap, it would be added to the bottom right in the left most open spot and would then have to be bubbled up to switch with the parent 16 and would be in the correct spot then. With adding 3,  it would be added to the bottom right and switch with 7 as a parent and then switch with 6 and then switch 4 and would be in the correct spot then.

10.2
When removing 6 at the top, it would switch 6 with the bottom right of the tree, so 55 would be at the top and then remove 6 and trickle down 55 switching it with 8 and then 50. To remove 8 after that, it would be switched with 93 from the bottom right and then 93 would switch with 9 then 26 and then 32 while 8 is removed from the bottom.

#### 3. Exercise 10.4 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html

10.4
To find the children of a node, i's children will be from i+1 to i+d in index in the array and the parent will be from i_1 to i-d depending on what child i is in order.

#### 4. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

