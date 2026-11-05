from collections import deque

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        queue = deque()
        matrix = {c: [] for c in range(numCourses)}
        indegree = [0] * numCourses
        taken = 0

        for c, p in prerequisites:
            matrix[p].append(c)
            indegree[c] += 1

        for c in range(numCourses):
            if indegree[c] == 0:
                queue.append(c)

        while queue:
            for _ in range(len(queue)):
                course = queue.popleft()
                taken += 1

                for nxt in matrix[course]:
                    indegree[nxt] -= 1

                    if indegree[nxt] == 0:
                        queue.append(nxt)

        return taken == numCourses
        