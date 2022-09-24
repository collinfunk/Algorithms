package mergesort;
import java.util.Arrays;


public class MergeSort {

    public static int[] merge_sort (int[] array) {
        if (array.length <= 1) {
            return array;
        }

        int middle = array.length / 2;
        int[] left = Arrays.copyOfRange(array, 0, middle);
        int[] right = Arrays.copyOfRange(array, middle, array.length);
        return merge(merge_sort(left), merge_sort(right));
    }

    public static int[] merge (int[] left, int[] right) {
        int[] result = new int[left.length + right.length];
        int left_index = 0;
        int right_index = 0;
        int result_index = 0;

        while (left_index < left.length || right_index < right.length) {
            if (left_index < left.length && right_index < right.length) {
                if (left[left_index] < right[right_index]) {
                    result[result_index] = left[left_index];
                    left_index++;
                    result_index++;
                } 
                
                else {
                    result[result_index] = right[right_index];
                    right_index++;
                    result_index++;
                }
            } 
            
            else if (left_index < left.length) {
                result[result_index] = left[left_index];
                left_index++;
                result_index++;
            } 
            
            else if (right_index < right.length) {
                result[result_index] = right[right_index];
                right_index++;
                result_index++;
            }
        }
        
        return result;
    }
}