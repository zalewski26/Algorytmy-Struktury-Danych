package org.example;

import java.util.ArrayList;

public class DijkstraShortestPath {
    PriorityQueue.Node[] vertices;
    int[] prev;
    double[] dist;
    ArrayList<Integer>[] adj;
    ArrayList<Double>[] costs;

    public void init(int n){
        vertices = new PriorityQueue.Node[n];
        prev = new int[n];
        dist = new double[n];
        adj = new ArrayList[n];
        costs = new ArrayList[n];

        for (int i = 0; i < n; i++){
            dist[i] = Double.MAX_VALUE;
            vertices[i] = new PriorityQueue.Node(i, dist[i]);
            prev[i] = i;
            adj[i] = new ArrayList<>();
            costs[i] = new ArrayList<>();
        }
    }

    public void addEdge(int source, int destination, double cost){
        adj[source].add(destination);
        costs[source].add(cost);
    }

    public void initStartingVert(int pos){
        vertices[pos].priority = 0;
    }

    public void run(){
        PriorityQueue pq = new PriorityQueue();
        pq.buildHeap(vertices);
        while (!pq.empty()){
            PriorityQueue.Node temp = pq.pop();
            dist[temp.value] = temp.priority;
            for (int i = 0; i < adj[temp.value].size(); i++){
                if (dist[temp.value] + costs[temp.value].get(i) < dist[adj[temp.value].get(i)]){
                    dist[adj[temp.value].get(i)] = dist[temp.value] + costs[temp.value].get(i);
                    prev[adj[temp.value].get(i)] = temp.value;
                    pq.changePriority(adj[temp.value].get(i), dist[temp.value] + costs[temp.value].get(i));
                }
            }
        }
    }

    public double[] getDist(){
        return dist;
    }

    public int[] getPrev(){
        return prev;
    }
}
