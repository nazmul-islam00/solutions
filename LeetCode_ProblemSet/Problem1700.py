from collections import deque

class Solution(object):
    def countStudents(self, students, sandwiches):
        """
        :type students: List[int]
        :type sandwiches: List[int]
        :rtype: int
        """
        prefersCircular = sum([1 for student in students if student == 0])
        prefersSquare = len(students) - prefersCircular
        preferenceCount = [prefersCircular, prefersSquare]
        students = deque(students)
        idx = 0
        
        while len(students) > 0:
            student = students.popleft()
            if student == sandwiches[idx]:
                preferenceCount[sandwiches[idx]] -= 1
                idx += 1
            elif preferenceCount[sandwiches[idx]] == 0:
                return len(students) + 1
            else:
                students.append(student)
                
        return 0
        