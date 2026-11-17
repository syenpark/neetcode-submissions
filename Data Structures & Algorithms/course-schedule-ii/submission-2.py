class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        answers = []

        pre_matrix = [[] for _ in range(numCourses)]
        current_matrix = [[] for _ in range(numCourses)]
        queue = deque([])

        for c, pre in prerequisites:
            pre_matrix[c].append(pre)
            current_matrix[pre].append(c)

        for c in range(numCourses):
            if len(pre_matrix[c]) == 0:
                queue.append(c)

        while queue:
            current_course = queue.popleft()
            answers.append(current_course)

            for next_ in current_matrix[current_course]:
                pre_matrix[next_].remove(current_course)

                if len(pre_matrix[next_]) == 0:
                    queue.appendleft(next_)

        return answers if len(answers) == numCourses else []

        