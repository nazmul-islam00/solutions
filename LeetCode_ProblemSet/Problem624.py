class Solution(object):
    def maxDistance(self, arrays):
        """
        :type arrays: List[List[int]]
        :rtype: int
        """
        _max_min = [self.get_max_min(array) for array in arrays]
        _max = sorted([(_max_min[idx][0], idx) for idx in range(len(arrays))], reverse=True)
        _min = sorted([(_max_min[idx][1], idx) for idx in range(len(arrays))])
        
        # if the smallest & largest are not from the same array
        if _max[0][1] != _min[0][1]:
            return _max[0][0] - _min[0][0]
        # if both are from the same array
        return max(
            abs(_max[0][0] - _min[1][0]),
            abs(_max[1][0] - _min[0][0])
        )
    
    def get_max_min(self, array):
        _max, _min = array[0], array[0]
        for num in array:
            _max = max(_max, num)
            _min = min(_min, num)
        return [_max, _min]
        
    
    