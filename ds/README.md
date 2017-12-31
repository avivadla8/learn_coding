# Data Structures

## Regarding usage of stl in cpp

### Heaps

Operations on heap:
1. make_heap() : function is used to convert a range in a container to a heap
2. front() :- function displays first element of heap which is max number
3. push_heap() :- This function is used to insert elements into heap. The size of the heap is increased by 1. New element is placed appropriately in the heap.
4. pop_heap() :- This function is used to delete the maximum element of the heap. The size of heap is decreased by 1. The heap elements are reorganised accordingly after this operation.
5. sort_heap() :- This function is used to sort the heap. After this operation, the container is no longer a heap.
6. is_heap() :- This function is used to check whether the container is heap or not. Generally, in most implementations, the reverse sorted container is considered as heap. Returns true if container is heap else returns false.
7. is_heap_until() :- This function returns the iterator to the position till the container is the heap. Generally, in most implementations, the reverse sorted container is considered as heap.


### Priority Queue

Functions are:
1. push()
2. pop()
3. top()
4. empty()

It directly gives the max heap results

For min_heap of integers
	priority_queue <int, vector<int>, greater<int> > pq;

For custom comparator function see
[CODE](./priority queue.cpp)


















