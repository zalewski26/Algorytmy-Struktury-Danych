package org.example;

import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;

public class TestGraphTraverse {
    static Random rand = new Random();
    public static void main(String[] args){
        try{
            //cliqueTest();
            //pathTestMiddle();
            //pathTestEnd();
            //treeTest();
            lollipopTest();
        } catch (IOException ex){
            ex.printStackTrace();
        }
    }

    private static void cliqueTest() throws IOException {
        FileWriter fw1 = new FileWriter("/home/zalewski26/Desktop/studia/Algorytmy i struktury danych/laby/5v2/cliqueLRW.txt");
        FileWriter fw2 = new FileWriter("/home/zalewski26/Desktop/studia/Algorytmy i struktury danych/laby/5v2/cliqueDFS.txt");
        FileWriter fw3 = new FileWriter("/home/zalewski26/Desktop/studia/Algorytmy i struktury danych/laby/5v2/cliqueRR.txt");
        LazyRandomWalk lrw;
        DepthFirstSearch dfs;
        RotorRouter rr;
        for (int i = 100; i <= 2000; i += 100){
            for (int l = 0; l < 10; l++){
                lrw = new LazyRandomWalk();
                dfs = new DepthFirstSearch();
                rr = new RotorRouter();
                lrw.init(i);
                dfs.init(i);
                rr.init(i);
                for (int j = 0; j < i; j++){
                    for (int k = j + 1; k < i; k++){
                        lrw.addEdge(j, k);
                        dfs.addEdge(j, k);
                        rr.addEdge(j, k);
                    }
                }
                fw1.write(i + " " + lrw.run(rand.nextInt(i)) + "\n");
                fw2.write(i + " " + dfs.run(rand.nextInt(i))+ "\n");
                fw3.write(i + " " + rr.run(rand.nextInt(i))+ "\n");
            }
        }
        fw1.close();
        fw2.close();
        fw3.close();
    }

    private static void pathTestMiddle() throws IOException{
        FileWriter fw1 = new FileWriter("/home/zalewski26/Desktop/studia/Algorytmy i struktury danych/laby/5v2/pathMidLRW.txt");
        FileWriter fw2 = new FileWriter("/home/zalewski26/Desktop/studia/Algorytmy i struktury danych/laby/5v2/pathMidDFS.txt");
        FileWriter fw3 = new FileWriter("/home/zalewski26/Desktop/studia/Algorytmy i struktury danych/laby/5v2/pathMidRR.txt");
        LazyRandomWalk lrw;
        DepthFirstSearch dfs;
        RotorRouter rr;
        for (int i = 100; i <= 2000; i += 100){
            for (int k = 0; k < 10; k++){
                lrw = new LazyRandomWalk();
                dfs = new DepthFirstSearch();
                rr = new RotorRouter();
                lrw.init(i);
                dfs.init(i);
                rr.init(i);
                for (int j = 0; j < i - 1; j++){
                    lrw.addEdge(j, j + 1);
                    dfs.addEdge(j, j + 1);
                    rr.addEdge(j, j + 1);
                }
                fw1.write(i + " " + lrw.run((i / 2))+ "\n");
                fw2.write(i + " " + dfs.run((i / 2))+ "\n");
                fw3.write(i + " " + rr.run((i / 2))+ "\n");
            }
        }
        fw1.close();
        fw2.close();
        fw3.close();
    }

    private static void pathTestEnd() throws IOException{
        FileWriter fw1 = new FileWriter("/home/zalewski26/Desktop/studia/Algorytmy i struktury danych/laby/5v2/pathEndLRW.txt");
        FileWriter fw2 = new FileWriter("/home/zalewski26/Desktop/studia/Algorytmy i struktury danych/laby/5v2/pathEndDFS.txt");
        FileWriter fw3 = new FileWriter("/home/zalewski26/Desktop/studia/Algorytmy i struktury danych/laby/5v2/pathEndRR.txt");
        LazyRandomWalk lrw;
        DepthFirstSearch dfs;
        RotorRouter rr;
        for (int i = 100; i <= 2000; i += 100){
            for (int k = 0; k < 10; k++){
                lrw = new LazyRandomWalk();
                dfs = new DepthFirstSearch();
                rr = new RotorRouter();
                lrw.init(i);
                dfs.init(i);
                rr.init(i);
                for (int j = 0; j < i - 1; j++){
                    lrw.addEdge(j, j + 1);
                    dfs.addEdge(j, j + 1);
                    rr.addEdge(j, j + 1);
                }
                fw1.write(i + " " + lrw.run((0))+ "\n");
                fw2.write(i + " " + dfs.run((0))+ "\n");
                fw3.write(i + " " + rr.run((0))+ "\n");
            }
        }
        fw1.close();
        fw2.close();
        fw3.close();
    }

