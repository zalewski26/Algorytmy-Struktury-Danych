package org.example;

import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;

public class Test {
    public static void main(String[] args){
        firstTest();
    }

    private static void firstTest(){
        try {
            FileWriter insert = new FileWriter("/home/zalewski26/Desktop/tests/insert");
            FileWriter oneInsert = new FileWriter("/home/zalewski26/Desktop/tests/oneInsert");
            FileWriter oneDelete = new FileWriter("/home/zalewski26/Desktop/tests/oneDelete");
            FileWriter min = new FileWriter("/home/zalewski26/Desktop/tests/min");
            FileWriter find = new FileWriter("/home/zalewski26/Desktop/tests/find");
            FileWriter successor = new FileWriter("/home/zalewski26/Desktop/tests/successor");
            AbstractBinaryTree bst;
            AbstractBinaryTree rbt;
            AbstractBinaryTree splay;
            long start;
            long finish;
            String[] arr;

            for (int i = 100; i <= 10000; i += 100) {
                for (int k = 0; k < 100; k++){
                    arr = new String[i];
                    for (int j = 0; j < i; j++){
                        arr[j] = getRandomString();
                    }
                    bst = new BSTree();
                    rbt = new RBTree();
                    splay = new SplayTree();

                    start = System.nanoTime();
                    for (int j = 0; j < i; j++) {
                        bst.insert(arr[j]);
                    }
                    finish = System.nanoTime();
                    insert.write("B " + i + " " + (finish - start) + "\n");
                    start = System.nanoTime();
                    bst.insert(arr[i / 2]);
                    finish = System.nanoTime();
                    oneInsert.write("B " + i + " " + (finish - start) + "\n");
                    start = System.nanoTime();
                    bst.min();
                    finish = System.nanoTime();
                    min.write("B " + i + " " + (finish - start) + "\n");
                    start = System.nanoTime();
                    bst.find(arr[i / 2]);
                    finish = System.nanoTime();
                    find.write("B " + i + " " + (finish - start) + "\n");
                    start = System.nanoTime();
                    bst.successor(arr[i / 2]);
                    finish = System.nanoTime();
                    successor.write("B " + i + " " + (finish - start) + "\n");
                    start = System.nanoTime();
                    bst.delete(arr[i / 2]);
                    finish = System.nanoTime();
                    oneDelete.write("B " + i + " " + (finish - start) + "\n");

                    start = System.nanoTime();
                    for (int j = 0; j < i; j++) {
                        rbt.insert(arr[j]);
                    }
                    finish = System.nanoTime();
                    insert.write("R " + i + " " + (finish - start) + "\n");
                    start = System.nanoTime();
                    rbt.insert(arr[i / 2]);
                    finish = System.nanoTime();
                    oneInsert.write("R " + i + " " + (finish - start) + "\n");
                    start = System.nanoTime();
                    rbt.min();
                    finish = System.nanoTime();
                    min.write("R " + i + " " + (finish - start) + "\n");
                    start = System.nanoTime();
                    rbt.find(arr[i / 2]);
                    finish = System.nanoTime();
                    find.write("R " + i + " " + (finish - start) + "\n");
                    start = System.nanoTime();
                    rbt.successor(arr[i / 2]);
                    finish = System.nanoTime();
                    successor.write("R " + i + " " + (finish - start) + "\n");
                    start = System.nanoTime();
                    rbt.delete(arr[i / 2]);
                    finish = System.nanoTime();
                    oneDelete.write("R " + i + " " + (finish - start) + "\n");

                    start = System.nanoTime();
                    for (int j = 0; j < i; j++) {
                        splay.insert(arr[j]);
                    }
                    finish = System.nanoTime();
                    insert.write("S " + i + " " + (finish - start) + "\n");
                    start = System.nanoTime();
                    splay.insert(arr[i / 2]);
                    finish = System.nanoTime();
                    oneInsert.write("S " + i + " " + (finish - start) + "\n");
                    start = System.nanoTime();
                    splay.min();
                    finish = System.nanoTime();
                    min.write("S " + i + " " + (finish - start) + "\n");
                    start = System.nanoTime();
                    splay.find(arr[i / 2]);
                    finish = System.nanoTime();
                    find.write("S " + i + " " + (finish - start) + "\n");
                    start = System.nanoTime();
                    splay.successor(arr[i / 2]);
                    finish = System.nanoTime();
                    successor.write("S " + i + " " + (finish - start) + "\n");
                    start = System.nanoTime();
                    splay.delete(arr[i / 2]);
                    finish = System.nanoTime();
                    oneDelete.write("S " + i + " " + (finish - start) + "\n");
                }
            }

            insert.close();
            oneInsert.close();
            oneDelete.close();
            min.close();
            find.close();
            successor.close();
        } catch (IOException ex){
            ex.printStackTrace();
        }
    }

    private static String getRandomString() {
        String ALLOWED_CHARACTERS = "qwertyuiopasdfghjklzxcvbnm";
        Random random = new Random();
        int sizeOfRandomString = random.nextInt(15) + 1;
        StringBuilder sb = new StringBuilder(sizeOfRandomString);
        for (int i = 0; i < sizeOfRandomString; i++){
            sb.append(ALLOWED_CHARACTERS.toCharArray()[(random.nextInt(ALLOWED_CHARACTERS.length()))]);
        }
        return sb.toString();
    }
}
