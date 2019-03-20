package tstEda;

//import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class BST {
	
	class BTNode<T> {
		protected T data;
		protected BTNode<T> left;
		protected BTNode<T> right;
		protected BTNode<T> parent;
		
		public BTNode(T data, BTNode<T> left, BTNode<T> right, BTNode<T> parent) {
			this.data = data;
			this.left = left;
			this.right = right;
			this.parent = parent;
		}
		
		public BTNode() {
		}
		
		public boolean isEmpty() {
			return this.data == null;
		}
		
		public boolean isLeaf() {
			return this.data != null && this.left.isEmpty() && this.right.isEmpty();
		}
		
		public T getData() {
			return data;
		}
		
		public void setData(T data) {
			this.data = data;
		}
		
		public BTNode<T> getLeft() {
			return left;
		}
		
		public void setLeft(BTNode<T> left) {
			this.left = left;
		}
		
		public BTNode<T> getRight() {
			return right;
		}
		
		public void setRight(BTNode<T> right) {
			this.right = right;
		}
		
		public BTNode<T> getParent() {
			return parent;
		}
		
		public void setParent(BTNode<T> parent) {
			this.parent = parent;
		}
		
		@SuppressWarnings("unchecked")
		@Override
		public boolean equals(Object obj) {
			boolean resp = false;
			if (obj instanceof BTNode) {
				if (!this.isEmpty() && !((BTNode<T>) obj).isEmpty()) {
					resp = this.data.equals(((BTNode<T>) obj).data);
				} else {
					resp = this.isEmpty() && ((BTNode<T>) obj).isEmpty();
				}

			}
			return resp;
		}

	}
	
	protected BTNode <Integer> root;
	
	public BST() {
		root = new BTNode <Integer> ();
	}
	
	public BTNode <Integer> getRoot() {
		return this.root;
	}
	
	public boolean isEmpty() {
		return root.isEmpty();
	}
	
	public BTNode<Integer> search(Integer element ) {
		if (root.isEmpty())
			return new BTNode<Integer>();
		
		return search(root, element);
	}
	
	protected BTNode<Integer> search(BTNode<Integer> node, Integer element) {
		if (node.getData().equals(element)) {
			return node;			
		} 
		
		if (node.getData().compareTo(element) < 0) {
			if (node.getRight().isEmpty())
				return new BTNode<Integer>();
			
			return search(node.getRight(), element);
		} else {
			if (node.getLeft().isEmpty())
				return new BTNode<Integer>();
			
			return search(node.getLeft(), element);
		}
	}

	public void insert(Integer element) {
		insert(root, null, element);
	}
	
	protected void insert(BTNode<Integer> node, BTNode <Integer> parent, Integer element) {
		if (node.isEmpty()) {
			node.setData(element);
			node.setLeft(new BTNode <Integer>());
			node.setRight(new BTNode <Integer>());
			node.setParent(parent);
		} else {
			if (node.getData().compareTo(element) < 0) {
				insert((BTNode <Integer>) node.getRight(), node, element);
			} else {
				insert((BTNode <Integer>) node.getLeft(), node, element);
			}
		}
	}
	
	public Integer[] preOrder(int size) {
		Integer [] elements = new Integer[size];
		if (root.isEmpty())
			return (Integer[]) elements;
		preOrder(root, 0, elements);
		return (Integer[]) elements;
	}
	
	private int preOrder(BTNode <Integer> node, int index, Integer[] elements) {
		elements[index] = node.getData();
		
		if (!node.getLeft().isEmpty()) {
			index = preOrder(node.getLeft(), index + 1, elements);
		}
		
		if (!node.getRight().isEmpty()) {
			index = preOrder(node.getRight(), index + 1, elements);
		}
		
		return index;
	}	
	
	private BTNode<Integer> minimum(BTNode<Integer> node) {
		if (node.getLeft().isEmpty()) {
			return node;
		}
		
		return minimum(node.getLeft());
	}
	
	
	public BTNode<Integer> sucessor(Integer element) {
		BTNode<Integer> node = search(element);
		if (node == null)
			return null;
		return sucessor(node);
	}
	
	private BTNode<Integer> sucessor(BTNode<Integer> node) {
		if (node.isEmpty())
			return null;
		
		if (!node.getRight().isEmpty()) {
			return minimum(node.getRight());
		}
		
		BTNode<Integer> curr = node;
		
		while (curr.getParent() != null && curr.getParent().getData().compareTo(node.getData()) < 0) {
			curr = curr.getParent();
		}
		
		return curr.getParent();
	}

	public boolean remove(Integer element) {
		BTNode<Integer> node = search(element);
		if (node.isEmpty()) return false;
		remove(node);
		return true;
	}
	
	private void remove(BTNode<Integer> node) {
		if (node != null) {
			if (node.isLeaf()) {
				replaceNodeInParent(node, new BTNode<Integer>());
				
			} else if (node.getRight().isEmpty()) {
				replaceNodeInParent(node, (BTNode<Integer>) node.getLeft());
				
			} else if (node.getLeft().isEmpty()) {
				replaceNodeInParent(node, (BTNode<Integer>) node.getRight());
				
			} else {
				BTNode<Integer> suc = sucessor(node);
				node.setData(suc.getData());
				remove(suc);
			}
		}
	}
	
	protected void replaceNodeInParent(BTNode<Integer> node, BTNode<Integer> target) {
		if (node.getParent() == null) {
			root = target;
			target.setParent(null);
		} else {
			if (node.getParent().getData().compareTo(node.getData()) <= 0) {
				node.getParent().setRight(target);
				target.setParent(node.getParent());
			} else {
				node.getParent().setLeft(target);
				target.setParent(node.getParent());
			}
		}
	}
	
	private void bfs() {
		Queue < BTNode <Integer> > fila = new LinkedList < BTNode <Integer> > ();		
		
		System.out.print(root.data);
		
		if (!root.right.isEmpty()) fila.add(root.right);
		if (!root.left.isEmpty()) fila.add(root.left);
		
		while (!fila.isEmpty()) {
			System.out.print(" " + fila.peek().data);
			if (!fila.peek().right.isEmpty()) fila.add(fila.peek().right);
			if (!fila.peek().left.isEmpty()) fila.add(fila.peek().left);
			fila.remove();
		}
		
		System.out.println("");
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int arr[] = lerArray(sc);
		
		BST bst = new BST();
		
		for (Integer num : arr) {
			bst.insert(num);
		}
		
		bst.bfs();
		
		sc.close();
	}

	private static int[] lerArray(Scanner sc) {
		String entrada[] = sc.nextLine().split(" ");
		
		int array[] = new int[entrada.length];
		
		for (int i = 0; i < entrada.length; i++) {	
			array[i] = Integer.parseInt(entrada[i]);
		}
		
		return array;
	}
}