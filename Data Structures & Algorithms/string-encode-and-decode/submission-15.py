class Solution:

    def encode(self, strs: List[str]) -> str:
        res = ""
        for string in strs:
            res += string + "xz"
        return res 

    def decode(self, s: str) -> List[str]:
        if s == " ":
            return [""]
        else:
            decoded = list(s.split('xz'))
            return decoded[0:len(decoded)-1]
