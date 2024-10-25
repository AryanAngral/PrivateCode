from collections import defaultdict

def maximum_expertise(n, conflicts, expertise):
    """Finds the maximum possible expertise of a team given conflicts and expertise values.

    Args:
        n: The number of employees.
        conflicts: A list of tuples representing conflicts between employees.
        expertise: A list of integers representing the expertise values of employees.

    Returns:
        The maximum possible expertise of a team.
    """

    # Create a graph representing conflicts
    graph = defaultdict(list)
    for u, v in conflicts:
        graph[u].append(v)
        graph[v].append(u)

    # Define a recursive function to find the expertise of a connected component
    def dfs(node, visited):
        visited.add(node)
        total_expertise = expertise[node - 1]  # expertise[node-1] since employees are 1-indexed

        for neighbor in graph[node]:
            if neighbor not in visited:
                total_expertise += dfs(neighbor, visited)

        return total_expertise

    # Find all connected components and their expertise totals
    total_expertise_sum = 0
    visited = set()
    
    for node in range(1, n + 1):
        if node not in visited:
            # Calculate the expertise for the connected component starting at this node
            component_expertise = dfs(node, visited)
            total_expertise_sum += component_expertise

    return total_expertise_sum

if __name__ == "__main__":
    n, c = map(int, input().split())  # number of employees and conflicts
    conflicts = []
    for _ in range(c):
        u, v = map(int, input().split())  # reading conflict pairs
        conflicts.append((u, v))
    
    expertise = list(map(int, input().split()))  # reading expertise values
    result = maximum_expertise(n, conflicts, expertise)
    print(result)
