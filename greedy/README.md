# Greedy Algorithms

## Activity Selection Problem

### Problem

Given N activities with start and finish times. Select Maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time

### Idea

Sort the activities according to their finish times
Then, If the start time of an activity is greater than or equal to the finish time of previous activity, then select the activity.

### Implementation

[ASP](./asp.cpp)
