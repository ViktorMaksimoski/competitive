#include <string>
#include <vector>
#include <queue>
using ll = long long;
using namespace std;

class TimeMaze {
    public:
    int minTime(vector<string> maze, int htime, int vtime)
    {
        int rows = maze.size(), cols = maze[0].size();
        //cout << rows << " " << cols << endl;
        bool vis[rows][cols];
        ll dist[rows][cols];
        memset(vis, 0, sizeof(vis));
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) dist[i][j] = 1e9;
        }
        int dr[4] = {0, 0, 1, -1};
        int dc[4] = {1, -1, 0, 0};

        pair<int, int> s, e;
        for(int i=0; i<maze.size(); i++) {
            for(int j=0; j<maze[i].size(); j++) {
                if(maze[i][j] == 'S') s = {i, j}, maze[i][j] = '0';
                if(maze[i][j] == 'E') e = {i, j}, maze[i][j] = '0';
            }
        }

        priority_queue<pair<int , pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({ 0, s });
        dist[s.first][s.second] = 0;

        while(!pq.empty()) {
            int weight = pq.top().first;
            auto node = pq.top().second;
            pq.pop();

            //cout << node.first << " " << node.second << '\n';

            if(vis[node.first][node.second]) continue;
            vis[node.first][node.second] = true;

            if(node == e) break;

            for(int i=0; i<4; i++) {
                int newR = node.first + dr[i];
                int newC = node.second + dc[i];

                if(newR < 0 || newR >= rows || newC < 0 || newC >= cols) continue;
                if(vis[newR][newC]) continue;
                if(maze[newR][newC] == '#') continue;

                int nextWeight = (maze[node.first][node.second] - '0');
                if(i < 2) nextWeight += htime;
                else nextWeight += vtime;

                if(dist[node.first][node.second] + nextWeight < dist[newR][newC]) {
                    pq.push({ dist[newR][newC] = dist[node.first][node.second] + nextWeight, make_pair(newR, newC) });

                }
            }
        }

        return (vis[e.first][e.second] ? dist[e.first][e.second] : -1);
    }
};

/*
int main()
{
    cout << TimeMaze().minTime({"S#1","#11","11E"}, 9, 9) << '\n';

    return 0;
}
*/