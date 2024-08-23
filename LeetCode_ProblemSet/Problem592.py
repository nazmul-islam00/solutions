class Solution(object):
    def fractionAddition(self, expression):
        """
        :type expression: str
        :rtype: str
        """
        # The input string only contains '0' to '9', '/', '+' and '-'. So does the output.
        # Each fraction (input and output) has the format ±numerator/denominator. If the first input fraction or the output is positive, then '+' will be omitted.
        # The input only contains valid irreducible fractions, where the numerator and denominator of each fraction will always be in the range [1, 10]. If the denominator is 1, it means this fraction is actually an integer in a fraction format defined above.
        # The number of given fractions will be in the range [1, 10].
        # The numerator and denominator of the final result are guaranteed to be valid and in the range of 32-bit int.

        fractions = self.parseExpression(expression)
        answer = fractions[0]

        for idx in range(1, len(fractions)):
            answer = self.addFractions(answer, fractions[idx])
        
        gcd = self.gcd(abs(answer[0]), answer[1])
        answer = [int(answer[0] / gcd), int(answer[1] /gcd)]

        return str(answer[0]) + '/' + str(answer[1])
    
    def gcd(self, firstNumber, secondNumber):
        if firstNumber == 0:
            return secondNumber
        
        return self.gcd(secondNumber % firstNumber, firstNumber)

    def addFractions(self, firstFraction, secondFraction):
        numerator = (
            firstFraction[0] * secondFraction[1] + secondFraction[0] * firstFraction[1]
        )
        denominator = firstFraction[1] * secondFraction[1]
        return [numerator, denominator]

    def parseExpression(self, expression):
        # add + if first term is positive
        if expression[0] != "-":
            expression = "+" + expression

        idx = 0
        fractions = []

        while idx < len(expression):
            # parse symbol
            isPositive = 1 if expression[idx] == "+" else -1
            idx += 1

            # parse numerator and slash
            if expression[idx + 1] == "/":
                numerator = int(expression[idx])
                idx += 2
            else:
                numerator = int(expression[idx : idx + 2])
                idx += 3

            # parse denominator
            if idx + 1 < len(expression) and expression[idx + 1] not in ("+", "-"):
                denominator = int(expression[idx : idx + 2])
                idx += 2
            else:
                denominator = int(expression[idx])
                idx += 1

            fractions.append([isPositive * numerator, denominator])

        return fractions
