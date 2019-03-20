package tst;

import java.util.Arrays;
import java.util.Scanner;

class BuildHeap {

	static int heap[];
	static int index = -1;
	
	private static int parent(int i) {
		return (i - 1) / 2;
	}

	private static int left(int i) {
		return (i * 2 + 1);
	}

	private static int right(int i) {
		return (i * 2 + 1) + 1;
	}

	public static boolean isEmpty() {
		return (index == -1);
	}

	public static int[] toArray() {
		return Arrays.copyOf(heap, index+1);
	}
	
	public static int size() {
		return index+1;
	}

	
	private static void heapify(int position) {
		int rightValue = -10;
		int leftValue = -10;

		if (right(position) < size())
			rightValue = heap[right(position)];

		if (left(position) < size())
			leftValue = heap[left(position)];

		if (right(position) < size() && heap[position] < rightValue && leftValue < rightValue) {

			swap(heap, right(position), position);
			heapify(right(position));

		} else if (left(position) < size() && heap[position] < leftValue) {

			swap(heap, left(position), position);
			heapify(left(position));
		}
	}

	private static void swap(int[] arr, int i, int j) {
		int aux = arr[i];
		arr[i] = arr[j];
		arr[j] = aux;		
	}

	public static void buildHeap(int[] array) {
		heap = Arrays.copyOf(array, array.length);
		index = array.length - 1;
		int lastParent = parent(index);

		while (lastParent >= 0) {
			heapify(lastParent--);
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int arr[] = read(sc);
		buildHeap(arr);
		System.out.println(Arrays.toString(heap));
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
