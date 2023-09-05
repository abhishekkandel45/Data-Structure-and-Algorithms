// Program to find the Pair from the Given array which sum is 10 given array [8,7,2,5,3,1] 

import java.util.*;
class PairSum {
    public static void main(String[] args) {
        arrayPairSum(new int[]{8,7,2,5,3,1}, 10);   
    }

    public static void arrayPairSum(int[] arr, int sum) {
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        for (int i = 0; i < arr.length; i++) {
            int temp = sum - arr[i];
            if (map.containsKey(temp)) {
                System.out.println("Pair is " + arr[i] + " " + temp);
            } else {
                map.put(arr[i], i);
            }
        }
    }
}
