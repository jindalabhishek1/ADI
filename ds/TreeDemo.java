import java.util.Scanner;

class Node
{
    int data;
    Node left, right;
    Node()
    {
        data = 0;
    }
    Node (int data)
    {
        this.data = data;
    }
    static Node insert(Node root, int data)
    {
        if (root == null)
        {
            Node newNode = new Node(data);
            root = newNode;
            return root;
        }
        // Node temp = root;
        if(data < root.data)
        {
            insert(root.left, data);
        }
        else
        {
            insert(root.right, data);
        }
        return root;
    }

    static void display(Node root)
    {
        if (root.left == null && root.right == null)
        {
            System.out.println(root.data);
            return;
        }
        display(root.left);
        System.out.println(root.data);
        display(root.right);
    }
}

class TreeDemo extends Node
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        // int size = sc.nextInt();
        Node root = new Node(5);
        /*
        for (int i = 0; i < size; i++)
        {
            int data = sc.nextInt();
            root = insert(root, data);
        }
        System.out.println(root.data + " " + root.left.data + " " + root.right.data);
        */
        root.left = new Node(3);
        root.right = new Node(6);
        display(root);
    }
}