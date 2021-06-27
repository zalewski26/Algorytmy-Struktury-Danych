package org.example;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Random;
import java.util.Set;

public class SimpleRandomWalk {
    Random rand = new Random();
    double[][] costs;
    Set<Integer> visited = new HashSet<>();
    ArrayList<Integer> route = new ArrayList<>();

    int hops = 0;
    double totalCost = 0;
    double totalMemory = 0;

    public void init(int n){
        costs = new double[n][n];
        //for (int i = 0; i < n; i++){
        //    costs[i] = new double[n];
        //}
    }

    public void addEdge(int source, int destination, double weight){
        costs[source][destination] = weight;
        costs[destination][source] = weight;
    }

    public void run(){
        int current = 0;
        visited.add(current);
        route.add(current);

        while (visited.size() != costs.length){
            int next = rand.nextInt(costs.length - 1);
            if (next == current)
                next = costs.length - 1;
            totalCost += costs[current][next];
            visited.add(next);
            route.add(next);
            hops++;
            current = next;
        }
    }

    public int getHops() {
        return hops;
    }

    public double getTotalCost() {
        return totalCost;
    }

    public ArrayList<Integer> getRoute(){
        return route;
    }
}
