class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hashSet = {}

        for string in strs:
            if str(sorted(string)) in hashSet:
                hashSet[str(sorted(string))].append(string)
            else:
                hashSet[str(sorted(string))] = [string] 
        return list(hashSet.values())        