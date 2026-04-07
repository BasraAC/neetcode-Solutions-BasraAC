class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        hashSet = {}
        for num in nums: 
            if num in hashSet:
                hashSet[num] += 1
            else:
                hashSet[num] = 1
        sorted_dict = sorted(hashSet.items(), key=lambda item: item[1])
        val = []
        for num in range(0,k):
            val.append(sorted_dict[len(sorted_dict) - num - 1][0])
        return val