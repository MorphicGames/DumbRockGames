#pragma once
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>

template<typename s>

class Graph
{
	template<typename s>
	class sceneGraphVertex
	{
		friend Graph;

	public:
		sceneGraphVertex(s node) : m_node(node)
		{ }

		s GetNode()
		{
			return m_node;
		}

	private:
		s m_node;
	};

	class sceneEdgeInfo
	{
		friend Graph;

	public:
		EdgeInfo() : m_v1Index(0), m_v2Index(0), m_weight(0)
		{ }

		bool operator<(const EdgeInfo &e2) const
		{
			return (m_weight < e2.m_weight);
		}

		bool operator==(const EdgeInfo &e2) const
		{
			return (m_v2Index == e2.m_v2Index);
		}

		int m_v1Index, m_v2Index;
		int m_weight;
	};

public:
	Graph(int numVerts) : m_maxVerts(numVerts), m_adjMatrix(NULL)
	{
		assert(numVerts > 0);

		m_vertices.reserve(m_maxVerts);

		m_adjMatrix = new int*[m_maxVerts];
		assert(m_adjMatrix != NULL);

		m_vertVisits = new char[m_maxVerts];
		assert(m_vertVisits != NULL);

		memset(m_vertVisits, 0, m_maxVerts);

		for (int i = 0; i < m_maxVerts; i++)
		{
			m_adjMatrix[i] = new int[m_maxVerts];
			assert(m_adjMatrix[i] != NULL);

			memset(m_adjMatrix[i], 0, m_maxVerts);
		}
	}

	~Graph()
	{
		if (m_adjMatrix != NULL)
		{
			for (int i = 0; i < m_maxVerts; i++)
			{
				if (m_adjMatrix[i] != NULL)
				{
					delete[] m_adjMatrix[i];
					m_adjMatrix[i] = NULL;
				}
			}

			delete[] m_adjMatrix;
			m_adjMatrix = NULL;
		}

		if (m_vertVisits != NULL)
		{
			delete[] m_vertVisits;
			m_vertVisits = NULL;
		}
	}


	bool push(s node)
	{
		if ((int)m_vertices.size() >= m_maxVerts)
			return false;

		m_vertices.push_back(GraphVertex<T>(node));
		return true;
	}

	void attachEdge(int index1, int index2, int weight)
	{
		assert(m_adjMatrix != NULL);

		m_adjMatrix[index1][index2] = weight;
		m_adjMatrix[index2][index1] = weight;
	}

	void attachDirectedEdge(int index1, int index2, int weight)
	{
		assert(m_adjMatrix != NULL);

		m_adjMatrix[index1][index2] = weight;
	}

	void DisplayMST(string &output)
	{
		//Assert whether graph is NULL
		assert(m_adjMatrix != NULL);

		//Assert whether vertices visited are NULL
		assert(m_vertVisits != NULL);

		//Start at first vertex
		int currentVert = 0;
		//Set total visited nodes to 0
		int totalChecked = 0;
		//Set size to size of the vertex vector
		int size = (int)m_vertices.size();

		//Create a vector to contain edge info
		vector<EdgeInfo> vList;

		//Loop while the number of checked vertices does not equal the total number of vertices
		while (totalChecked < size - 1)
		{
			//Set current vertex to visited (true)
			m_vertVisits[currentVert] = 1;
			//Add to total number of visited vertices
			totalChecked++;

			//Loop through and add all unchecked adjacent vertices and their weights to a priority queue
			for (int i = 0; i < size; i++)
			{
				//If counter is equal to current vertex goto next iteration
				//If vertex visited is true goto next iteration
				//If adjacency matrix does not have an edge at current vertex goto next iteration
				if (i == currentVert || m_vertVisits[i] == 1 || m_adjMatrix[currentVert][i] == 0)
					continue;

				//Create an edgeinfo
				EdgeInfo edge;
				//Set first vertex to start point of edge
				edge.m_v1Index = currentVert;
				//Set second vertex to end point of edge
				edge.m_v2Index = i;
				//Set weight from the current vertex stored in adjacency matrix
				edge.m_weight = m_adjMatrix[currentVert][i];

				//Create vector iterator to search for the edge from the begining to end of the vector containing edgeinfo
				vector<EdgeInfo>::iterator it = find(vList.begin(), vList.end(), edge);

				//If end of the vector push edge
				if (it == vList.end())
					vList.push_back(edge);
				//If weight found within the iterator is greater than the edge weight
				//Reassign new weight to iterator edge
				else
				{
					if (edge.m_weight <= (*it).m_weight)
					{
						(*it).m_v1Index = edge.m_v1Index;
						(*it).m_v2Index = edge.m_v2Index;
						(*it).m_weight = edge.m_weight;
					}
				}
			}

			//If vector of edgeinfo is empty print error
			if (vList.empty() == true)
			{
				output = "Error: Graph is not connected.";
				return;
			}

			// Orders from greatest to least
			// Since we have to sort anyhow lets put the
			// min at the end so pop_back() is fast.
			sort(vList.rbegin(), vList.rend());

			int endIndex = (int)vList.size() - 1;
			int v1 = vList[endIndex].m_v1Index;
			currentVert = vList[endIndex].m_v2Index;

			//Output vertices
			output += m_vertices[v1].GetNode();
			output += ":";
			output += m_vertices[currentVert].GetNode();
			output += " ";

			//Remove minimum, which was placed at the back.
			vList.pop_back();
		}

		//Set memory for vertices visited
		memset(m_vertVisits, 0, m_maxVerts);
	}

private:
	vector<sceneGraphVertex<s> > m_vertices;
	int m_maxVerts;

	int **m_adjMatrix;
	char *m_vertVisits;
};

#endif