# Project Overview

This repository is a learning project aimed at building a **Data Structures and Algorithms** using **C++**. My goal is to really learn more about commonly used DSA concepts and test them on large amounts of data.

## Currently Built Algorithms

- **SegmentTrees**
	A segment tree implementation designed to efficiently perform range queries and updates. It is built using a statically allocated array, with the size calculated based on the input. Can do range min, max, and sum operations

- **Khan's Algorithm**
	An implementation of Kahn's Algorithm for topological sorting of Directed Acyclic Graphs (DAGs). It uses in-degree tracking and a queue to process nodes in linear order. Efficiently detects cycles and produces a valid topological ordering if one exists.

- **QuickPick Algorithm**
	An efficient divide-and-conquer algorithm for finding the \(k\)-th smallest element in an unsorted array in \(O(n)\) average time. It operates by selecting a pivot using the Median of Medians algorithm, partitioning the array aroundthe pivot, and recursively searching in the relevant partition.

- **Bellman-Ford**
	A Single Source SHortest Path Algorithm that work on a graph with positive and negative weights. Works by utilizing the intuition that we can find the shortest path in at most number of nodes - 1 hops. Essentially a question of given a constraint of <= i hops, what is the minimum path we can get. Gauranteed to be solved in n - 1 hops unless the graph has a negative weight cycle.