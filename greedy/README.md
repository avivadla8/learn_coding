# Greedy Algorithms

## Where to use Greedy?

A problem must comprise these two components for a greedy algorithm to work:

1. It has optimal substructures. The optimal solution for the problem contains optimal solutions to the sub-problems.

2. It has a greedy property (hard to prove its correctness!). If you make a choice that seems the best at the moment and solve the remaining sub-problems later, you still reach an optimal solution. You will never have to reconsider your earlier choices.

## Activity Selection Problem

### Problem

	Given N activities with start and finish times. Select Maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time

### Idea

	Sort the activities according to their finish times
	Then, If the start time of an activity is greater than or equal to the finish time of previous activity, then select the activity.

### Implementation

[CODE](./asp.cpp)


## Egyptian Fraction

### Problem

	Every positive number can be expressed as sum of unique unit fractions. A fraction is unit fraction if numerator is 1 and denominator is positive integer.

	If a fraction is given, Express it in terms of unit fractions.

### Idea
	
	Given nr/dr, find ceiling of (dr/nr), let it be k.
	subtract 1/k from nr/dr and apply same method for the output until we get a unit fraction.

### Implementation

[CODE](./egy_frac.cpp)
