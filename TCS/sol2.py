def min_string_factor(X, Y, S, R):
    from functools import lru_cache
    n, m = len(X), len(Y)

    @lru_cache(None)
    def dp(i):
        if i == 0:
            return 0
        res = float('inf')
        for j in range(i):
            if X[j:i] in Y:
                res = min(res, dp(j) + S)
            if X[j:i] in Y[::-1]:
                res = min(res, dp(j) + R)
        return res

    result = dp(n)
    return result if result != float('inf') else "Impossible"

if __name__ == "__main__":
    X = input().strip()
    Y = input().strip()
    S, R = map(int, input().split())
    
    result = min_string_factor(X, Y, S, R)
    print(result)
