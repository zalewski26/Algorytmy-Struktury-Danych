package org.example;

import java.io.*;

public abstract class AbstractBinaryTree {
    class Node{
        String key;
        Node parent;
        Node leftChild;
        Node rightChild;
        String color;

        Node(String key){
            this.key = key;
        }
        Node(String key, String color){
            this.key = key;
            this.color = color;
        }
    }
    protected Node root;
    protected Node nullNode;

    protected int elementsCount = 0;
    protected int maxElementsCount = 0;
    protected long comparisonsCount = 0;
    protected int insertCount = 0;
    protected int deleteCount = 0;
    protected int minCount = 0;
    protected int maxCount = 0;
    protected int successorCount = 0;
    protected int findCount = 0;
    protected int inorderCount = 0;
    protected int loadCount = 0;

    public abstract void insert(String s);
    public abstract void delete(String s);
    public abstract void min();
    public abstract void max();
    public abstract void successor(String s);
    public abstract void find(String s);
    public abstract void inorder();

    protected String prepareToInsert(String s){
        String result = "";
        char[] arr = s.toCharArray();
        boolean legal = false;
        for (int i = 0; i < arr.length; i++){
            if (String.valueOf(arr[i]).matches("[a-zA-Z]")){
                legal = true;
            }
            if (legal){
                result += arr[i];
            }
        }
        return result;
    }

    public void load(File f){
        loadCount++;
        try{
            BufferedReader br = new BufferedReader(new FileReader(f));
            String line;
            while ((line = br.readLine()) != null){
                String[] arr = line.split("[^a-zA-Z0-9']");
                for (String s: arr){
                    insert(s);
                }
            }

        } catch (FileNotFoundException x){
            System.out.println("Wskazany plik nie istnieje");
        } catch (IOException x){
            x.printStackTrace();
        }
    }

    public int getInsertCount() {
        return insertCount;
    }

    public int getDeleteCount() {
        return deleteCount;
    }

    public int getMinCount() {
        return minCount;
    }

    public int getMaxCount() {
        return maxCount;
    }

    public int getSuccessorCount() {
        return successorCount;
    }

    public int getFindCount() {
        return findCount;
    }

    public int getInorderCount() {
        return inorderCount;
    }

    public int getLoadCount() {
        return loadCount;
    }

    public int getElementsCount(){
        return elementsCount;
    }

    public int getMaxElementsCount(){
        return maxElementsCount;
    }

    public long getComparisonsCount() {
        return comparisonsCount;
    }
}
