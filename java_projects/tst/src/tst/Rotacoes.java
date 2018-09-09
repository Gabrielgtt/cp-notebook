package tst;

import java.util.Arrays;
import java.util.Scanner;

class Rotacoes {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int arr[] = read(sc);
		BSTImpl <Integer> bst = new BSTImpl <Integer>();
		
		int rotacoes = 0;
		for (int i=0; i<arr.length; i++) {
			rotacoes += bst.insert(arr[i]);
		}
		if (rotacoes == 0) {
			System.out.println("balanceada");
		}		
	}

	private static int[] read(Scanner sc) {
		String entrada[] = sc.nextLine().split(" ");
		int arr[] = new int[entrada.length];

		for (int i = 0; i < entrada.length; i++) {
			arr[i] = Integer.parseInt(entrada[i]);
		}

		return arr;
	}
}

class BSTNode<T> {
	protected T data;
	protected BSTNode<T> left;
	protected BSTNode<T> right;
	protected BSTNode<T> parent;

	public BSTNode(T data, BSTNode<T> left, BSTNode<T> right, BSTNode<T> parent) {
		this.data = data;
		this.left = left;
		this.right = right;
		this.parent = parent;
	}

	public BSTNode() {
	}

	public boolean isEmpty() {
		return this.data == null;
	}

	public boolean isLeaf() {
		return this.data != null && this.left.isEmpty() && this.right.isEmpty();
	}

	@Override
	public String toString() {
		String resp = "NIL";
		if (!isEmpty()) {
			resp = data.toString();
		}
		return resp;
	}

	@SuppressWarnings("unchecked")
	@Override
	public boolean equals(Object obj) {
		boolean resp = false;
		if (obj instanceof BSTNode) {
			if (!this.isEmpty() && !((BSTNode<T>) obj).isEmpty()) {
				resp = this.data.equals(((BSTNode<T>) obj).data);
			} else {
				resp = this.isEmpty() && ((BSTNode<T>) obj).isEmpty();
			}

		}
		return resp;
	}

	public T getData() {
		return data;
	}

	public void setData(T data) {
		this.data = data;
	}

	public BSTNode<T> getLeft() {
		return left;
	}

	public void setLeft(BSTNode<T> left) {
		this.left = left;
	}

	public BSTNode<T> getRight() {
		return right;
	}

	public void setRight(BSTNode<T> right) {
		this.right = right;
	}

	public BSTNode<T> getParent() {
		return parent;
	}

	public void setParent(BSTNode<T> parent) {
		this.parent = parent;
	}
}


class BSTImpl<T extends Comparable<T>> {

	protected BSTNode<T> root;

	public BSTImpl() {
		root = new BSTNode<T>();
	}

	public int insert(T element) {
		BSTNode<T> inserted = insert(root, null, element);
		int rotacoes = rebalanceUp(inserted);
		return rotacoes;
	}

	private BSTNode<T> insert(BSTNode<T> node, BSTNode<T> parent, T element) {
		if (node.isEmpty()) {
			node.setData(element);
			node.setLeft(new BSTNode<T>());
			node.setRight(new BSTNode<T>());
			node.setParent(parent);
			return node;
		} else {
			if (node.getData().compareTo(element) < 0) {
				return insert((BSTNode<T>) node.getRight(), node, element);
			} else {
				return insert((BSTNode<T>) node.getLeft(), node, element);
			}
		}
	}
	
	public BSTNode<T> leftRotation(BSTNode<T> node) {
		if (node.getRight().isEmpty())
			return null;
		
		System.out.println("rot_esq(" + node.getData() + ")");

		BSTNode<T> right = (BSTNode<T>) node.getRight();
		
		if (node.equals(this.root)) root = right;

		node.setRight(right.getLeft());

		node.getRight().setParent(node);

		right.setLeft(node);

		right.setParent(node.getParent());
		
		if (node.getParent() != null) node.getParent().setLeft(right);

		node.setParent(right);
		
		System.out.println(Arrays.toString(this.preOrder()));

		return right;
	}

	public BSTNode<T> rightRotation(BSTNode<T> node) {
		if (node.getLeft().isEmpty())
			return null;
		

		System.out.println("rot_dir(" + node.getData() + ")");

		BSTNode<T> left = (BSTNode<T>) node.getLeft();

		if (node.equals(this.root)) root = left;

		node.setLeft(left.getRight());

		node.getLeft().setParent(node);

		left.setRight(node);

		left.setParent(node.getParent());
		
		if (node.getParent() != null) node.getParent().setRight(left);

		node.setParent(left);
		
		System.out.println(Arrays.toString(this.preOrder()));

		return left;
	}

	protected int calculateBalance(BSTNode<T> node) {
		return height((BSTNode<T>) node.getLeft()) - height((BSTNode<T>) node.getRight());
	}

