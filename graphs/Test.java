package org.example;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;
import java.util.Scanner;

public class Test {
    static Random rand = new Random();

    public static void main(String[] args){
        Test test = new Test();
        try {
            //test.priorityQueueTest();
            //test.dijkstraTest();
            //test.kruskal();
            //test.prim();
            test.traversing();
        } catch (IOException ex){
            ex.printStackTrace();
        }
    }

    private void priorityQueueTest() throws IOException {
        FileWriter fw = new FileWriter("/home/zalewski26/Desktop/studia/Algorytmy i struktury danych/laby/5v2/priorityQueueTest.txt");
        for (int i = 100; i < 10000; i+= 100){
            for (int k = 0; k < 100; k++){
                PriorityQueue pq = new PriorityQueue();
                PriorityQueue.Node[] arr = new PriorityQueue.Node[i];
                for (int j = 0; j < i; j++){
                    arr[j] = new PriorityQueue.Node(rand.nextInt(i / 2), rand.nextDouble());
                }

                pq.buildHeap(arr);
                pq.insert(i / 2, rand.nextDouble());
                long start = System.nanoTime();
                pq.changePriority(i / 2, rand.nextDouble());
                long end = System.nanoTime();
                pq.pop();

                fw.write(i + " " + (end - start) / 1000000f + "\n");
            }
        }
        fw.close();
    }

    private void dijkstraTest() throws IOException {
        FileWriter fw = new FileWriter("/home/zalewski26/Desktop/studia/Algorytmy i struktury danych/laby/5v2/dijkstraTest.txt");
        Scanner scanner = null;
        int opt = 0;
        for (int i = 3; i < 4; i+= 1){
            for (int k = 0; k < 5; k++){
                switch (i){
                    case 0:
                        scanner = new Scanner(new File("/home/zalewski26/Desktop/studia/Algorytmy i struktury danych/laby/5/g8.txt"));
                        opt = 8;
                        break;
                    case 1:
                        scanner = new Scanner(new File("/home/zalewski26/Desktop/studia/Algorytmy i struktury danych/laby/5/g250.txt"));
                        opt = 250;
                        break;
                    case 2:
                        scanner = new Scanner(new File("/home/zalewski26/Desktop/studia/Algorytmy i struktury danych/laby/5/g1000.txt"));
                        opt = 1000;
                        break;
                    case 3:
                        scanner = new Scanner(new File("/home/zalewski26/Desktop/studia/Algorytmy i struktury danych/laby/5/g10000.txt"));
                        opt = 10000;
                        break;
                }
                DijkstraShortestPath dsp = new DijkstraShortestPath();

                dsp.init(scanner.nextInt());
                int counter = scanner.nextInt();
                for (int j = 0; j < counter; j++){
                    dsp.addEdge(scanner.nextInt(), scanner.nextInt(), scanner.nextDouble());
                }
                dsp.initStartingVert(0);

                long start = System.nanoTime();
                dsp.run();
                long end = System.nanoTime();

                fw.write(opt + " " + (end - start) / 1000000f + "\n");
            }
        }
        fw.close();
    }

    private void kruskal() throws IOException {
        FileWriter fw = new FileWriter("/home/zalewski26/Desktop/studia/Algorytmy i struktury danych/laby/5v2/kruskalTest.txt");
        Scanner scanner = null;
        int opt = 0;
        for (int i = 3; i < 4; i+= 1){
            for (int k = 0; k < 5; k++){
                switch (i){
                    case 0:
                        scanner = new Scanner(new File("/home/zalewski26/Desktop/studia/Algorytmy i struktury danych/laby/5/g8.txt"));
                        opt = 8;
                        break;
                    case 1:
                        scanner = new Scanner(new File("/home/zalewski26/Desktop/studia/Algorytmy i struktury danych/laby/5/g250.txt"));
                        opt = 250;
                        break;
                    case 2:
                        scanner = new Scanner(new File("/home/zalewski26/Desktop/studia/Algorytmy i struktury danych/laby/5/g1000.txt"));
                        opt = 1000;
                        break;
                    case 3:
                        scanner = new Scanner(new File("/home/zalewski26/Desktop/studia/Algorytmy i struktury danych/laby/5/g10000.txt"));
                        opt = 10000;
                        break;
                }
                KruskalSpanningTree kst = new KruskalSpanningTree();

                kst.init(scanner.nextInt());
                int counter = scanner.nextInt();
                for (int j = 0; j < counter; j++){
                    kst.addEdge(scanner.nextInt(), scanner.nextInt(), scanner.nextDouble());
                }

                long start = System.nanoTime();
                kst.run();
                long end = System.nanoTime();

                fw.write(opt + " " + (end - start) / 1000000f + "\n");
            }
        }
        fw.close();
    }

