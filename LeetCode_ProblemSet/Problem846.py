class Solution(object):
    def isNStraightHand(self, hand, groupSize):
        """
        :type hand: List[int]
        :type groupSize: int
        :rtype: bool
        """
        # always possible
        if groupSize == 1:
            return True

        # not possible to make groups
        if len(hand) % groupSize != 0:
            return False

        hands = {}

        # store in dict
        for i in range(len(hand)):
            if hand[i] in hands:
                hands[hand[i]] += 1
            else:
                hands[hand[i]] = 1

        vals = sorted(hands.keys())

        for val in vals:
            while hands[val] > 0:
                for i in range(groupSize):
                    if (val + i) in vals and hands[val + i] > 0:
                        hands[val + i] -= 1
                    else:
                        return False

        return True

