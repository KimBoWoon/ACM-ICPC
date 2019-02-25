#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n, m, a, b;
vector<vector<int> > graph;
int indegree[32001];
vector<int> answer;

/*
1) indegree(진입차수) 가 0인 점을 큐에 넣고 탐색을 시작한다.
2) 현재점과 연결된 정점의 진입차수를 1 감소시킨다.
3) 그 중 진입차수가 0이 되는 점을 큐에 넣고 반복
진입차수가 0인 점을 넣는 순서가 위상정렬의 순서이다.
*/
void bfs() {
    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) { // 현재 진입차수가 0인 점을 큐에 넣음
            q.push(i);
            answer.push_back(i);
        }
    }

    while (!q.empty()) {
        int here = q.front();
        q.pop();

        for (int i = 0; i < graph[here].size(); i++) {
            int there = graph[here][i];
            indegree[there]--; // 연결된 곳의 차수를 1씩 감소해준다.
            if (indegree[there] == 0) { // 다시 0인 곳을 큐에 넣음
                q.push(there);
                answer.push_back(there);
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    graph.resize(n + 1);

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        graph[a].push_back(b); // a가 b앞에 와야 한다.
        indegree[b]++;         // b의 진입차수 증가
    }

    bfs();

    for (int i = 0; i < answer.size(); i++) {
        printf("%d ", answer[i]);
    }
    printf("\n");

    return 0;
}

// #include <cstdio>
// #include <algorithm>
// #include <vector>

// using namespace std;

// int n, m, a, b;
// vector<vector<int> > graph;
// bool visited[32001];
// vector<int> answer;


// // dfs의 재귀를 탈출하는 곳은 이 정점과 연결된 점을 이미 전부 방문한 뒤 이므로 
// // -> 재귀를 탈출 할 때 마다 넣어두고 최종 결과를 뒤집어 주면 위상정렬한 상태가 나온다.
// void dfs(int here) {
//     if(visited[here]) {
//         return;
//     }

//     visited[here] = true;

//     for(int i = 0; i < graph[here].size(); i++) {
//         int there = graph[here][i];
//         dfs(there);
//     }

//     answer.push_back(here); // 재귀 탈출 하면서 현재 정점을 넣어준다.
// }

// int main() {
//     scanf("%d %d", &n, &m);

//     graph.resize(n+1);

//     for(int i=0;i<m;i++) {
//         scanf("%d %d", &a, &b);
//         graph[a].push_back(b); // a가 b앞에 와야 한다.
//     }

//     for(int i = 1; i <= n; i++) {
//         dfs(i);
//     }

//     reverse(answer.begin(), answer.end()); // 결과를 뒤집어 준다.

//     for(int i = 0; i < answer.size(); i++) {
//         printf("%d ", answer[i]);
//     }
//     printf("\n");
    
//     return 0;
// }