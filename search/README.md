# Search Algorithms


## Reverse elements of an array

### Implementation
[CODE](./reverse_elements.cpp)


## binary search

### Implementation

[CODE](./bin_search.cpp)

## Find first k largest elements

### Implementation

Using Max heap -- [CODE](./max_heap_k_elem.cpp)
Using Min heap -- [CODE](./min_heap_k_elem.cpp)


## Searching for a pattern in a given string

### Idea

* Using knuth-Morris-Pratt(KMP) Algorithm
* Complexity is O(n)
* Preprocessing
	* KMP algorithm does preproceses pat[] and constructs an auxiliary lps[] of size m (same as size of pattern) which is used to skip characters while matching. 
	* name lps indicates longest proper prefix which is also suffix.. A proper prefix is prefix with whole string not allowed. For example, prefixes of "ABC" are "", "A", "AB" and "ABC". Proper prefixes are "", "A" and "AB". Suffixes of the string are "", "C", "BC" and "ABC".
	* For each sub-pattern pat[0..i] where i = 0 to m-1, lps[i] stores length of the maximum matching proper prefix which is also a suffix of the sub-pattern pat[0..i]. 
	```
	 lps[i] = the longest proper prefix of pat[0..i] 
	               which is also a suffix of pat[0..i]. 
	```

* Searching 
	* we use a value from lps[] to decide the next characters to be matched. The idea is to not match character that we know will anyway match
	* We start comparison of pat[j] with j = 0 with characters of current window of text. 
	* We keep matching characters txt[i] and pat[j] and keep incrementing i and j while pat[j] and txt[i] keep matching.
	* When we see a mismatch
		* We know that characters pat[0..j-1] match with txt[i-j+1…i-1] (Note that j starts with 0 and increment it only when there is a match). 
		* We also know (from above definition) that lps[j-1] is count of characters of pat[0…j-1] that are both proper prefix and suffix. 
		* From above two points, we can conclude that we do not need to match these lps[j-1] characters with txt[i-j…i-1] because we know that these characters will anyway match. Let us consider above example to understand this.

### Implementation

[VIDEO_LINK](https://www.youtube.com/watch?v=GTJr8OvyEVQ)
[CODE]()


## Problems:

* Simple logic problems:
	* [LINK1](https://www.geeksforgeeks.org/search-almost-sorted-array/)
	* [LINK2](https://www.geeksforgeeks.org/given-sorted-array-number-x-find-pair-array-whose-sum-closest-x/)
	* [LINK3](https://www.geeksforgeeks.org/given-a-sorted-and-rotated-array-find-if-there-is-a-pair-with-a-given-sum/)
	* [LINK4](https://www.geeksforgeeks.org/find-the-element-that-odd-number-of-times-in-olog-n-time/)
	* [LINK5](https://www.geeksforgeeks.org/find-three-closest-elements-from-given-three-sorted-arrays/)
	* [LINK6](https://www.geeksforgeeks.org/binary-search-for-rational-numbers-without-using-floating-point-arithmetic/)
	* [LINK7](https://www.geeksforgeeks.org/print-possible-sums-consecutive-numbers-sum-n/)
	* [LINK8](https://www.geeksforgeeks.org/check-reversing-sub-array-make-array-sorted/)
	* [LINK9](https://www.geeksforgeeks.org/best-first-search-informed-search/)

* Important problems:
	* [Make all array elements equal with minimum cost](https://www.geeksforgeeks.org/make-array-elements-equal-minimum-cost/)
	* [Second minimum element using minimum comparisons](https://www.geeksforgeeks.org/second-minimum-element-using-minimum-comparisons/)
	* [kth smallest in array in linear time](https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array-set-2-expected-linear-time-2/)
	* [kth smallest in worst case linear time](https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array-set-3-worst-case-linear-time/)
	* [k-most frequent words in file](https://www.geeksforgeeks.org/find-the-k-most-frequent-words-from-a-file/)
	* [Celebrity Problem](https://www.geeksforgeeks.org/the-celebrity-problem/)


## 
