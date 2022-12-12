#include <vector>

class graph
{
private:
	struct Edge
	{
		int source;
		int destination;
		int cost;
		Edge* next;

		Edge(int src, int dst, int cst);
	};

	struct Adjacent_list
	{
		Edge* head;
	};
	int count;
	std::vector<Adjacent_list*> ListVector;

	class EdgeComparator
	{
	public:
		bool operator()(Edge* x, Edge* y);
	};

public:
	explicit graph(int cnt);

	virtual void add_edge(int source, int destination, int cost);

	virtual void add_edge(int source, int destination);

	virtual void add_bidirectional_edge(int source, int destination, int cost);

	virtual void add_bidirectional_edge(int source, int destination);

	void DFSStack();
	void DFS();
	void DFSRecursion(int index, std::vector<int> &visited);

	void BFS();
	void BFSQueue(int index, std::vector<int> &visited);
};