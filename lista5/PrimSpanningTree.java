package org.example;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;

public class PrimSpanningTree {
    PriorityQueue.Node[] vertices;
    int[] prev;
    double[] dist;
    ArrayList<Integer>[] adj;
    ArrayList<Double>[] costs;
    ArrayList<PriorityQueue.Node> finalNodes = new ArrayList<>();
    ArrayList<Integer> finalPrevs = new ArrayList<>();
    Set<Integer> done = new HashSet<>();

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
        adj[destination].add(source);
        costs[destination].add(cost);
    }

    public void run(){
        vertices[0].priority = 0;
        PriorityQueue pq = new PriorityQueue();
        pq.buildHeap(vertices);
        while (!pq.empty()){
            PriorityQueue.Node temp = pq.pop();
            dist[temp.value] = temp.priority;
            for (int i = 0; i < adj[temp.value].size(); i++){
                if (!done.contains(adj[temp.value].get(i)) && (costs[temp.value].get(i) < dist[adj[temp.value].get(i)])){
                    dist[adj[temp.value].get(i)] = costs[temp.value].get(i);
                    prev[adj[temp.value].get(i)] = temp.value;
                    pq.changePriority(adj[temp.value].get(i), costs[temp.value].get(i));
                }
            }
            finalNodes.add(temp);
            done.add(temp.value);
            finalPrevs.add(prev[temp.value]);
        }
    }

    public ArrayList<PriorityQueue.Node> getFinalNodes() {
        return finalNodes;
    }

    public ArrayList<Integer> getPrev(){
        return finalPrevs;
    }
}
