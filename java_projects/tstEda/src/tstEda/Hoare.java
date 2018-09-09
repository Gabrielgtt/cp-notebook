package tstEda;

import java.util.Arrays;
import java.util.Scanner;

public class Hoare {

	public static void main(String[] args) {
		int arr[] = lerArray();
		
		hoare(arr, 0, arr.length - 1);
		
		System.out.println(Arrays.toString(arr));
	}

	private static void hoare(int[] arr, int left, int right) {
		int pivot = arr[left], i = left-1, j = right+1;
		
		while (true) {
			while(arr[++i] < pivot);
			while(arr[--j] > pivot);
			if (i >= j) return;
			swap(arr, i, j);
		}
	}
	
	private static void swap(int[] array, int i, int j) {
		int aux = array[i];
		array[i] = array[j];
		array[j] = aux;		
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
