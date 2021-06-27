package org.example;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Random;
import java.util.Set;

public class LazyRandomWalk {
    ArrayList<Integer>[] next;
    Set<Integer> visited = new HashSet<>();
    Random rand = new Random();

    public void init(int n){
        next = new ArrayList[n];
        for (int i = 0; i < n; i++){
            next[i] = new ArrayList<>();
        }
    }

    public void addEdge(int source, int destination){
        next[source].add(destination);
        next[destination].add(source);
    }

    public int run(int starting){
        int current = starting;
        visited.add(current);
        int time = 0;
        int nextHop;

        while (visited.size() != next.length) {
            if (rand.nextInt(2) == 0){
                nextHop = next[current].get(rand.nextInt(next[current].size()));
                current = nextHop;
                visited.add(current);
            }
            time++;
        }
        return time;
    }
}
