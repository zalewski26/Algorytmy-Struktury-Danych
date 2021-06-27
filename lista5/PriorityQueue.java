package org.example;

public class PriorityQueue {
    static class Node {
        int value;
        double priority;
        Node(int value, double priority){
            this.value = value;
            this.priority = priority;
        }
    }
    Node[] heap = new Node[500000];
    int heapsize = 0;

    public void buildHeap(Node[] arr){
        heapsize = arr.length;
        for (int i = 0; i < heapsize; i++){
            heap[i] = arr[i];
        }
        for (int i = (heapsize - 1) / 2; i >= 0; i--){
            heapify(i);
        }
    }

    public void insert(int value, double priority){
        Node newNode = new Node(value, priority);
        heapsize++;
        heap[heapsize - 1] = newNode;
        decreaseKey(heapsize - 1, priority);
    }

    public boolean empty(){
        return heapsize == 0;
    }

    public int top(){
        return heap[0].value;
    }

    public Node pop(){
        if (heapsize < 1)
            return null;
        Node max = heap[0];
        heap[0] = heap[heapsize - 1];
        heapsize--;
        heapify(0);
        return max;
    }

    public void changePriority(int val, double priority){
        for (int i = 0; i < heapsize; i++){
            if (heap[i].value == val)
                decreaseKey(i, priority);
        }
    }

    private void decreaseKey(int pos, double priority){
        if (priority > heap[pos].priority){
            return;
        }
        heap[pos].priority = priority;
        while (pos > 0 && heap[parent(pos)].priority > heap[pos].priority){
            Node temp = heap[pos];
            heap[pos] = heap[parent(pos)];
            heap[parent(pos)] = temp;
            pos = parent(pos);
        }
    }

    private void heapify(int pos){
        int l = left(pos);
        int r = right(pos);
        int smallest = pos;

        if (l < heapsize && heap[l].priority < heap[pos].priority)
            smallest = l;
        if (r < heapsize && heap[r].priority < heap[smallest].priority)
            smallest = r;
        if (smallest != pos){
            Node temp = heap[pos];
            heap[pos] = heap[smallest];
            heap[smallest] = temp;
            heapify(smallest);
        }
    }

    private int left(int pos){
        return (2 * pos) + 1;
    }

    private int right(int pos){
        return (2 * pos) + 2;
    }

    private int parent(int pos){
        return (pos - 1) / 2;
    }

    public void print(){
        for (int i = 0; i < heapsize; i++){
            System.out.println(i + ":  val = " + heap[i].value + "  priority = " + heap[i].priority);
        }
    }
}
