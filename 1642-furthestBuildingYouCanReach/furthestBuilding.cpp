#include <queue>
#include <vector>

// dp solution. Memory exceeded!
class BadSolution {
private:
  std::vector<std::vector<std::vector<int>>> dp;
  int furthestBuildingRec(std::vector<int> &heights, int bricks, int ladders,
                          int idx) {
    if (dp[idx][bricks][ladders] != -1) {
      return dp[idx][bricks][ladders];
    }
    if (idx == heights.size() - 1) {
      return idx;
    }
    int heightDiff = heights[idx + 1] - heights[idx];
    // If heights[i] >= heights[i+1] we good
    if (heightDiff > 0) {
      // If heights[i] < heights[i+1] we either use a ladder or
      // heights[i+1]-heights[i] bricks
      int w_ladder = idx;
      int w_bricks = idx;
      if (ladders > 0) {
        w_ladder = furthestBuildingRec(heights, bricks, ladders - 1, idx + 1);
      }
      if (bricks > heightDiff) {
        w_bricks =
            furthestBuildingRec(heights, bricks - heightDiff, ladders, idx + 1);
      }
      dp[idx][bricks][ladders] = std::max(w_ladder, w_bricks);
    } else {
      dp[idx][bricks][ladders] =
          furthestBuildingRec(heights, bricks, ladders, idx + 1);
    }
    return dp[idx][bricks][ladders];
  }

public:
  int furthestBuilding(std::vector<int> &heights, int bricks, int ladders) {
    dp = std::vector<std::vector<std::vector<int>>>(
        heights.size(), std::vector<std::vector<int>>(
                            bricks + 1, std::vector<int>(ladders + 1, -1)));
    return furthestBuildingRec(heights, bricks, ladders, 0);
  }
};

// Greedy pq solution
class Solution {
public:
  int furthestBuilding(std::vector<int> &heights, int bricks, int ladders) {
    std::priority_queue<int> pq;
    int used_bricks = 0;
    int i;
    for (i = 0; i < heights.size() - 1; i++) {
      int height_diff = heights[i + 1] - heights[i];
      if (height_diff <= 0) {
        continue;
      }
      if (bricks - used_bricks >= height_diff) {
        // while we can use bricks we do so.
        pq.push(height_diff);
        used_bricks += height_diff;
      } else {
        // we swap the biggest height for a ladder.
        if (ladders > 0) {
          if (pq.size() > 0 && height_diff < pq.top()) {
            used_bricks -= pq.top();
            pq.pop();
            used_bricks += height_diff;
            pq.push(height_diff);
          }
          ladders--;
        } else {
          break;
        }
      }
    }
    return i;
  }
};
