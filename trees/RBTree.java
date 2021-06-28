package org.example;

public class RBTree extends BSTree {
    RBTree(){
        root = nullNode;
        nullNode = new Node("null", "black");
    }

    @Override
    protected void insertFixUp(Node newNode){
        while (newNode.parent.color.equals("red")){
            comparisonsCount++;
            if (newNode.parent.equals(newNode.parent.parent.leftChild)){
                Node temp = newNode.parent.parent.rightChild;
                if (temp.color.equals("red")){
                    newNode.parent.color = "black";
                    temp.color = "black";
                    newNode.parent.parent.color = "red";
                    newNode = newNode.parent.parent;
                } else {
                    if (newNode.equals(newNode.parent.rightChild)) {
                        newNode = newNode.parent;
                        leftRotate(newNode);
                    }
                    comparisonsCount++;
                    newNode.parent.color = "black";
                    newNode.parent.parent.color = "red";
                    rightRotate(newNode.parent.parent);
                }
            } else {
                Node temp = newNode.parent.parent.leftChild;
                if (temp.color.equals("red")){
                    newNode.parent.color = "black";
                    temp.color = "black";
                    newNode.parent.parent.color = "red";
                    newNode = newNode.parent.parent;
                } else {
                    if (newNode.equals(newNode.parent.leftChild)) {
                        newNode = newNode.parent;
                        rightRotate(newNode);
                    }
                    comparisonsCount++;
                    newNode.parent.color = "black";
                    newNode.parent.parent.color = "red";
                    leftRotate(newNode.parent.parent);
                }
            }
        }
        root.color = "black";
    }

    protected void leftRotate(Node newNode){
        Node temp = newNode.rightChild;
        if (temp == null || temp.equals(nullNode)){
            return;
        }
        newNode.rightChild = temp.leftChild;
        if (temp.leftChild != null && !temp.leftChild.equals(nullNode)){
            temp.leftChild.parent = newNode;
        }
        temp.parent = newNode.parent;
        if (newNode.parent == null || newNode.parent.equals(nullNode)){
            root = temp;
        } else if (newNode.equals(newNode.parent.leftChild)){
            comparisonsCount++;
            newNode.parent.leftChild = temp;
        } else{
            comparisonsCount++;
            newNode.parent.rightChild = temp;
        }
        temp.leftChild = newNode;
        newNode.parent = temp;
    }

    protected void rightRotate(Node newNode){
        Node temp = newNode.leftChild;
        if (temp == null || temp.equals(nullNode)){
            return;
        }
        newNode.leftChild = temp.rightChild;
        if (temp.rightChild != null && !temp.rightChild.equals(nullNode)){
            temp.rightChild.parent = newNode;
        }
        temp.parent = newNode.parent;
        if (newNode.parent == null || newNode.parent.equals(nullNode)){
            root = temp;
        } else if (newNode.equals(newNode.parent.leftChild)){
            comparisonsCount++;
            newNode.parent.leftChild = temp;
        } else{
            comparisonsCount++;
            newNode.parent.rightChild = temp;
        }
        temp.rightChild = newNode;
        newNode.parent = temp;
    }

    @Override
    protected void deleteFixUp(Node temp){
        Node brother;
        while (!temp.equals(root) && temp.color.equals("black")){
            comparisonsCount++;
            if (temp.equals(temp.parent.leftChild)){
               brother = temp.parent.rightChild;
               if (brother.color.equals("red")){
                   brother.color = "black";
                   temp.parent.color = "red";
                   leftRotate(temp.parent);
                   brother = temp.parent.rightChild;
               }
               if (brother.leftChild.color.equals("black") && brother.rightChild.color.equals("black")){
                   brother.color = "red";
                   temp = temp.parent;
               } else {
                   if (brother.rightChild.color.equals("black")) {
                       brother.leftChild.color = "black";
                       brother.color = "red";
                       rightRotate(brother);
                       brother = temp.parent.rightChild;
                   }
                   brother.color = temp.parent.color;
                   temp.parent.color = "black";
                   brother.rightChild.color = "black";
                   leftRotate(temp.parent);
                   temp = root;
               }
            } else{
                brother = temp.parent.leftChild;
                if (brother.color.equals("red")){
                    brother.color = "black";
                    temp.parent.color = "red";
                    rightRotate(temp.parent);
                    brother = temp.parent.leftChild;
                }
                if (brother.leftChild.color.equals("black") && brother.rightChild.color.equals("black")){
                    brother.color = "red";
                    temp = temp.parent;
                } else {
                    if (brother.leftChild.color.equals("black")) {
                        brother.rightChild.color = "black";
                        brother.color = "red";
                        leftRotate(brother);
                        brother = temp.parent.leftChild;
                    }
                    brother.color = temp.parent.color;
                    temp.parent.color = "black";
                    brother.leftChild.color = "black";
                    rightRotate(temp.parent);
                    temp = root;
                }
            }
        }
        temp.color = "black";
    }
}
