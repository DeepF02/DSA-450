or<int> adjList[5];
    adjList[1].push_back(0);
    adjList[0].push_back(2);
    adjList[2].push_back(1);
    adjList[0].push_back(3);
    adjList[3].push_back(4);

    Graph.isCyclic(5, adjList)? cout << "Graph contains cycle\n":cout << "Graph doesn't contain cycle\n";