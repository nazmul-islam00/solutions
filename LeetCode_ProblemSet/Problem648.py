class Solution(object):
    def replaceWords(self, dictionary, sentence):
        """
        :type dictionary: List[str]
        :type sentence: str
        :rtype: str
        """
        # sort dictionary by length of the roots
        roots = sorted(dictionary, key=lambda x: len(x))

        answer = ""

        # replace words
        for word in sentence.split(" "):
            new_word = word

            for root in roots:
                if word.startswith(root):
                    new_word = root
                    break

            answer += new_word + " "

        return answer.strip()