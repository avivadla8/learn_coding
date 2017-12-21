# Divide and conquer

## Strassen's algorithm

### Problem

	Perform Matrix Multiplication

### Idea

It has 4 steps:

* Divide input matrices A and B and output matrix C into n/2 x n/2 submatrices.
* Create 10 matrices S_1, S_2,...,S_10, each of which is n/2 x n/2 and is sum or difference of two matrices created in first step.
* Using submatrices created in first step and 10 matrices created in second step, recursively compute seven matrix products P_1,P_2,....,P_7.
* Compute desired matrices C_11,C_12,C_21,C_22 of the result matrix C by adding and subtracting various combinations of P_i matrices.

### Implementation


## Binary Search

### Problem

Search for a given number

### Idea

Using stl in cpp

* binary_search(start_ptr,end_ptr,num);
	* This function returns boolean true if element is present,else false

* lower_bound(start_ptr,end_ptr,num);
	* Returns pointer to "position of num" if container contains 1 occurrence of num.
	* Returns pointer to "first position of num" if container contains multiple occurrence of num.
	* Returns pointer to "position of next higher number than num" if container does not contain occurrence of num.
	* Subtracting the pointer to 1st position i.e "vect.begin()" returns the actual index.

* upper_bound(start_ptr, end_ptr, num);
	* Returns pointer to "position of next higher number than num" if container contains 1 occurrence of num.
	* Returns pointer to "first position of next higher number than last occurrence of num" if container contains multiple occurrence of num.
	* Returns pointer to "position of next higher number than num" if container does not contain occurrence of num.
	* Subtracting the pointer to 1st position i.e "vect.begin()" returns the actual index.



## Master's theorem


	
	
