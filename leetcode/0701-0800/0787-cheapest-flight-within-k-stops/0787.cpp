/**
 * https://leetcode.com/problems/cheapest-flights-within-k-stops/
 */

#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

struct G {
public:
    vector<vector<tuple<int, int>>> edges;

    G(int n, vector<vector<int>> &flights) : edges(n)
    {
        for (auto &&f : flights) {
            edges[f[0]].push_back({f[1], f[2]});
        }
    }
};

class Solution1 // (!)
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        G g(n, flights);
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> queue;

        vector<int> dists(n, INT_MAX);
        vector<int> steps(n, INT_MAX);

        dists[src] = 0;
        steps[src] = 0;

        queue.push({0, 0, src});

        while (!queue.empty()) {
            auto [curDist, curStep, curNode] = queue.top();
            queue.pop();

            // feasible with smallest distance
            if (curNode == dst) {
                return curDist;
            }

            // (s) -> (1) -> (2) -> (3 = k) -> (t), means that we can skip
            // those having k + 1

            if (curStep >= k + 1) {
                continue;
            }

            for (auto &&[to, dist] : g.edges[curNode]) {
                auto nxtStep = curStep + 1;
                auto nxtDist = curDist + dist;

                if (nxtDist < dists[to] || nxtStep < steps[to]) {
                    dists[to] = nxtDist;
                    steps[to] = nxtStep;
                    queue.push({nxtDist, nxtStep, to});
                }
            }
        }

        return -1;
    }
};

class Solution2 // (!)
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        // bellman-ford's modification

        vector<int> curDists(n, INT_MAX);
        curDists[src] = 0;

        for (int i = 0; i < k + 1; ++i) {
            vector<int> nxtDists(curDists.begin(), curDists.end());

            for (auto &&f : flights) {
                auto fr = f[0];
                auto to = f[1];
                auto di = f[2];

                if (curDists[fr] != INT_MAX && curDists[fr] + di < nxtDists[to]) {
                    nxtDists[to] = curDists[fr] + di;
                }
            }

            curDists = move(nxtDists);
        }

        return curDists[dst] == INT_MAX ? -1 : curDists[dst];
    }
};

int main()
{
    return 0;
}
