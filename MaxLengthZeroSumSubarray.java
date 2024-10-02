import java.util.HashMap;

public class MaxLengthZeroSumSubarray {
    public static void main(String[] args) {
        int[] arr = {1, -1, 3, 2, -2, -3, 3}; // Example array
        System.out.println("Maximum length of subarray with sum 0: " + maxLengthZeroSum(arr));
    }

    public static int maxLengthZeroSum(int[] arr) {
        HashMap<Integer, Integer> cumulativeSumMap = new HashMap<>();
        int maxLength = 0;
        int cumulativeSum = 0;

        // Initialize the map with a cumulative sum of 0 at index -1
        cumulativeSumMap.put(0, -1);

        for (int i = 0; i < arr.length; i++) {
            cumulativeSum += arr[i];

            // Check if this cumulative sum has been seen before
            if (cumulativeSumMap.containsKey(cumulativeSum)) {
                // Calculate the length of the subarray
                int length = i - cumulativeSumMap.get(cumulativeSum);
                maxLength = Math.max(maxLength, length);
            } else {
                // Store the index of this cumulative sum
                cumulativeSumMap.put(cumulativeSum, i);
            }
        }

        return maxLength;
    }
}
