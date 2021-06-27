package org.example;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;

public class DepthFirstSearch {
    ArrayList<Integer>[] next;
    boolean[] visited;
    int time = 0;

    public void init(int n){
        next = new ArrayList[n];
        visited = new boolean[n];
        for (int i = 0; i < n; i++){
            next[i] = new ArrayList<>();
        }
    }

    public void addEdge(int source, int destination){
        next[source].add(destination);
        next[destination].add(source);
    }

    public int run(int starting){
        Arrays.fill(visited, false);
        dfs(starting);
        return time;
    }

    private void dfs(int id){
        time++;
        if (visited[id])
            return;
        visited[id] = true;
        for (int n : next[id]){
            dfs(n);
        }
    }
}
