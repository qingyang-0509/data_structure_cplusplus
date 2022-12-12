#include "graph.h"
#include <stack>
#include <queue>

graph::Edge::Edge(int src, int dst, int cst = 1)
{
	source = src;
	destination = dst;
	cost = cst;
	next = nullptr;
}

graph::graph(int cnt)
{
	count = cnt;
	ListVector = std::vector<Adjacent_list*>(cnt);
	for (int i = 0; i < cnt; i++)
	{
		ListVector[i] = new Adjacent_list();
		ListVector[i]->head = nullptr;
	}
}

void graph::add_edge(int source, int destination, int cost)
{
	Edge* edge = new Edge{ source, destination, cost };
	edge->next = ListVector[source]->head;
	ListVector[source]->head = edge;
}

void graph::add_edge(int source, int destination)
{
	add_edge(source, destination, 1);
}

void graph::add_bidirectional_edge(int source, int destination, int cost)
{
	add_bidirectional_edge(source, destination, cost);
}

void graph::add_bidirectional_edge(int source, int destination)
{
	add_edge(source, destination, 1);
	add_edge(destination, source, 1);
}

bool graph::EdgeComparator::operator()(graph::Edge* x, graph::Edge* y)
{
	if (x->cost <= y->cost)
	{
		return true;
	}
	return false;
}

void graph::DFSStack()
{
	std::vector<int> visited(count);
	int curr;
	std::stack<int> stk;
	for (int i = 0; i < count; i++)
		visited[i] = 0;
	visited[0] = 1;
	stk.push(0);
	while (!stk.empty())
	{
		curr = stk.top();
		stk.pop();
		Edge* head = ListVector[curr]->head;
		while (head != nullptr)
		{
			if (visited[head->destination] == 0)
			{
				visited[head->destination] = 1;
				stk.push(head->destination);
			}
			head = head->next;
		}
	}
}


/****************************************************************************************************/
/* Recursion based implementation of DFS */
void graph::DFS()
{
	std::vector<int> visited(count);
	for (int i = 0; i < count; i++)
	{
		visited[i] = 0;
	}
	for (int i = 0; i < count; i++)
	{
		if (visited[i] == 0)
		{
			visited[i] = 1;
			DFSRecursion(i, visited);
		}
	}
}

void graph::DFSRecursion(int index, std::vector<int>& visited)
{
	Edge* head = ListVector[index]->head;
	while (head != nullptr)
	{
		if (visited[head->destination] == 0)
		{
			visited[head->destination] = 1;
			DFSRecursion(head->destination, visited);
		}
		head = head->next;
	}
}

/****************************************************************************************************/

void graph::BFS()
{
	std::vector<int> visited(count);
	for (int i = 0; i < count; i++)
	{
		visited[i] = 0;
	}
	for (int i = 0; i < count; i++)
	{
		if (visited[i] == 0)
		{
			BFSQueue(i, visited);
		}
	}
}

void graph::BFSQueue(int index, std::vector<int>& visited)
{
	int curr;
	std::queue<int> que;
	visited[index] = 1;
	que.push(index);
	while (que.empty() == false)
	{
		curr = que.front();
		que.pop();
		Edge* head = ListVector[curr]->head;
		while (head != nullptr)
		{
			if (visited[head->destination] == 0)
			{
				visited[head->destination] = 1;
				que.push(head->destination);
			}
			head = head->next;
		}
	}
}