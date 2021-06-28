package org.example;

import java.util.ArrayList;

public class KruskalSpanningTree {
    static class Edge{
        int source;
        int destination;
        double weight;
        Edge(int source, int destination, double weight){
            this.source = source;
            this.destination = destination;
            this.weight = weight;
        }
    }
    ArrayList<Edge> edgesList = new ArrayList<>();
    int[] parents;
    int[] ranks;
    ArrayList<Edge> finalEdges = new ArrayList<>();

    public void init(int verts){
        parents = new int[verts];
        ranks = new int[verts];
        for (int i = 0; i < verts; i++) {
            parents[i] = i;
            ranks[i] = 0;
        }
    }

    private int find(int node){
        while (node != parents[node])
            node = parents[node];
        return node;
    }

    private void union(int nodeX, int nodeY){
        int first = find(nodeX);
        int sec = find(nodeY);

        if (ranks[first] > ranks[sec])
            parents[sec] = first;
        else {
            parents[first] = sec;
            if (ranks[first] == ranks[sec])
                ranks[sec]++;
        }
    }

    public void addEdge(int source, int destination, double cost){
        edgesList.add(new Edge(source, destination, cost));
    }

    public void run(){
        PriorityQueue pq = new PriorityQueue();
        PriorityQueue.Node[] arr = new PriorityQueue.Node[edgesList.size()];
        for (int i = 0; i < edgesList.size(); i++){
            arr[i] = new PriorityQueue.Node(i, edgesList.get(i).weight);
        }
        pq.buildHeap(arr);
        while (!pq.empty()){
            PriorityQueue.Node temp = pq.pop();
            if (find(edgesList.get(temp.value).source) != find(edgesList.get(temp.value).destination)){
                finalEdges.add(edgesList.get(temp.value));
                union(edgesList.get(temp.value).source, edgesList.get(temp.value).destination);
            }
        }
    }

    public ArrayList<Edge> getFinalEdges(){
        return finalEdges;
    }
}
