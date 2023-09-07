/*Finding the Duplicate Number is a classic problem, and as such there are many different ways to approach it; a total of 7 approaches are presented here. The first 4 approaches involve rearranging or modifying elements of the array, and hence do not meet the constraints specified in the problem statement. However, they are included here since they are more feasible to come up with as the first approach in an interview setting. Since each approach is independent of the other approaches, they can be read in any order.

Proof
Proving that at least one duplicate must exist in numsnumsnums is an application of the pigeonhole principle. Here, each number in numsnumsnums is a "pigeon" and each distinct number that can appear in numsnumsnums is a "pigeonhole." Because there are n+1n+1n+1 numbers and nnn distinct possible numbers, the pigeonhole principle implies that if you were to put each of the n+1n + 1n+1 pigeons into nnn pigeonholes, at least one of the pigeonholes would have 2 or more pigeons.

Approach 1: Sort
Note: This approach modifies individual elements and does not use constant space, and hence does not meet the problem constraints. However, it utilizes a fundamental concept that can help solve similar problems.

Intuition

In an unsorted array, duplicate elements may be scattered across the array. However, in a sorted array, duplicate numbers will be next to each other.

Algorithm

Sort the input array (numsnumsnums).

Iterate through the array, comparing the current number to the previous number (i.e. compare nums[i]nums[i]nums[i] to nums[i−1]nums[i - 1]nums[i−1] where i>0i > 0i>0).

Return the first number that is equal to its predecessor.


Complexity Analysis

Time Complexity: O(nlog⁡n)O(n \log n)O(nlogn)

Sorting takes O(nlog⁡n)O(n \log n)O(nlogn) time. This is followed by a linear scan, resulting in a total of O(nlog⁡n)O(n \log n)O(nlogn) + O(n)O(n)O(n) = O(nlog⁡n)O(n \log n)O(nlogn) time.

Space Complexity: O(log⁡n)O(\log n)O(logn) or O(n)O(n)O(n)

The space complexity of the sorting algorithm depends on the implementation of each programming language:

In Java, Arrays.sort() for primitives is implemented using a variant of the Quick Sort algorithm, which has a space complexity of O(log⁡n)O(\log n)O(logn)
In C++, the sort() function provided by STL uses a hybrid of Quick Sort, Heap Sort and Insertion Sort, with a worst case space complexity of O(log⁡n)O(\log n)O(logn)
In Python, the sort() function is implemented using the Timsort algorithm, which has a worst-case space complexity of O(n)O(n)O(n)
Approach 2: Set
Note: This approach does not use constant space, and hence does not meet the problem constraints. However, it utilizes a fundamental concept that can help solve similar problems.

Intuition

As we traverse the array, we need a way to "remember" values that we've seen. If we come across a number that we've seen before, we've found the duplicate. An efficient way to record the seen values is by adding each number to a set as we iterate over the numsnumsnums array.

Algorithm

In order to achieve linear time complexity, we need to be able to insert elements into a data structure and look them up in constant time. A HashSet/unordered_set is well suited for this purpose. Initialize an empty hashset, seenseenseen.

Iterate over the array and first check if the current element exists in the hashset (seenseenseen).

If it does exist in the hashset, that number is the duplicate and can be returned right away.
Otherwise, insert the current element into seenseenseen, move to the next element in the array and repeat step 2.


Complexity Analysis

Time Complexity: O(n)O(n)O(n)

HashSet insertions and lookups have amortized constant time complexities. Hence, this algorithm requires linear time, since it consists of a single for loop that iterates over each element, looking up the element and inserting it into the set at most once.

Space Complexity: O(n)O(n)O(n)

We use a set that may need to store at most nnn elements, leading to a linear space complexity of O(n)O(n)O(n).

Approach 3: Negative Marking
Note: This approach temporarily modifies individual elements and thus does not satisfy the problem constraints. However, this approach is intuitive and utilizes a technique that is useful to know. Furthermore, the underlying concept lends itself to solving similar problems. As such, you can further practice this technique on other problems such as 41. First Missing Positive.

Intuition

There are n+1n + 1n+1 positive numbers in the array (numsnumsnums) (all in the range [1,n][1, n][1,n]). Since the array only contains positive integers, we can track each number (numnumnum) that has been seen before by flipping the sign of the number located at index ∣num∣|num|∣num∣, where ∣∣||∣∣ denotes absolute value.

For example, if the input array is [1,3,3,2][1, 3, 3, 2][1,3,3,2], then for 111, flip the number at index 111, making the array [1,−3,3,2][1,-3,3,2][1,−3,3,2]. Next, for −3-3−3 flip the number at index 333, making the array [1,−3,3,−2][1,-3,3,-2][1,−3,3,−2]. Finally, when we reach the second 333, we'll notice that nums[3]nums[3]nums[3] is already negative, indicating that 333 has been seen before and hence is the duplicate number.

Algorithm

Iterate over the array, evaluating each element (let's call the current element curcurcur).

Since we use negative marking, we must ensure that the current element (curcurcur) is positive (i.e. if curcurcur is negative, then use its absolute value).

Check if nums[cur]nums[cur]nums[cur] is negative.

If it is, then we have already performed this operation for the same number, and hence curcurcur is the duplicate number. Store curcurcur as the duplicate and exit the loop.

Otherwise, flip the sign of nums[cur]nums[cur]nums[cur] (i.e. make it negative). Move to the next element and repeat step 3.

Once we've identified the duplicate, we could just return the duplicate number. However, even though we were not able to meet the problem constraints, we can show that we are mindful of the constraints by restoring the array. This is done by changing all negative numbers to positive.


Complexity Analysis

Time Complexity: O(n)O(n)O(n)

Each element is visited at most twice (once in the first loop to find the duplicate and once in the second loop to restore the numbers).

Space Complexity: O(1)O(1)O(1)

All manipulation is done in place, so no additional storage (barring one variable) is needed.

Approach 4.1: Array as HashMap (Recursion)
Note: Approaches 4.1 and 4.2 modify individual elements, and hence do not meet the problem constraints. However, they utilize an insightful concept that can help with similar problems.

Intuition

Use the Array as a HashMap -- map each number to its equivalent index in the array. For instance, map (and store) the number 5 to index 5 (i.e. nums[5]=5nums[5] = 5nums[5]=5). Since there are (n+1)(n + 1)(n+1) positions/indexes in the input array, and the numbers range from 111 to nnn, at least one index will have more than one number (due to the pigeonhole principle).

Since all numbers are in the range [1,n][1,n][1,n], no number will be mapped to index 0. So let's start with the number at index 0 since it must be out of place. Say that the number at index 0 is firstfirstfirst. Then firstfirstfirst needs to be stored at nums[first]nums[first]nums[first]. But there's some other number at nums[first]nums[first]nums[first] that needs to be stored at its respective location (and so on).

If nums[first]nums[first]nums[first] is the same as firstfirstfirst, then we have found a duplicate. Otherwise, let's swap the numbers located at index 000 and at index firstfirstfirst, and repeat this process with the new number at index 000.

As we repeatedly apply this mapping, the duplicate number will, on its first instance, be mapped/stored correctly at its equivalent index, and then on its second occurrence, we will attempt to store it there again. When a number already exists at its correct index, and we attempt to store another instance of the same number there again, then we know that's the duplicate.

Algorithm

Start with the first index (index 000) of the array. Call store(nums,0)store(nums, 0)store(nums,0) to store the number 000 at index 000.

Note that because all input numbers are in the range [1,n][1, n][1,n], no number will ever be mapped to index 000. Hence, index 000 can hold any dummy value, including 000.
store(nums,cur)store(nums, cur)store(nums,cur) uses the current number, curcurcur, as the target index. It first backs up the number that's stored at the equivalent position (nxt=nums[cur]nxt = nums[cur]nxt=nums[cur]), and then overwrites that index with curcurcur.

Now we need to deal with the number that was backed up (i.e. nxtnxtnxt). Recursively call storestorestore with this number as input (i.e. store(nums,nxt)store(nums, nxt)store(nums,nxt)) so it too can be placed at its equivalent index.

Repeat steps 2 and 3. At some point, nums[cur]nums[cur]nums[cur] will already contain the number curcurcur, in which case we have found the duplicate number.

To illustrate the algorithm, let's consider an example [3,3,5,4,1,3][3,3,5,4,1,3][3,3,5,4,1,3]:

store(nums,0)store(nums, 0)store(nums,0)

Here cur=0cur = 0cur=0 and nums[cur]=3nums[cur] = 3nums[cur]=3
Back up the number 3 (that's at index 0)
Store 0 at index 0. The array is now: [0‾,3,5,4,1,3][\underline0,3,5,4,1,3][ 
0
​
 ,3,5,4,1,3]
Recursively call store(nums,3)store(nums, 3)store(nums,3)
store(nums,3)store(nums, 3)store(nums,3)

Back up the number 4 (at index 3)
Store 3 at index 3. The array is now: [0,3,5,3‾,1,3][0,3,5,\underline3,1,3][0,3,5, 
3
​
 ,1,3]
Now call store(nums,4)store(nums, 4)store(nums,4)
store(nums,4)store(nums, 4)store(nums,4)

Back up the number 1 (at index 4)
Store 4 at index 4. The array is now [0,3,5,3,4‾,3][0,3,5,3,\underline4,3][0,3,5,3, 
4
​
 ,3]
Now call store(nums,1)store(nums, 1)store(nums,1)
store(nums,1)store(nums, 1)store(nums,1)

Back up the number 3 (at index 1)
Store 1 at index 1. The array is now [0,1‾,5,3,4,3][0,\underline1,5,3,4,3][0, 
1
​
 ,5,3,4,3]
Now call store(nums,3)store(nums, 3)store(nums,3)
store(nums,3)store(nums, 3)store(nums,3)

Since 3 already exists at index 3 in the array [0,1,5,3‾,4,3][0,1,5,\underline3,4,3][0,1,5, 
3
​
 ,4,3], and we have another instance of 3 that we are trying to store there, clearly that's the duplicate number. Return 3 as the duplicate, and stop execution.

Complexity Analysis

Time Complexity: O(n)O(n)O(n)

The function (storestorestore) makes a single recursive call at every instance. Each index is visited at most once, resulting in O(n)O(n)O(n) time complexity.

Space Complexity: O(n)O(n)O(n)

Since this is a recursive function with up to nnn self-invocations (i.e. depth of the recursive function = nnn), the space complexity is O(n)O(n)O(n) as there can be up to nnn function calls in memory at some point. Note that due to the recursive nature of the solution, there is some additional overhead on each invocation (such as the function variables and a return function pointer that are stored on the system executable stack).

Approach 4.2: Array as HashMap (Iterative)
Intuition

This technique is also known as cyclic sort

The core intuition behind this approach is similar to that of Approach 4.1. Here as well, we start with index 0. Since all numbers are in the range [1,n][1, n][1,n], they will be mapped to indices 111 through nnn inclusive, and hence no number will be mapped to index 000.

The key idea is to always map the number at index 0 to its equivalent index. While in the recursive approach, we directly jump to the next index, in this approach, we will bring the number from the next index to index 000 and continue from there (effectively performing a swap).

Algorithm

At every iteration, compare the number at index 0 (i.e. nums[0]nums[0]nums[0]) to the number at index nums[0]nums[0]nums[0] (i.e. nums[nums[0]]nums[nums[0]]nums[nums[0]]).

Use index 000 as the source of all swapping because we know the number 000 is not in the array.

Take each number at index 000 (let's call it firstfirstfirst) and swap it with the number at its equivalent index in the array (i.e. the number at nums[first]nums[first]nums[first]).

Repeat step 3 until firstfirstfirst is the same as nums[first]nums[first]nums[first] (e.g. if the duplicate number is 333, then keep swapping nums[0]nums[0]nums[0] and nums[nums[0]] until both nums[3]==3nums[3] == 3nums[3]==3 and nums[0]==3nums[0] == 3nums[0]==3).

To illustrate the algorithm, let's consider an example [3,3,5,4,1,3][3,3,5,4,1,3][3,3,5,4,1,3]:

[3‾,3,5,4‾,1,3][\underline3,3,5,\underline4,1,3][ 
3
​
 ,3,5, 
4
​
 ,1,3] // Compare nums[0] to nums[nums[0]] (i.e. nums[0] to nums[3]). 333 != 444. Swap them. Now the first 333 will be swapped into its correct position, and position 0 has 444.
[4‾,3,5,3,1‾,3][\underline4,3,5,3,\underline1,3][ 
4
​
 ,3,5,3, 
1
​
 ,3] // Compare nums[0] to nums[4]. 4 != 1. Not equal, so swap again. Now 4 is in its correct position.
[1‾,3‾,5,3,4,3][\underline1,\underline3,5,3,4,3][ 
1
​
 , 
3
​
 ,5,3,4,3] // Compare nums[0] with nums[1]. Not equal, swap.
[3‾,1,5,3‾,4,3][\underline3,1,5,\underline3,4,3][ 
3
​
 ,1,5, 
3
​
 ,4,3] // Now nums[0] == nums[3] (both are 3). That's it! 3 is in both positions 0 and position 3, so it's the duplicate.

Complexity Analysis

Time Complexity: O(n)O(n)O(n)

Each number needs to be swapped at most once before it is placed in its desired position.

Space Complexity: O(1)O(1)O(1)

No additional storage is needed (barring the temporary variables used for swapping).

Approach 5: Binary Search
Intuition

Consider an array that has nnn distinct numbers in the range [1,n][1,n][1,n]. For example: [1,2,3,4,5][1,2,3,4,5][1,2,3,4,5]. If we pick any one of these 5 numbers and count how many numbers are less than or equal to it, the answer will be equal to that number. So in [1,2,3,4,5][1,2,3,4,5][1,2,3,4,5], if you pick the number 444, there's exactly 4 numbers that are less than or equal to 444. If you pick 333, there's exactly 3 numbers that are less than or equal to 333, and so on. However, when you have duplicates in the array, this count will exceed the number at some point. For example: in [4,3,4,5,2,4,1][4,3,4,5,2,4,1][4,3,4,5,2,4,1], 333 has 3 numbers less than or equal to it. However, the duplicate number will have a count of numbers less than or equal to itself, that is greater than itself (in this example, 444, which is the duplicate, has 6 numbers that are less than or equal to it). Hence, the smallest number that satisfies this property is the duplicate number.

Consider an example: [4,6,4,2,1,4,3,5][4,6,4,2,1,4,3,5][4,6,4,2,1,4,3,5]. This has n+1n + 1n+1 elements where nnn = 777. Take each number from 111 to 777 and count how many numbers are less than or equal to it. In our example, count(1,2,3,4,5,6,7)count(1,2,3,4,5,6,7)count(1,2,3,4,5,6,7) = (1,2,3,6,7,8,8)(1,2,3,6,7,8,8)(1,2,3,6,7,8,8). If we performed a linear scan, we would find that the number 444 is the first number to have its counts exceed the actual number (i.e. 6 > 4) - hence 444 is the duplicate. A linear scan based approach would require an overall O(n2)O(n^2)O(n 
2
 ) time complexity in the worst case, since we'd need to iterate over each of the nnn numbers (requiring O(n)O(n)O(n) time), and then compare it to every element to generate a count of equal or lower numbers (requiring O(n)O(n)O(n) time as well - nested inside the other O(n)O(n)O(n) loop). Fortunately, countcountcount is monotonic (it's values are always in non-decreasing order), and hence it is an excellent candidate for binary search.

In the binary search approach, instead of doing a linear scan from 111 to nnn, we can apply a binary search with a goal of finding the smallest number that satisfies the aforementioned property. We start with a search space of [1,n][1,n][1,n] that has a midpoint midmidmid. If midmidmid satisfies the property, we narrow our search space to the left half [1,mid−1][1, mid - 1][1,mid−1] and continue searching, otherwise, we narrow our search space to the right half [mid+1,n][mid + 1, n][mid+1,n].

To observe the monotonicity of count, consider the evaluation: "For the given number, the count of numbers less than or equal to it, exceeds the number itself". Going back to our example, we had derived: count(1,2,3,4,5,6,7)count(1,2,3,4,5,6,7)count(1,2,3,4,5,6,7) = (1,2,3,6,7,8,8)(1,2,3,6,7,8,8)(1,2,3,6,7,8,8). If we now take the first number and apply said evaluation, we get falsefalsefalse (since count(1)==1count(1) == 1count(1)==1, which is not greater than 1). Applying this evaluation to all counts, we get (false,false,false,true,true,true,true)(false, false, false, true, true, true, true)(false,false,false,true,true,true,true). Observe how this remains falsefalsefalse in the beginning, and switches to truetruetrue for the number 4 (i.e. the duplicate), after which point it remains truetruetrue for all further numbers. Formally, the count for each number must include itself plus the count of all numbers less than itself. Since a number cannot have a negative count, each number, N, must have a count greater than or equal to the count of N-1. Since count(N)>=count(N−1)count(N) >= count(N-1)count(N)>=count(N−1), countcountcount must be monotonically increasing.

Algorithm

To recap, we need to find the smallest number such that the count of numbers less than or equal to it is greater than the number itself.

Apply binary search and start with the entire range of numbers [1,n][1,n][1,n].

Note: Binary search will be applied to the numbers in the range [1,n] (inclusive) regardless of the contents of the array. So even if a number does not exist in the array, we will still evaluate it. For example, if the array is [1,2,4,2,2,5][1,2,4,2,2,5][1,2,4,2,2,5], the algorithm will first evaluate the number 3 even though that number does not exist in the array.
Find the mid-point (curcurcur).

For curcurcur, count how many numbers in the input array are less than or equal to it.

If that number strictly exceeds curcurcur, then store that as the answer and continue to look for a smaller number that satisfies the condition by narrowing the window to the left [low,cur−1][low, cur - 1][low,cur−1].
Otherwise, narrow down the window to the right [cur+1,high][cur + 1, high][cur+1,high].
Repeat step 3 until we've exhausted the search range (i.e. until lowlowlow > highhighhigh) and return the lowest value that met the aforementioned condition.


Complexity Analysis

Time Complexity: O(nlog⁡n)O(n \log n)O(nlogn)

The outer loop uses binary search to identify a candidate - this runs in O(log⁡n)O(\log n)O(logn) time. For each candidate, we iterate over the entire array which takes O(n)O(n)O(n) time, resulting in a total of O(nlog⁡n)O(n \log n)O(nlogn) time.

Space Complexity: O(1)O(1)O(1)

No additional storage is needed (barring a few variables), resulting in a constant O(1)O(1)O(1) space complexity.

Approach 6: Sum of Set Bits
Intuition

Consider an example [3,1,3,2,4][3,1,3,2,4][3,1,3,2,4]. This has n+1n + 1n+1 elements where nnn = 444. If we did not have the duplicate, and instead had every number from 111 through 444, this base array would have been [1,2,3,4][1,2,3,4][1,2,3,4]. Let's look at each of these numbers in binary and count the number of times 1 is seen at each bit position (let's call that base_countbase\_countbase_count). Since the largest number is 444 (1002100_2100 
2
​
  in binary notation), we need to count this for the 3 least significant bits:

Initially, base_countbase\_countbase_count = [0,0,0][0,0,0][0,0,0]
After 1 (in binary, 0012001_2001 
2
​
 ), base_countbase\_countbase_count = [0,0,1][0,0,1][0,0,1]
After 2 (in binary, 0102010_2010 
2
​
 ), base_countbase\_countbase_count = [0,1,1][0,1,1][0,1,1]
After 3 (in binary, 0112011_2011 
2
​
 ), base_countbase\_countbase_count = [0,2,2][0,2,2][0,2,2]
After 4 (in binary, 1002100_2100 
2
​
 ), base_countbase\_countbase_count = [1,2,2][1,2,2][1,2,2]
Now that we have the base count established, let's go through the example array [3,1,3,2,4][3,1,3,2,4][3,1,3,2,4] and calculate the same (sum of 1's set across all bit positions) in this array. Let's call it nums_countnums\_countnums_count:

Initially, nums_countnums\_countnums_count = [0,0,0][0,0,0][0,0,0]
After 3 (in binary, 0112011_2011 
2
​
 ), nums_countnums\_countnums_count = [0,1,1][0,1,1][0,1,1]
After 1 (in binary, 0012001_2001 
2
​
 ), nums_countnums\_countnums_count = [0,1,2][0,1,2][0,1,2]
After 3 (in binary, 0112011_2011 
2
​
 ), nums_countnums\_countnums_count = [0,2,3][0,2,3][0,2,3]
After 2 (in binary, 0102010_2010 
2
​
 ), nums_countnums\_countnums_count = [0,3,3][0,3,3][0,3,3]
After 4 (in binary, 1002100_2100 
2
​
 ), nums_countnums\_countnums_count = [1,3,3][1,3,3][1,3,3]
Comparing nums_countnums\_countnums_count to base_countbase\_countbase_count, we see that the bit count difference is [1,3,3][1,3,3][1,3,3] - [1,2,2][1,2,2][1,2,2] = [0,1,1][0,1,1][0,1,1]. This is the equivalent of the number 3, which is the duplicate. By iterating over each bit, and comparing the base to the current, we were able to construct the duplicate number bit by bit.

So how does this work if the duplicate number appears more than twice? In that case, think of it as simply replacing the missing numbers with the duplicate number, effectively reducing the count of 1's corresponding to the missing numbers and adding 1's associated with the duplicate number - so the algorithm remains intact, since the count of 1's will be even more pronounced in favor of the duplicate number.

To illustrate this, consider the same array but with the duplicate occurring more than twice: [3,1,3,3,3][3,1,3,3,3][3,1,3,3,3] (we've replaced both 222 and 444 with 333). base_countbase\_countbase_count will remain [1,2,2][1,2,2][1,2,2] because nnn still equals 444. However, nums_countnums\_countnums_count becomes [0,4,5][0,4,5][0,4,5]. Comparing nums_countnums\_countnums_count to base_countbase\_countbase_count, we see that the bit count difference is [0,4,5][0,4,5][0,4,5] - [1,2,2][1,2,2][1,2,2] = [−1,2,3][-1,2,3][−1,2,3]. If we consider just the positive counts (seen at positions 0 and 1), this, again is the equivalent of the number 333, which is the duplicate number.

A good question to ask here is "Why does only including the bits with a positive count result in the duplicate number?" To understand this, let's take a step back and reconsider the example array [3,1,3,2,4][3,1,3,2,4][3,1,3,2,4]. However, for this example ignore the binary representation of each number. Pretend base_countbase\_countbase_count is an array where base_count[num]base\_count[num]base_count[num] contains the frequency of number numnumnum. So for the range [1,4][1, 4][1,4], base_countbase\_countbase_count is [1,1,1,1][1, 1, 1, 1][1,1,1,1] and nums_countnums\_countnums_count is the count of each number ([1,1,2,1][1, 1, 2, 1][1,1,2,1]). Then the difference is [1,1,2,1]−[1,1,1,1]=[0,0,1,0][1, 1, 2, 1] - [1, 1, 1, 1] = [0, 0, 1, 0][1,1,2,1]−[1,1,1,1]=[0,0,1,0]. The third index is the only index to have a positive count and thus 3 is the duplicate number.

To meet the constant space requirement, we will consider one bit at a time and count how many times that bit is set in the numbers [1, 2, ..., n], this will be (base_countbase\_countbase_count) for the bit. Then we will count how many times the bit is set in nums, this will be (nums_countnums\_countnums_count) for the bit. If nums_count−base_count>0nums\_count - base\_count > 0nums_count−base_count>0 then this bit must be set in the duplicate number.

A key observation is that if the array had nnn elements instead of n+1n + 1n+1 (where each element is in the range [1,n][1,n][1,n]), this solution would not work. For example, if the input array was [1,3,3][1,3,3][1,3,3], then base_countbase\_countbase_count = [2,2][2,2][2,2] and nums_countnums\_countnums_count = [2,3][2,3][2,3], resulting in a difference of [0,1][0,1][0,1] and hence 111 as the reconstructed number, which is incorrect. The n+1n + 1n+1 number ensures that number from 111 to nnn appear exactly once and plus one extra number.

Algorithm

Since this involves bit manipulation, let's do a brief recap:

(1<<m)(1 << m)(1<<m) accesses the mthm^{th}m 
th
  bit. For example, 1=000121 = 0001_21=0001 
2
​
  and (1<<3)=8=10002(1 << 3) = 8 = 1000_2(1<<3)=8=1000 
2
​
  notice 1 was bit shifted to the left 3 places in the binary representation.
To check if the mthm^{th}m 
th
  bit is set to 111 in a number numnumnum, we can use if(((1<<m)&num)>0)if(((1 << m) \& num) > 0)if(((1<<m)&num)>0). For example, (1 << 2) & 12 = 4 & 12 = 010020100_20100 
2
​
  & 110021100_21100 
2
​
  = 010020100_20100 
2
​
  = 4 which is nonzero, this tells us that the 3rd3^{rd}3 
rd
  bit from the right in the number 12 is set to 1. Notice only bits that were set in both 4 and 12 remain after performing the bitwise AND operation.
Now for the algorithm:

Initialize the answer (duplicateduplicateduplicate) to 000

Iterate over each bit from 000 to bitsbitsbits where bitsbitsbits is the bit-length of nnn.

For each bit, iterate over every number from 111 through nnn and count how many times the bit is set to 111. This will be the base count (base_countbase\_countbase_count).

For each bit, iterate over every number in input array and count how many times the bit is set to 111. This will be the current count (nums_countnums\_countnums_count).

If nums_countnums\_countnums_count > base_countbase\_countbase_count, then set the current bit to 111 in duplicateduplicateduplicate

After checking each bit to see if it should be set in duplicate, and setting the bits with nums_count>base_countnums\_count > base\_countnums_count>base_count to 111, return the duplicate number.


Complexity Analysis

Let nnn be the length of numsnumsnums and mmm be the bit-length of nnn.

Time Complexity: O(nlog⁡n)O(n \log n)O(nlogn)

The outer loop runs a maximum of mmm times (once for each bit in nnn). The inner loop goes over all nnn elements in numsnumsnums, resulting in a total time complexity of O(m⋅n)O(m \cdot n)O(m⋅n).

It is a common misconception to treat mmm as a constant because it is small and thus consider this to be a linear time complexity algorithm. Setting the problem constraints aside, the value of mmm depends on nnn. More specifically, mmm is the bit-length of nnn which is approximately equal to log2(n)log_2(n)log 
2
​
 (n). Thus this algorithm has linearithmic time complexity.

Space Complexity: O(1)O(1)O(1)

No additional storage is needed (barring a few variables), resulting in a constant O(1)O(1)O(1) space complexity.

Approach 7: Floyd's Tortoise and Hare (Cycle Detection)
Intuition

The idea is to reduce the problem to
Linked List Cycle II:

Given a linked list, return the node where the cycle begins.

First of all, where does the cycle come from?
Let's use the function f(x) = nums[x] to construct the sequence:
x, nums[x], nums[nums[x]], nums[nums[nums[x]]], ....

Each new element in the sequence is an element in nums at the index
of the previous element.

If one starts from x = nums[0], such a sequence will produce a linked list
with a cycle.

The cycle appears because nums contains duplicates. The duplicate node
is a cycle entrance.

Here is how it works:

pic

The example above is simple because the loop is small. Here is a
more interesting example
(special thanks to @sushant_chaudhari)

pic

Now the problem is to find the entrance of the cycle.

Algorithm

Floyd's algorithm
consists of two phases and uses two pointers, usually called tortoise and hare.

In phase 1, hare = nums[nums[hare]] is twice as fast as
tortoise = nums[tortoise]. Since the hare goes fast,
it would be the first to enter the cycle and run around the cycle.
At some point, the tortoise enters the cycle as well, and since
it's moving slower the hare catches up to the tortoise at some intersection point.
Now phase 1 is over, and the tortoise has lost.

Note that the intersection point is not the cycle entrance in the general case.

pic

To compute the intersection point, let's note that the hare has
traversed twice as many nodes as the tortoise,
i.e. 2d(tortoise)=d(hare)2d(\text{tortoise}) = d(\text{hare})2d(tortoise)=d(hare), implying:

2(F+a)=F+nC+a2(F + a) = F + nC + a2(F+a)=F+nC+a, where nnn is some integer.

Hence the coordinate of the intersection point is F+a=nCF + a = nCF+a=nC.

In phase 2, we give the tortoise a second chance by slowing down the hare,
so that it now moves at the speed of tortoise: tortoise = nums[tortoise],
hare = nums[hare]. The tortoise is back at the starting
position, and the hare starts from the intersection point.

pic

Let's show that this time they meet at the cycle entrance after FFF steps.

The tortoise started at zero, so its position after FFF steps is FFF.

The hare started at the intersection point F+a=nCF + a = nCF+a=nC,
so its position after F steps is
nC+FnC + FnC+F, that is the same point as FFF.

So the tortoise and the (slowed down) hare will meet at the entrance of the cycle.

Current


Complexity Analysis

Time Complexity: O(n)O(n)O(n)

Space Complexity: O(1)O(1)O(1)
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //cyclic sort:
        while(nums[0] != nums[nums[0]]){
            swap(nums[0],nums[nums[0]]);
        }
        return nums[0];
    }
};