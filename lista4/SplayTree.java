package org.example;

public class SplayTree extends RBTree {
    public SplayTree() {
        root = null;
        nullNode = null;
    }

    @Override
    public void splay(Node node) {
        while(node.parent != null) {
            if(node.parent == this.root) {
                if(node == node.parent.leftChild) {
                    this.rightRotate(node.parent);
                }
                else {
                    this.leftRotate(node.parent);
                }
            }
            else {
                Node dad = node.parent;
                Node grandpa = dad.parent;

                if(node.equals(dad.leftChild) && dad.equals(grandpa.leftChild)) {
                    this.rightRotate(grandpa);
                    this.rightRotate(dad);
                }
                else if(node.equals(dad.rightChild) && dad.equals(grandpa.rightChild)) {
                    this.leftRotate(grandpa);
                    this.leftRotate(dad);
                }
                else if(node.equals(dad.rightChild) && dad.equals(grandpa.leftChild)) {
                    this.leftRotate(dad);
                    this.rightRotate(grandpa);
                }
                else {
                    this.rightRotate(dad);
                    this.leftRotate(grandpa);
                }
            }
        }
    }

    @Override
    public void delete(String s){
        Node result = innerFind(root, s);
        if (result == null || result.equals(nullNode))
            return;

        SplayTree leftTree = new SplayTree();
        leftTree.root = root.leftChild;
        SplayTree rightTree = new SplayTree();
        rightTree.root = root.rightChild;
        if (leftTree.root != null)
            leftTree.root.parent = null;
        if (rightTree.root != null)
            rightTree.root.parent = null;
        if (leftTree.root != null){
            Node leftMax = leftTree.innerMax(leftTree.root);
            leftTree.splay(leftMax);
            leftTree.root.rightChild = rightTree.root;
            if (rightTree.root != null)
                rightTree.root.parent = leftTree.root;
            root = leftTree.root;
        } else{
            root = rightTree.root;
        }
    }

    @Override
    public void max(){
        maxCount++;
        Node temp = innerMax(root);
        if (temp == null || temp.equals(nullNode)){
            System.out.println();
        } else{
            splay(temp);
            System.out.println(temp.key);
        }
    }

    @Override
    public void min(){
        minCount++;
        Node temp = innerMin(root);
        if (temp == null || temp.equals(nullNode)){
            System.out.println();
        } else{
            splay(temp);
            System.out.println(temp.key);
        }
    }

    @Override
    protected void insertFixUp(Node node){}

    @Override
    protected void deleteFixUp(Node node){}
}
