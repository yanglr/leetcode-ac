class Test3 {
    public boolean isValid(String s) {
        // ...
        return false;
    }
}

class Main {
    public static void main(String[] args) {
        Test3 sol = new Test3();
        String s = "()[]{}";
        boolean res = sol.isValid(s);
        
        System.out.println(res);
    }
}