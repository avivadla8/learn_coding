# Dynamic Programming

## Maximum Subarray Sum

### Problem

	Given a array, find the maximum sum of the subarray possible.

### Idea

	At each index, if the element is negative, retain it, otherwise, if the previous element is positive add the previous element to it and store at that index else retain the value.

### Implementation

[CODE](./max_sub_sum.cpp)
