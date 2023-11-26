public class MainExample {
    public static void main(String[] args) {
        // Example array
        int[] array = { -3, -2, -1, 0, 1, 2, 3 };

        // Call the oddOrPos method and print the result
        int result = oddOrPos(array);
        System.out.println("Number of elements that are odd or positive: " + result);
    }

    public static int oddOrPos(int[] x) {
        // effects: if x==null throw nullPointerException
        // else return the number of elements in x that are either odd or positive (or both)
        if (x == null) {
            throw new NullPointerException("Array x cannot be null");
        }

        int count = 0;
        for (int i = 0; i < x.length; i++) {
            if (x[i] % 2 == 1 || x[i] > 0) {
                count++;
            }
        }
        return count;
    }
}
