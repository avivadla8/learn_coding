# Bit Manipulation Methods

## Change all the right side bits of most significant digit for a number to 1

### Idea

let N = 21 {10101} here, most significant digit is 4th one, assuming it starts from 0th position from right.

	N = N| (N>>1);
	N = N| (N>>2);
	N = N| (N>>4);
	N = N| (N>>8);

## Count number of 1's in binary representation of a number

### Idea

```
int count_one (int n)
{
	while(n)
	{
		n = n&(n-1);
		count++;
	}
	return count;
}
```

## To check whether a number is power of 2 or not

### Idea

* x will check if x == 0 and !(x & (x - 1)) will check if x is a power of 2 or not.
	(x && !(x & (x - 1)))

## Few tricks

1. x ^ ( x & (x-1)) : Returns the rightmost 1 in binary representation of x.
2. x & (-x) : Returns the rightmost 1 in binary representation of x
3. (-x) is the two’s complement of x. (-x) will be equal to one’s complement of x plus 1.Therefore (-x) will have all the bits flipped that are on the left of the rightmost 1 in x. 
4. x | (1 << n) : Returns the number x with the nth bit set.

