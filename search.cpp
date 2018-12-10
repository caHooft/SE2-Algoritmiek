// search.cpp
// Compile with: g++ search.cpp -o search
/*
#include "search.h"

using namespace std;

typename std::vector<Vertex>::const_iterator Graph::cbegin(Vertex v) const
{
    currentVertex = v;
    return adjacents[v].cbegin();
}

typename std::vector<Vertex>::const_iterator Graph::cend() const
{
    return adjacents[currentVertex].cend();
}

Graph::GraphMap Graph::adjacents = 
{ 
        { 'S', { 'A', 'B' } },
        { 'A', { 'B', 'D', 'S' } },
        { 'B', { 'S', 'A', 'C' } },
        { 'C', { 'B', 'E' } },
        { 'D', { 'A', 'G' } },
        { 'E', { 'C' } },
        { 'G', { 'D' } }
}; 

Path dfs(const Graph &graph, const Vertex &start, std::function<bool(const Vertex &vertex)> goalTest)
{
    std::stack<Path> q;
    std::set<Vertex> visited;
    Path path;
    
    q.push(path);
    while (!q.empty()) {
        path = q.top();
        q.pop();
        
        Vertex last;
        if (path.size() == 0) {
            last = start;
        } else {
            last = path.back();
        }
        if (goalTest(last)) 
            return path; // path is a vector of Vertices
        
        if (visited.find(last) == visited.end()) {
            visited.insert(last);
            for (auto it = graph.cbegin(last); it != graph.cend(); it++) { // extend path with new Vertex
                Path n = path;
                n.push_back(*it);
                q.push(n);
            }
        }
    }
    return Path(); // return empty path
}

Path bfs(const Graph &graph, const Vertex &start, std::function<bool(const Vertex &vertex)> goalTest)
{
	std::deque<Path> q;
	std::set<Vertex> visited;
	Path path;

	q.push_back(path);
	while (!q.empty()) 
	{
		path = q.front();
		q.pop_front();

		Vertex last;
		if (path.size() == 0) 
		{
			last = start;
		}
		else 
		{
			last = path.back();
		}
		if (goalTest(last))
		{
			return path; // path is a vector of Vertices
		}			

		if (visited.find(last) == visited.end()) 
		{
			visited.insert(last);
			for (auto it = graph.cbegin(last); it != graph.cend(); it++) 
			{ // extend path with new Vertex
				Path n = path;
				n.push_back(*it);
				q.push_back(n);
			}
		}
	}
	return Path(); // return empty path
}

int main() 
{
    Graph graph;

    Vertex start = 'S';
    Vertex goal = 'G';

//    Path path = dfs(graph, start, [&](Vertex v) { return (v == goal); });
    Path path = bfs(graph, start, [&](Vertex v) { return (v == goal); });

    std::cout << start << std::endl;
    for (auto it = path.cbegin(); it != path.cend(); it++)
    {
        std::cout << *it << std::endl;
    }

    return 0;
}
*/
