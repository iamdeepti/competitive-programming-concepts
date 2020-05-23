## Fenwick Tree
<br/>
Fenwick trees are similar to segment trees. Like a segment tree, you can update and query in log(n) time. The benefit of using a Fenwick tree over segment trees are
1) Fenwick tree consumes lesser space than a segment tree
2) The update and query function in Fenwick tree are simpler and iterative.
In a segment tree, the first index is our root node and we recursively update the child nodes which stores the answer for a given segment. In the same way, an array is used to represent a Fenwick tree and the first node can be considered as root. To answer a given query we traverse up in a Fenwick tree by switching the least significant bit off in the index. For example, if we're at index 7 which is 111 in binary, we'll set the last bit to zero resulting in 110 i.e 6 in decimal, and on doing again we will get 100 i.e. and finally, we'll reach zero. So all these indexes (i.e. 7, 6, 4, 0) contain the answer to our query and will be added up to give the final answer. In Fenwick tree also a given index stores answer for a particular range, and to get an answer from 0 to a particular index, we traverse up in the given way to get the answer. So let's say you want to calculate the answer for a range (l,r) then you can query for (0,r) and (0,l-1) and subtract them.

The function to update the tree is also similar to query function, here instead of traversing up we traverse down. For a given index we'll need to update all those indexes that can be affected by it. For example, if the given index is 7 i.e. 111 in binary, the index that will be affected can be calculated again by adding the least significant bit to it, so we'll be adding 1 to 111, resulting in 1000 i.e. 8 in binary and repeating the process we will reach 16, 32 up to n. So here the update and query function for a Fenwick tree of size n will look like,
void update(int * BIT,int value,int index,int n)
{
    for(;index<=n;index += index&(-index))
        BIT[index] += value;
}
int query(int * BIT,int index,int n)
{
    int ans = 0;
    for(;index>0;index -= index&(-index))
        ans += BIT[index];
    return ans;
}
Unlike the segment tree, the functions here are iterative and therefore consumes lesser memory. Also for an array of size n, we need up to 4*n space for a segment tree, whereas in Fenwick tree only n+1 space is required. 
Time complexity for update and query function
Since we have seen that in update function we unset the least significant bit, therefore the time complexity for it will be the number of bits in a given number. The maximum index can be n and the number of bits in n is log(n), hence update function is O(logn). The same reasoning can be used for query function.
Now the next question that pops into mind is can Fenwick tree always replace a segment tree? The answer is no, it can be used only if the answer can be expressed as a cumulative sum. Segment trees are more powerful implementation and offer more operations than a Fenwick tree. 
In competitive programming usually, the time limits and memory limits are too strict to use segment tree, so use Fenwick trees as and when possible in place of a segment tree.