    private static void treeTest() throws IOException{
        FileWriter fw1 = new FileWriter("/home/zalewski26/Desktop/studia/Algorytmy i struktury danych/laby/5v2/treeLRW.txt");
        FileWriter fw2 = new FileWriter("/home/zalewski26/Desktop/studia/Algorytmy i struktury danych/laby/5v2/treeDFS.txt");
        FileWriter fw3 = new FileWriter("/home/zalewski26/Desktop/studia/Algorytmy i struktury danych/laby/5v2/treeRR.txt");
        LazyRandomWalk lrw;
        DepthFirstSearch dfs;
        RotorRouter rr;
        for (int i = 100; i <= 2000; i += 100){
            for (int k = 0; k < 10; k++){
                lrw = new LazyRandomWalk();
                dfs = new DepthFirstSearch();
                rr = new RotorRouter();
                lrw.init(i);
                dfs.init(i);
                rr.init(i);
                for (int j = 0; j < i; j++){
                    if (j * 2 + 1 < i){
                        lrw.addEdge(j, j * 2 + 1);
                        dfs.addEdge(j, j * 2 + 1);
                        rr.addEdge(j, j * 2 + 1);
                    }
                    if (j * 2 + 2 < i){
                        lrw.addEdge(j, j * 2 + 2);
                        dfs.addEdge(j, j * 2 + 2);
                        rr.addEdge(j, j * 2 + 2);
                    }
                }
                fw1.write(i + " " + lrw.run((0))+ "\n");
                fw2.write(i + " " + dfs.run((0))+ "\n");
                fw3.write(i + " " + rr.run((0))+ "\n");
            }
        }
        fw1.close();
        fw2.close();
        fw3.close();
    }

    private static void lollipopTest() throws IOException{
        FileWriter fw1 = new FileWriter("/home/zalewski26/Desktop/studia/Algorytmy i struktury danych/laby/5v2/lollipopLRW.txt");
        FileWriter fw2 = new FileWriter("/home/zalewski26/Desktop/studia/Algorytmy i struktury danych/laby/5v2/lollipopDFS.txt");
        FileWriter fw3 = new FileWriter("/home/zalewski26/Desktop/studia/Algorytmy i struktury danych/laby/5v2/lollipopRR.txt");
        LazyRandomWalk lrw;
        DepthFirstSearch dfs;
        RotorRouter rr;
        for (int i = 100; i <= 2000; i += 100){
            for (int l = 0; l < 1; l++){
                lrw = new LazyRandomWalk();
                dfs = new DepthFirstSearch();
                rr = new RotorRouter();
                lrw.init(i);
                dfs.init(i);
                rr.init(i);
                int cliqueSize = 2 * (i / 3);

                for (int j = 0; j < cliqueSize; j++){
                    for (int k = j + 1; k < cliqueSize; k++){
                        lrw.addEdge(j, k);
                        dfs.addEdge(j, k);
                        rr.addEdge(j, k);
                    }
                }
                for (int j = cliqueSize - 1; j < i - 1; j++){
                    lrw.addEdge(j, j + 1);
                    dfs.addEdge(j, j + 1);
                    rr.addEdge(j, j + 1);
                }
                fw1.write(i + " " + lrw.run((rand.nextInt(cliqueSize)))+ "\n");
                fw2.write(i + " " + dfs.run((rand.nextInt(cliqueSize)))+ "\n");
                fw3.write(i + " " + rr.run((rand.nextInt(cliqueSize)))+ "\n");
            }
        }
        fw1.close();
        fw2.close();
        fw3.close();
    }
}
