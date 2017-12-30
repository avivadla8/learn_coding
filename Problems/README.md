# Problems

## Find Next Greater element for every element in array in O(n) time 

### Idea

1. Push the first element to stack.
2. Pick rest of the elements one by one and follow following steps in loop.
	1. Mark the current element as next.
	2. If stack is not empty, then pop an element from stack and compare it with next.
	3. If next is greater than the popped element, then next is the next greater element for the popped element.
	4. Keep popping from the stack while the popped element is smaller than next. next becomes the next greater element for all such popped elements
	5. If next is smaller than the popped element, then push the popped element back.
3. After the loop in step 2 is over, pop all the elements from stack and print -1 as next element for them.


## Find Maximum of minimums for every window size in a given array.

### Idea

1. Find indices of next smaller and previous smaller for every element. Next smaller is nearest smaller element on right side of arr[i]. Similarly, previous smaller element is the nearest smallest element on left side of arr[i]. If there is no smaller element on right side, then next smaller is n.If there is no smaller on left side, then previous smaller is -1.
	Eg: For input {10, 20, 30, 50, 10, 70, 30}, array of indexes of next smaller is {7, 4, 4, 4, 7, 6, 7}.
	    For input {10, 20, 30, 50, 10, 70, 30}, array of indexes of previous smaller is {-1, 0, 1, 2, -1, 4, 4}

2. Once we have indexes of next and previous smaller, we know that arr[i] is a minimum of a window of length “right[i] – left[i] – 1”. Lengths of windows for which the elements are minimum are {7, 3, 2, 1, 7, 1, 2}. This array indicates, first element is minimum in window of size 7, second element is minimum in window of size 3, and so on

3. Some entries in ans[] are 0 and yet to be filled. For example, we know maximum of minimum for lengths 1, 2, 3 and 7 are 70, 30, 20 and 10 respectively, but we don’t know the same for lengths 4, 5 and 6.
Below are few important observations to fill remaining entries
a) Result for length i, i.e. ans[i] would always be greater or same as result for length i+1, i.e., ans[i+1].
b) If ans[i] is not filled it means there is no direct element which is minimum of length i and therefore either the element of length ans[i+1], or ans[i+2], and so on is same as ans[i].


