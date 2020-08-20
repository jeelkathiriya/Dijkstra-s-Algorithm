#include<iostream>

using namespace std;

#define INF 999

int V, sourceVertices, costValue[100][100];
int space[100];
bool visited[100] = { 0 };
int parent[100];

void init()
{
	for (int i = 0; i < V; i++)
	{
		parent[i] = i;
		space[i] = INF;
	}

	space[sourceVertices] = 0;
}

int nearestVertices()
{
	int minvalue = INF;
	int minnode = 0;

	for (int i = 0; i < V; i++)
	{
		if (!visited[i] && space[i] < minvalue)
		{
			minvalue = space[i];
			minnode = i;
		}
	}

	return minnode;
}

void dijkstraAlgorithm()
{
	for (int i = 0; i < V; i++)
	{
		int nearest = nearestVertices();
		visited[nearest] = true;

		for (int adj = 0; adj < V; adj++)
		{
			if (costValue[nearest][adj] != INF && 
				space[adj] > space[nearest] + costValue[nearest][adj])
			{
				space[adj] = space[nearest] + costValue[nearest][adj];
				parent[adj] = nearest;
			}
		}
	}
}

void print_output()
{
	cout << "Node:\t\t\tCost :\t\t\tPath";

	for (int i = 0; i < V; i++)
	{
		cout << i << "\t\t\t" << space[i] << "\t\t\t" << " ";

		cout << i << " ";

		int parnode = parent[i];

		while (parnode != sourceVertices)
		{
			cout << " <-- " << parnode << " ";
			parnode = parent[parnode];
		}
		cout << endl;
	}
}

int main(void) 
{
	cout << "Enter Number Of Vertices: ";
	cin >> V;
	cout << endl;

	cout << "ENTER THE COST MATRiX BELOW:-";
	cout << endl;
	for (int i = 0; i < V; i++) 
	{
		for (int j = 0; j< V; j++) 
		{
			cin >> costValue[i][j];
		}
	}

	cout << endl;
	cout << "Initialize Start Node: ";
	cin >> sourceVertices;
	cout << endl;

	init();
	dijkstraAlgorithm();
	print_output();
}