	protected int rebalance(BSTNode<T> node) {
		if (node.getParent() != null && node.getParent().getParent() != null) {
			BSTNode<T> grand = (BSTNode<T>) node.getParent().getParent();
			BSTNode<T> parent = (BSTNode<T>) node.getParent();

			int balance = calculateBalance(grand);

			if (balance < -1) {
				if (grand.getRight().equals(parent) && parent.getRight().equals(node)) {
					leftRotation(grand);
					return 1;

				} else if (grand.getRight().equals(parent) && parent.getLeft().equals(node)) {
					rightRotation(parent);
					leftRotation(grand);
					return 1;
				}

			} else if (balance > 1) {
				if (grand.getLeft().equals(parent) && parent.getLeft().equals(node)) {
					rightRotation(grand);
					return 1;

				} else if (grand.getLeft().equals(parent) && parent.getRight().equals(node)) {
					leftRotation(parent);
					rightRotation(grand);
					return 1;
				}
			}
		}
		return 0;
	}

	protected int rebalanceUp(BSTNode<T> node) {
		int res = 0;
		if (node != null) {
			res += rebalance(node);
			res += rebalanceUp((BSTNode<T>) node.getParent());
		}
		return res;
	}

	public BSTNode<T> getRoot() {
		return this.root;
	}

	public boolean isEmpty() {
		return root.isEmpty();
	}

	public int height() {
		return height(root) - 1;
	}

	protected int height(BSTNode<T> node) {
		if (node.isEmpty())
			return 0;

		int right = 0, left = 0;

		if (!node.getRight().isEmpty()) {
			right = height((BSTNode<T>) node.getRight());
		}
		if (!node.getLeft().isEmpty()) {
			left = height((BSTNode<T>) node.getLeft());
		}

		if (right > left)
			return right + 1;
		return left + 1;
	}

	public BSTNode<T> search(T element) {
		if (root.isEmpty())
			return new BSTNode<T>();
		return search(root, element);
	}

	private BSTNode<T> search(BSTNode<T> node, T element) {
		if (node.getData().equals(element))
			return node;

		if (node.getData().compareTo(element) < 0) {
			if (node.getRight().isEmpty())
				return new BSTNode<T>();
			return search((BSTNode<T>) node.getRight(), element);
		} else {
			if (node.getLeft().isEmpty())
				return new BSTNode<T>();
			return search((BSTNode<T>) node.getLeft(), element);
		}
	}

	public BSTNode<T> maximum() {
		if (root.isEmpty())
			return null;
		return maximum(root);
	}

	private BSTNode<T> maximum(BSTNode<T> node) {
		if (node.getRight().isEmpty())
			return node;
		return maximum((BSTNode<T>) node.getRight());
	}

	public BSTNode<T> minimum() {
		if (root.isEmpty())
			return null;
		return minimum(root);
	}

	private BSTNode<T> minimum(BSTNode<T> node) {
		if (node.getLeft().isEmpty())
			return node;
		return minimum((BSTNode<T>) node.getLeft());
	}

	public BSTNode<T> sucessor(T element) {
		BSTNode<T> node = search(element);
		if (node == null)
			return null;
		return sucessor(node);
	}

	protected BSTNode<T> sucessor(BSTNode<T> node) {
		if (node.isEmpty())
			return null;

		if (!node.getRight().isEmpty()) {
			return minimum((BSTNode<T>) node.getRight());
		}

		BSTNode<T> curr = node;

		while (curr.getParent() != null && curr.getParent().getData().compareTo(node.getData()) < 0) {
			curr = (BSTNode<T>) curr.getParent();
		}

		return (BSTNode<T>) curr.getParent();
	}

	public BSTNode<T> predecessor(T element) {
		BSTNode<T> node = search(element);
		if (node == null)
			return null;
		return predecessor(node);
	}

	private BSTNode<T> predecessor(BSTNode<T> node) {
		if (node.isEmpty())
			return null;

		if (!node.getLeft().isEmpty()) {
			return maximum((BSTNode<T>) node.getLeft());
		}

		BSTNode<T> curr = node;

		while (curr.getParent() != null && curr.getParent().getData().compareTo(node.getData()) > 0) {
			curr = (BSTNode<T>) curr.getParent();
		}

		return (BSTNode<T>) curr.getParent();
	}

	@SuppressWarnings("unchecked")
	public T[] preOrder() {
		Comparable<T>[] elements = new Comparable[this.size()];
		if (this.isEmpty())
			return (T[]) elements;
		preOrder(root, 0, elements);
		return (T[]) elements;
	}

	private int preOrder(BSTNode<T> node, int index, Comparable[] elements) {
		elements[index] = node.getData();

		if (!node.getLeft().isEmpty()) {
			index = preOrder((BSTNode<T>) node.getLeft(), index + 1, elements);
		}

		if (!node.getRight().isEmpty()) {
			index = preOrder((BSTNode<T>) node.getRight(), index + 1, elements);
		}

		return index;
	}

	public int size() {
		return size(root);
	}

	private int size(BSTNode<T> node) {
		int result = 0;
		if (!node.isEmpty()) {
			result = 1 + size((BSTNode<T>) node.getLeft()) + size((BSTNode<T>) node.getRight());
		}
		return result;
	}

}