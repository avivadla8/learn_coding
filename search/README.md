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



