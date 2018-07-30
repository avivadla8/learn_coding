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
```
	priority_queue <int, vector<int>, greater<int> > pq
```

For custom comparator function see
 [CODE](./priority_queue.cpp)

#### Problems on Priority Queue

* You are given an array A of N integers and an integer B.You have to find the longest subarray of A such that the difference between the maximum and the minimum element of that subarray is strictly less than B.
	* Idea :- Use Two pointers to iterate over the array and two pointers act as start and end of sub-array using priority queue with custom comparator functions we can obtain minimum and maximum elements in sub-array in O(log(n)) time.
	* Implementation :- [CODE](./long_sub_diff.cpp)
	
### Stacks

* empty() – Returns whether the stack is empty
* size() – Returns the size of the stack
* top() – Returns a reference to the top most element of the stack
* push(g) – Adds the element ‘g’ at the top of the stack
* pop() – Deletes the top most element of the stack

Initialization: stack< type > var;

#### Problems on stacks

* The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the current day is less than or equal to its price on the given day.
For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}
	
	* Idea :- We see that S[i] on day i can be easily computed if we know the closest day preceding i, such that the price is greater than on that day than the price on day i. If such a day exists, let’s call it h(i), otherwise, we define h(i) = -1.The span is now computed as S[i] = i – h(i)
	* Implementation -- [CODE](./stockspan.cpp)


* Given a set of time intervals in any order, merge all overlapping intervals into one and output the result which should have only mutually exclusive intervals. Let the intervals be represented as pairs of integers for simplicity. 
	
	* Idea :- first sort the intervals according to starting time. Once we have the sorted intervals, we can combine all intervals in a linear traversal. The idea is, in sorted array of intervals, if interval[i] doesn’t overlap with interval[i-1], then interval[i+1] cannot overlap with interval[i-1] because starting time of interval[i+1] must be greater than or equal to interval[i]. Following is the detailed step by step algorithm.
	```
	1. Sort the intervals based on increasing order of starting time.
	2. Push the first interval on to a stack.
	3. For each interval do the following
		a. If the current interval does not overlap with the stack top, push it.
		b. If the current interval overlaps with stack top and ending time of current interval is more than that of stack top, update stack top with the ending  time of current interval.
	4. At the end stack contains the merged intervals

	```


* Largest Rectangular region in a Histogram
	* Idea :-
		1. Create an empty stack.
		2. Start from first bar, and do following for every bar ‘hist[i]’ where ‘i’ varies from 0 to n-1.
			a. If stack is empty or hist[i] is higher than the bar at top of stack, then push ‘i’ to stack.
			b. If this bar is smaller than the top of stack, then keep removing the top of stack while top of the stack is greater. Let the removed bar be hist[tp]. Calculate area of rectangle with hist[tp] as smallest bar. For hist[tp], the ‘left index’ is previous (previous to tp) item in stack and ‘right index’ is ‘i’ (current index).
		3. If the stack is not empty, then one by one remove all bars from stack and do step 2.b for every removed bar.

	* Implementation :-- [CODE](./maxhistarea.cpp)

* Find Maximum of minimum for every window size in a given array
	* Idea :-
		1. Find indexes of next smaller and previous smaller for every element. Next smaller is the nearest smallest element on right side of arr[i]. Similarly, previous smaller element is the nearest smallest element on left side of arr[i]. If there is no smaller element on right side, then next smaller is n.If there is no smaller on left side, then previous smaller is -1.
			eg: For input {10, 20, 30, 50, 10, 70, 30}, array of indexes of next smaller is {7, 4, 4, 4, 7, 6, 7}.
			For input {10, 20, 30, 50, 10, 70, 30}, array of indexes of previous smaller is {-1, 0, 1, 2, -1, 4, 4}
		2. Once we have indexes of next and previous smaller, we know that arr[i] is a minimum of a window of length “right[i] – left[i] – 1”. Lengths of windows for which the elements are minimum are {7, 3, 2, 1, 7, 1, 2}. This array indicates, first element is minimum in window of size 7, second element is minimum in window of size 3, and so on.
		```
		for (int i=0; i < n; i++)
    	{
        	// length of the interval
        	int len = right[i] - left[i] - 1;

	        // a[i] is the possible answer for
    	    // this length len interval
        	ans[len] = max(ans[len], arr[i]);
    	}
    	```
    	3. Some entries in ans[] are 0 and yet to be filled. For example, we know maximum of minimum for lengths 1, 2, 3 and 7 are 70, 30, 20 and 10 respectively, but we don’t know the same for lengths 4, 5 and 6.
    	4. Below are few important observations to fill remaining entries:
    		a. Result for length i, i.e. ans[i] would always be greater or same as result for length i+1, i.e., ans[i+1].
    		b. If ans[i] is not filled it means there is no direct element which is minimum of length i and therefore either the element of length ans[i+1], or ans[i+2], and so on is same as ans[i]
		So we fill rest of the entries using below loop.

		```
		 for (int i=n-1; i>=1; i--)
	        ans[i] = max(ans[i], ans[i+1]);
	     
	     ```

	* Implementation :-- [CODE](./maxOfMin.cpp)

