class Solution(object):
    def commonChars(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        character_counts = [0] * 26

        for c in words[0]:
            character_counts[ord(c) - ord('a')] += 1

        for word in words[1:]:
            character_count = [0] * 26

            for c in word:
                character_count[ord(c) - ord('a')] += 1

            for i in range(26):
                character_counts[i] = min(character_count[i], character_counts[i])

        ans = []

        for i in range(26):
            for _ in range(character_counts[i]):
                ans.append(chr(i + ord('a')))

        return ans
