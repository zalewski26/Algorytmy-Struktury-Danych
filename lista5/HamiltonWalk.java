package org.example;

import java.util.ArrayList;
import java.util.LinkedHashSet;
import java.util.Stack;
import java.util.Vector;

public class HamiltonWalk {

    ArrayList<KruskalSpanningTree.Edge> edges = new ArrayList<>();
    KruskalSpanningTree ksp = new KruskalSpanningTree();
    ArrayList<Integer> visited = new ArrayList<>();
    int hops = 0;
    double totalCost = 0;
    int verts;
    Vector<Integer> path = new Vector<>();

    public void init(int n){
        verts = n;
    }

    public void addEdge(int source, int destination, double weight){
        edges.add(new KruskalSpanningTree.Edge(source, destination, weight));
    }

    public void run(){
        ksp.init(verts);
        for (KruskalSpanningTree.Edge e : edges)
            ksp.addEdge(e.source, e.destination, e.weight);
        ksp.run();
        edges.clear();
        edges = ksp.getFinalEdges();

        ArrayList<Integer>[] next = new ArrayList[verts];
        ArrayList<Integer>[] next2 = new ArrayList[verts];
        ArrayList<Double>[] costs = new ArrayList[verts];
        for (int i = 0; i < next.length; i++){
            next[i] = new ArrayList<>();
            next2[i] = new ArrayList<>();
            costs[i] = new ArrayList<>();
        }
        for (int i = 0; i < edges.size(); i++){
            next[edges.get(i).source].add(edges.get(i).destination);
            costs[edges.get(i).source].add(edges.get(i).weight);
            next[edges.get(i).source].add(edges.get(i).destination);
            costs[edges.get(i).source].add(edges.get(i).weight);
            next[edges.get(i).destination].add(edges.get(i).source);
            costs[edges.get(i).destination].add(edges.get(i).weight);
            next[edges.get(i).destination].add(edges.get(i).source);
            costs[edges.get(i).destination].add(edges.get(i).weight);

            next2[edges.get(i).source].add(edges.get(i).destination);
            next2[edges.get(i).destination].add(edges.get(i).source);
        }

        int numOfAdj[] = new int[verts];
        for (int i = 0; i < edges.size(); i++){
            numOfAdj[edges.get(i).source]++;
        }
        int current = 0;
        for (int i = 0; i < verts; i++){
            if (numOfAdj[i] % 2 == 1) {
                current = i;
            }
        }

        Stack<Integer> stack = new Stack<>();
        while (!stack.isEmpty() || next[current].size() != 0) {
            if (next[current].size() == 0) {
                path.add(current);
                current = stack.pop();
            }
            else {
                int nextCurr = next[current].get(0);
                stack.add(current);
                next[current].remove(Integer.valueOf(nextCurr));
                next[nextCurr].remove(Integer.valueOf(current));
                current = nextCurr;
            }
        }

        LinkedHashSet<Integer> hashSet = new LinkedHashSet<Integer>(path);
        path.clear();
        path.addAll(hashSet);

        for (int i = 0; i < path.size() - 1; i++){
            for (int j = 0; j < next2[path.get(i)].size(); j++){
                if (next2[path.get(i)].get(j) == (path.get(i + 1))){
                    totalCost += costs[path.get(i)].get(j);
                }
            }
        }
    }

    public Vector<Integer> getPath(){
        return path;
    }

    public double getTotalCost(){
        return totalCost;
    }

    public int getHops(){
        return path.size() - 1;
    }
}
