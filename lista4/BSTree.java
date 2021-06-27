package org.example;

import java.util.Stack;

public class BSTree extends AbstractBinaryTree {
    BSTree(){
        root = null;
        nullNode = null;
    }

    @Override
    public void insert(String s) {
        s = prepareToInsert(s);
        if (s.length() == 0){
            return;
        }
        insertCount++;
        elementsCount++;
        maxElementsCount = Math.max(maxElementsCount, elementsCount);
        Node newNode = new Node(s, "red");
        Node prev = nullNode;
        Node temp = root;
        while (temp != null && !temp.equals(nullNode)){
            comparisonsCount ++;
            prev = temp;
            if (s.compareTo(temp.key) < 0){
                temp = temp.leftChild;
            } else {
                temp = temp.rightChild;
            }
        }
        newNode.parent = prev;
        if (prev == null || prev.equals(nullNode)){
            root = newNode;
        } else if (s.compareTo(prev.key) < 0){
            comparisonsCount++;
            prev.leftChild = newNode;
        } else {
            comparisonsCount++;
            prev.rightChild = newNode;
        }
        newNode.leftChild = nullNode;
        newNode.rightChild = nullNode;
        insertFixUp(newNode);
        splay(newNode);
    }

    protected void insertFixUp(Node newNode){}
    public void splay(Node node){}

    @Override
    public void delete(String s) {
        deleteCount++;
        Node temp = innerFind(root, s);
        if (temp == null || temp.equals(nullNode)){
            return;
        }
        Node next = temp;
        String originalColor = next.color;
        Node helper;
        elementsCount--;
        if (temp.leftChild == null || temp.leftChild.equals(nullNode)){
            helper = temp.rightChild;
            transplant(temp, temp.rightChild);
        } else if (temp.rightChild == null || temp.rightChild.equals(nullNode)){
            helper = temp.leftChild;
            transplant(temp, temp.leftChild);
        } else{
            next = innerMin(temp.rightChild);
            originalColor = next.color;
            helper = next.rightChild;
            if (next.parent.equals(temp)){
                if (helper != null)
                    helper.parent = next;
            } else{
                transplant(next, next.rightChild);
                next.rightChild = temp.rightChild;
                next.rightChild.parent = next;
            }
            comparisonsCount++;
            transplant(temp, next);
            next.leftChild = temp.leftChild;
            next.leftChild.parent = next;
            next.color = temp.color;
        }
        if (originalColor.equals("black")){
            deleteFixUp(helper);
        }
    }

    protected void deleteFixUp(Node temp){}

    private void transplant(Node old, Node sub){
        if (old.parent == null || old.parent.equals(nullNode)){
            root = sub;
        } else if (old.equals(old.parent.leftChild)){
            comparisonsCount++;
            old.parent.leftChild = sub;
        } else {
            comparisonsCount++;
            old.parent.rightChild = sub;
        }
        if (sub != null)
            sub.parent = old.parent;
    }

    @Override
    public void min(){
        minCount++;
        Node temp = innerMin(root);
        if (temp == null || temp.equals(nullNode)){
            System.out.println();
        } else{
            System.out.println(temp.key);
        }
    }

    protected Node innerMin(Node x){
        if (x != null && !x.equals(nullNode)){
            Node temp = x;
            while (temp.leftChild != null && !temp.leftChild.equals(nullNode)){
                temp = temp.leftChild;
            }
            return temp;
        }
        return null;
    }

    @Override
    public void max(){
        maxCount++;
        Node temp = innerMax(root);
        if (temp == null || temp.equals(nullNode)){
            System.out.println();
        } else{
            System.out.println(temp.key);
        }
    }

    protected Node innerMax(Node x){
        if (x != null && !x.equals(nullNode)){
            Node temp = x;
            while (temp.rightChild != null && !temp.rightChild.equals(nullNode)){
                temp = temp.rightChild;
            }
            return temp;
        }
        return nullNode;
    }

    @Override
    public void successor(String s){
        successorCount++;
        Node temp = innerFind(root, s);
        if (temp == null || temp.equals(nullNode)){
            System.out.println();
        } else {
            if (temp.rightChild != null && !temp.rightChild.equals(nullNode)){
                Node result = innerMin(temp.rightChild);
                splay(result);
                System.out.println(result.key);
            } else {
                Node prev = temp.parent;
                while (prev != null && !prev.equals(nullNode) && temp == prev.rightChild){
                    comparisonsCount++;
                    temp = prev;
                    prev = prev.parent;
                }
                if (prev == null || prev.equals(nullNode)){
                    System.out.println();
                } else {
                    splay(prev);
                    System.out.println(prev.key);
                }
            }
        }
    }

    @Override
    public void find(String s){
        findCount++;
        Node result = innerFind(root, s);
        if (result == null || result.equals(nullNode)){
            System.out.println("0");
        } else{
            System.out.println("1");
        }
    }

    protected Node innerFind(Node first, String s){
        comparisonsCount++;
        if (first == null || first.equals(nullNode) || s.equals(first.key)){
            if (first != null && !first.equals(nullNode))
                splay(first);
            return first;
        } else {
            comparisonsCount++;
            if (s.compareTo(first.key) < 0){
                return innerFind(first.leftChild, s);
            } else {
                return innerFind(first.rightChild, s);
            }
        }
    }

    @Override
    public void inorder() {
        inorderCount++;
        if (root == null || root.equals(nullNode)){
            System.out.println();
        } else {
            inorderWalk(root);
            System.out.println();
        }
    }

    protected void inorderWalk(Node x) {
        Stack<Node> stack = new Stack();
        Node temp = x;

        while (!stack.empty() || (temp != null && !temp.equals(nullNode))) {
            if (temp != null && !temp.equals(nullNode)) {
                stack.push(temp);
                temp = temp.leftChild;
            } else {
                temp = stack.pop();
                System.out.print(temp.key + " ");
                temp = temp.rightChild;
            }
        }
    }
}
