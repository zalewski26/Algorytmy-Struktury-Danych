package org.example;

import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class App
{
    private static AbstractBinaryTree tree;

    public static void main(String[] args ){
        long start = System.currentTimeMillis();
        try{
            Scanner scanner = new Scanner(new File("input.txt"));
            String cmd = scanner.next();
            if (cmd.equalsIgnoreCase("bst")){
                tree = new BSTree();
                System.out.println("BST");
            } else if (cmd.equalsIgnoreCase("rbt")){
                tree = new RBTree();
                System.out.println("RBT");
            } else if (cmd.equalsIgnoreCase("splay")){
                tree = new SplayTree();
                System.out.println("SPLAY");
            }
            int counter = Integer.parseInt(scanner.next());
            for (int i = 0; i < counter; i++){
                cmd = scanner.next();
                if (cmd.equals("insert")){
                    tree.insert(scanner.next());
                } else if (cmd.equals("load")) {
                    tree.load(new File(scanner.next()));
                } else if (cmd.equals("delete")) {
                    tree.delete(scanner.next());
                } else if (cmd.equals("find")) {
                    tree.find(scanner.next());
                } else if (cmd.equals("min")) {
                    tree.min();
                } else if (cmd.equals("max")) {
                    tree.max();
                } else if (cmd.equals("successor")){
                    tree.successor(scanner.next());
                } else if (cmd.equals("inorder")){
                    tree.inorder();
                }
            }
            long finish = System.currentTimeMillis();
            scanner.close();

            System.err.println("Time: " + (finish - start) + " ms");
            System.err.println("Insert: " + tree.getInsertCount());
            System.err.println("Delete: " + tree.getDeleteCount());
            System.err.println("Min: " + tree.getMinCount());
            System.err.println("Max: " + tree.getMaxCount());
            System.err.println("Successor: " + tree.getSuccessorCount());
            System.err.println("Find: " + tree.getFindCount());
            System.err.println("Inorder: " + tree.getInorderCount());
            System.err.println("Load: " + tree.getLoadCount());
            System.err.println("Number of elements: " + tree.getElementsCount());
            System.err.println("Max number of elements: " + tree.getMaxElementsCount());
            System.err.println("Comparisons: " + tree.getComparisonsCount());

        } catch (IOException ex){
            ex.printStackTrace();
        }
    }
}
