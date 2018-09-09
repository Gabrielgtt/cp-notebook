package tstEda;

import java.util.Arrays;
import java.util.Scanner;

public class MergeSortPasso {
	
	public static void main(String[] args) {
		int arr[] = lerArray();
		
		mergeSort(arr, 0, arr.length-1);
	}

	private static void mergeSort(int[] arr, int left, int right) {
		
		int array[] = Arrays.copyOfRange(arr, left, right+1);
		System.out.println(Arrays.toString(array));
		
		if (left < right) {
			int mid = (left + right) / 2;	
			
			mergeSort(arr, left, mid);
			mergeSort(arr, mid+1, right);
			
			merge(arr, left, right, mid);
		}
	}

	private static void merge(int[] arr, int left, int right, int mid) {
			
		int arrayFinal[] = new int[right-left+1];
		int index = 0, i = left, j = mid+1;
		
		while (i <= mid || j <= right) {
			if (i > mid) {
				arrayFinal[index++] = arr[j++];
			} else if (j > right) {
				arrayFinal[index++] = arr[i++];
			} else if (arr[i] < arr[j]) {
				arrayFinal[index++] = arr[i++];
			} else {
				arrayFinal[index++] = arr[j++];
			}
		}		
		
		System.out.println(Arrays.toString(arrayFinal));
		for (int k = left; k <= right; k++) {
			arr[k] = arrayFinal[k-left];
		}		
	}
	
	public Integer[] preOrder() {
		Integer [] elements = new Integer[this.size()];
		if (this.isEmpty())
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

	private static int[] lerArray() {
		Scanner sc = new Scanner(System.in);
		String entrada[] = sc.nextLine().split(" ");
		sc.close();

		int array[] = new int[entrada.length];
		
		for (int i = 0; i < entrada.length; i++) {	
			array[i] = Integer.parseInt(entrada[i]);
		}
		
		return array;
	}
}
