package org.example;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Random;
import java.util.Set;

public class RotorRouter {
    Vertice[] vertices;
    Set<Integer> visited = new HashSet<>();
    Random rand = new Random();

    class Vertice {
        int id;
        ArrayList<Integer> next = new ArrayList<>();
        int nextDest = 0;
        Vertice(int id){
            this.id = id;
        }
    }

    public void init(int n){
        vertices = new Vertice[n];
        for (int i = 0; i < n; i++){
            vertices[i] = new Vertice(i);
        }
    }

    public void addEdge(int source, int destination){
        vertices[source].next.add(destination);
        vertices[destination].next.add(source);
    }

    public void setNext(){
        for (int i = 0; i < vertices.length; i++){
            vertices[i].nextDest = rand.nextInt(vertices[i].next.size());
        }
    }

    public int run(int starting){
        setNext();
        int current = starting;
        visited.add(current);
        int time = 0;
        int next;

        while (visited.size() != vertices.length) {
            next = vertices[current].next.get(vertices[current].nextDest);
            vertices[current].nextDest = (vertices[current].nextDest + 1) % vertices[current].next.size();
            current = next;
            visited.add(current);
            time++;
        }
        return time;
    }
}
