//Algorithm using Dynamic Programming

if three consecutive 0's:
              dp[i] = max(dp[i-1], p + dp[i-3])
          else if 1, 0 or 0, 1:
              dp[i] = max(dp[i-1], q + dp[i-2])
          
          return dp[n-1]
