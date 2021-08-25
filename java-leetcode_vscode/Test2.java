class Test2 {
    public int sum(int a, int b) {
        return a + b;
    }

    // Test
    public static void main(String[] args) {
        Test2 sol = new Test2();
        int a = 2, b = 5;
        int res = sol.sum(a, b);
        
        System.out.println(res);
        /* To print array */
        // System.out.println(Arrays.toString(arr));  

        /* To print list in Java 8 */
        // System.out.println(Arrays.toString(list.toArray()));
        // list.forEach(System.out::println);
        // list.stream().forEach(System.out::println);
    }
}