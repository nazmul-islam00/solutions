class Solution(object):
    def numberToWords(self, num):
        """
        :type num: int
        :rtype: str
        """
        if num == 0:
            return "Zero"
        parts = self.getParts(num)
        repr = self.getRepresentation(parts)
        return repr
        
    def getParts(self, num):
        parts = []
        while num >= 1000:
            parts.append(num % 1000)
            num = int(num / 1000)
        parts.append(num)
        return parts
    
    def getRepresentation(self, parts):
        repr = ""
        for idx in range(len(parts) - 1, -1, -1):
            partRepr = self.getString(parts[idx])
            if partRepr != "":
                repr += partRepr + " " + self.getSuffix(idx) + " "
        return repr.strip()
    
    def getString(self, num):
        hundreds = int(num / 100)
        num %= 100
        repr1 = self.getWordForHundreds(hundreds)
        
        decades = int(num / 10)
        rest = num % 10
        if decades == 1:
            repr2 = self.getWord__(num)
        else:
            repr2 = self.getWordForDecades(decades)
            repr3 = self.getWordForRest(rest)
            if repr3 != "" and repr2 != "":
                repr2 += " "
            repr2 = repr2 + repr3
        
        if repr1 == "":
            return repr2
        if repr2 == "":
            return repr1
        return repr1 + " " + repr2
        
    def getWordForHundreds(self, digit):
        match digit:
            case 0: return ""
            case 1: return "One Hundred"
            case 2: return "Two Hundred"
            case 3: return "Three Hundred"
            case 4: return "Four Hundred"
            case 5: return "Five Hundred"
            case 6: return "Six Hundred"
            case 7: return "Seven Hundred"
            case 8: return "Eight Hundred"
            case 9: return "Nine Hundred"
            
    def getWordForDecades(self, digit):
        match digit:
            case 0: return ""
            case 2: return "Twenty"
            case 3: return "Thirty"
            case 4: return "Forty"
            case 5: return "Fifty"
            case 6: return "Sixty"
            case 7: return "Seventy"
            case 8: return "Eighty"
            case 9: return "Ninety"
            
    def getWordForRest(self, digit):
        match digit:
            case 0: return ""
            case 1: return "One"
            case 2: return "Two"
            case 3: return "Three"
            case 4: return "Four"
            case 5: return "Five"
            case 6: return "Six"
            case 7: return "Seven"
            case 8: return "Eight"
            case 9: return "Nine"
            
    def getWord__(self, num):
        match num:
            case 10: return "Ten"
            case 11: return "Eleven"
            case 12: return "Twelve"
            case 13: return "Thirteen"
            case 14: return "Fourteen"
            case 15: return "Fifteen"
            case 16: return "Sixteen"
            case 17: return "Seventeen"
            case 18: return "Eighteen"
            case 19: return "Nineteen"
            
    def getSuffix(self, idx):
        match idx:
            case 0: return ""
            case 1: return "Thousand"
            case 2: return "Million"
            case 3: return "Billion"