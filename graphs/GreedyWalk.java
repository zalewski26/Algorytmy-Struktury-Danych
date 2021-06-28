package org.example;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;

public class GreedyWalk {
    class Edge{
        int source;
        int destination;
        double weight;
        Edge(int source, int destination, double weight){
            this.source = source;
            this.destination = destination;
            this.weight = weight;
        }
    }
    ArrayList<Edge> edges = new ArrayList<>();
    Set<Integer> visited = new HashSet<>();
    ArrayList<Integer> route = new ArrayList<>();
    int hops = 0;
    double totalCost = 0;
    int verts;

    public void init(int n){
        verts = n;
    }

    public void addEdge(int source, int destination, double cost){
        edges.add(new Edge(source, destination, cost));
    }

    public void run(){
        PriorityQueue[] arr = new PriorityQueue[verts];
        for (int i = 0; i < verts; i++){
            arr[i] = new PriorityQueue();
        }
        for (int i = 0; i < edges.size(); i++){
            arr[edges.get(i).source].insert(i, edges.get(i).weight);
            arr[edges.get(i).destination].insert(i, edges.get(i).weight);
        }

        int current = 0;

        visited.add(current);
        route.add(current);
        while (visited.size() != verts){
            int id = arr[current].pop().value;
            int next = edges.get(id).destination;
            if (next == current)
                next = edges.get(id).source;
            if (!visited.contains(next)){
                hops++;
                current = next;
                totalCost += edges.get(id).weight;
                visited.add(next);
                route.add(next);
            }
        }

    }

    public int getHops(){
        return hops;
    }

    public double getTotalCost(){
        return totalCost;
    }

    public ArrayList<Integer> getRoute(){
        return route;
    }
}
