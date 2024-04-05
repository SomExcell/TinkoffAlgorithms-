#include <bits/stdc++.h>

std::vector<std::pair<int, int>> graph[100001];

int search(int value)
{
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,std::greater<std::pair<int, int>>> priorityQueue;
	std::vector<int> dist(value + 2, 1e9);

	priorityQueue.push({0, 1});
	dist[1] = 0;
	while (!priorityQueue.empty()) {
		int current = priorityQueue.top().second;
		priorityQueue.pop();
		for (auto& neighbours : graph[current]) 
        {
			int v = neighbours.first;
			int weight = neighbours.second;
			if (dist[v] > dist[current] + weight) {
				dist[v] = dist[current] + weight;
				priorityQueue.push({dist[v], v});
			}
		}
	}

	return  1 + dist[0];
}

void minSum(int value)
{
	for (int i = 1; i <= value; ++i) 
    {
		int from = (i) % value;
		int to = (i + 1) % value;
		graph[from].push_back({to, 1});
	}

	for (int i = 1; i <= value; ++i) 
    {
		int from = (i) % value;
		int to = (10 * i) % value;
		graph[from].push_back({to, 0});
	}
}

int main()
{
    int value;
    std::cin >> value;
	minSum(value);
    std::cout << search(value);

	return 0;
}