* Tracking current max element in a stack

	* Idea :-
		1. We maintain other stack which maintains the max value till that point, we can just output the top value of second stack to get the max value at that instant
		eg: first :- 4 2 14 1 18    second:- 4 4 14 14 18 

* Check mirror in n-ary tree
	* Given two n-ary trees, the task is to check if they are mirror of each other or not. Print “Yes” if they are mirror of each other else “No”.
	* Idea :- 
		1. use Queue and Stack to check if given N-ary tree are mirror of each other or not.
		2. Let first n-ary tree be t1 and second n-ary tree is t2. For each node in t1, make stack and push its connected node in it. Now, for each node in t2, make queue and push its connected node in it.
		Now,
		```
		  While stack and Queue is not empty.
		  	a = top element of stack;
  			b = front of stack;
  			if (a != b)
    		return false;
  			pop element from stack and queue.
  		```

* Length of longest valid substring
	* Given a string consisting of opening and closing parenthesis, find length of the longest valid parenthesis substring.
	eg: ((()  -- ans:- 2

	* Idea :- 
		1. Create an empty stack and push -1 to it. The first element of stack is used to provide base for next valid string.
		2. Initialize result as 0.
		3. f the character is '(' i.e. str[i] == '(', push index 'i' to the stack. 
		4. Else (if the character is ')')
			a. Pop an item from stack (Most of the time an opening bracket)
			b. If stack is not empty, then find length of current valid substring by taking difference between current index and top of the stack. If current length is more than result, then update the result.
			c. If stack is empty, push current index as base for next valid substring.
		5. Return result.


* Form minimum number from given sequence.
	* Given a pattern containing only I’s and D’s. I for increasing and D for decreasing. Devise an algorithm to print the minimum number following that pattern. Digits from 1-9 and digits can’t repeat.
	eg: a) Input: D -- output :- 21  b) Input:- DIDI   output:- 21435
	
	* Idea :-
		* Few observations:
			* The digits can't be repeated, hence there can be nine digits atmost in final output.
			* To form minimum number, at every index of output, we are interested in minimum number which can be placed at that index.

		* The idea is to iterate over the entire input array , keeping track of the minimum number (1-9) which can be placed at that position of the output.
		* The tricky part of course occurs when ‘D’ is encountered at index other than 0. In such a case we have to track the nearest ‘I’ to the left of ‘D’ and increment each number in the output vector by 1 in between ‘I’ and ‘D’. 
		* We cover base case by :
			* If the first character of input is ‘I’ then we append 1 and 2 in the output vector and the minimum available number is set to 3 .The index of most recent ‘I’ is set to 1.
			* If the first character of input is ‘D’ then we append 2 and 1 in the output vector and the minimum available number is set to 3, and the index of most recent ‘I’ is set to 0.

		* Now we iterate the input string from index 1 till its end and:
			* If the character scanned is ‘I’ ,minimum value which has not been used yet is appended to the output vector .We increment the value of minimum no. available and index of most recent ‘I’ is also updated.
			* If the character scanned is ‘D’ at index i of input array, we append the ith element from output vector in the output and track the nearest ‘I’ to the left of ‘D’ and increment each number in the output vector by 1 in between ‘I’ and ‘D’.

	* Implementation:-- [CODE](./min_number.cpp)

