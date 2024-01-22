#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int moves[8][2] = {{2, 1}, {1, 2}, {-2, 1}, {-1, 2}, {2, -1}, {1, -2}, {-2, -1}, {-1, -2}};

bool isValid(int x, int y) {
    return x >= 1 && x <= 8 && y >= 1 && y <= 8;
}

pair<int, pair<int, int>> bfs(int startX, int startY, int targetX, int targetY) {
    vector<vector<bool>> visited(8, vector<bool>(8, false));
    vector<vector<int>> distance(8, vector<int>(8, -1));
    vector<vector<pair<int, int>>> parent(8, vector<pair<int, int>>(8, {-1, -1}));
    queue<pair<int, int>> q;

    q.push({startX, startY});
    visited[startX - 1][startY - 1] = true;
    distance[startX - 1][startY - 1] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == targetX && y == targetY) {
            return {distance[x - 1][y - 1], parent[x - 1][y - 1]};
        }

        for (int i = 0; i < 8; ++i) {
            int newX = x + moves[i][0];
            int newY = y + moves[i][1];
            if (isValid(newX, newY) && !visited[newX - 1][newY - 1]) {
                visited[newX - 1][newY - 1] = true;
                distance[newX - 1][newY - 1] = distance[x - 1][y - 1] + 1;
                parent[newX - 1][newY - 1] = {x, y};
                q.push({newX, newY});
            }
        }
    }

    return {-1, {-1, -1}};
}

int main() {
    int numTests;
    cin >> numTests;

    vector<pair<vector<pair<int, int>>, pair<int, int>>> testCases;

    for (int t = 0; t < numTests; ++t) {
        vector<pair<int, int>> knights(4);
        pair<int, int> king;
        for (int i = 0; i < 5; ++i) {
            string position;
            cin >> position;
            int x = position[1] - '0';
            int y = position[0] - 'a' + 1;
            if (i == 4) {
                king = {x, y};
            } else {
                knights[i] = {x, y};
            }
        }
        testCases.push_back({knights, king});
    }

    vector<vector<int>> results;

    for (const auto& testCase : testCases) {
        const vector<pair<int, int>>& knights = testCase.first;
        const pair<int, int>& king = testCase.second;

        int minMovesCount = INT_MAX;
        vector<int> movesCounts;

        for (const auto& knight : knights) {
            pair<int, pair<int, int>> result = bfs(knight.first, knight.second, king.first, king.second);
            int movesCount = result.first - 1;
            movesCounts.push_back(movesCount);
            if (movesCount < minMovesCount) {
                minMovesCount = movesCount;
            }
        }

        vector<int> output;
        for (int movesCount : movesCounts) {
            if (movesCount == minMovesCount) {
                output.push_back(movesCount);
            }
        }
        results.push_back(output);
    }

    for (const vector<int>& output : results) {
        for (int movesCount : output) {
            cout << movesCount << " ";
        }
    }

    return 0;
}