    private void prim() throws IOException {
        FileWriter fw = new FileWriter("/home/zalewski26/Desktop/studia/Algorytmy i struktury danych/laby/5v2/primTest.txt");
        Scanner scanner = null;
        int opt = 0;
        for (int i = 0; i < 4; i+= 1){
            for (int k = 0; k < 10; k++){
                switch (i){
                    case 0:
                        scanner = new Scanner(new File("/home/zalewski26/Desktop/studia/Algorytmy i struktury danych/laby/5/g8.txt"));
                        opt = 8;
                        break;
                    case 1:
                        scanner = new Scanner(new File("/home/zalewski26/Desktop/studia/Algorytmy i struktury danych/laby/5/g250.txt"));
                        opt = 250;
                        break;
                    case 2:
                        scanner = new Scanner(new File("/home/zalewski26/Desktop/studia/Algorytmy i struktury danych/laby/5/g1000.txt"));
                        opt = 1000;
                        break;
                    case 3:
                        scanner = new Scanner(new File("/home/zalewski26/Desktop/studia/Algorytmy i struktury danych/laby/5/g10000.txt"));
                        opt = 10000;
                        break;
                }
                PrimSpanningTree pst = new PrimSpanningTree();

                pst.init(scanner.nextInt());
                int counter = scanner.nextInt();
                for (int j = 0; j < counter; j++){
                    pst.addEdge(scanner.nextInt(), scanner.nextInt(), scanner.nextDouble());
                }

                long start = System.nanoTime();
                pst.run();
                long end = System.nanoTime();

                fw.write(opt + " " + (end - start) / 1000000f + "\n");
            }
        }
        fw.close();
    }

    private void traversing() throws IOException{
        //FileWriter fw1 = new FileWriter("/home/zalewski26/Desktop/studia/Algorytmy i struktury danych/laby/5v2/srwTest.txt");
        FileWriter fw2 = new FileWriter("/home/zalewski26/Desktop/studia/Algorytmy i struktury danych/laby/5v2/gwTest.txt");
        FileWriter fw3 = new FileWriter("/home/zalewski26/Desktop/studia/Algorytmy i struktury danych/laby/5v2/hwTest.txt");
        SimpleRandomWalk srw;
        GreedyWalk gw;
        HamiltonWalk hw;
        for (int i = 100; i <= 1000; i += 100){
            for (int l = 0; l < 5; l++){
                //srw = new SimpleRandomWalk();
                gw = new GreedyWalk();
                hw = new HamiltonWalk();
                //srw.init(i);
                gw.init(i);
                hw.init(i);
                for (int j = 0; j < i; j++){
                    for (int k = j + 1; k < i; k++){
                        //srw.addEdge(j, k, i / 2 + 1 + rand.nextInt(i / 2));
                        gw.addEdge(j, k, i / 2 + 1 + rand.nextInt(i / 2));
                        hw.addEdge(j, k, i / 2 + 1 + rand.nextInt(i / 2));
                    }
                }

                long one = System.nanoTime();
                //srw.run();
                long two = System.nanoTime();
                gw.run();
                long three = System.nanoTime();
                hw.run();
                long four = System.nanoTime();

                //fw1.write( i+ " " + srw.getHops() + " " + srw.getTotalCost() + " " + (two - one) / 1000000f + "\n");
                fw2.write( i+ " " + gw.getHops() + " " + gw.getTotalCost() + " " + (three - two) / 1000000f + "\n");
                fw3.write( i+ " " + hw.getHops() + " " + hw.getTotalCost() + " " + (four - three) / 1000000f + "\n");
            }
        }
        //fw1.close();
        fw2.close();
        fw3.close();
    }


}
