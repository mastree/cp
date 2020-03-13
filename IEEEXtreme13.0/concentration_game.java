import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    static final int MOD = 1000000007; // 1e9 + 7
    static final boolean AUTO_FLUSH = true; // slow if true
    // int = num(); // long = ll();
    // string = next(); // a string line = line();
    // ---------------------------------- \
    
    void main() {
        int n = num();
        int[] arr = new int[2*n+1];
        for (int i = 1; i <= 2*n; i += 2) {
            outln(i + " " + (i+1));
            String next = next();
            if (next.equals("MATCH")) {
                arr[i] = -1;
                arr[i+1] = -1;
            } else {
                arr[i] = Integer.parseInt(next);
                arr[i+1] = num();
            }
        }
        for (int i = 1; i <= 2*n; ++i) {
            if (arr[i] == -1)
                continue;
            for (int j = i+1; j <= 2*n; ++j) {
                if (arr[i] == arr[j]) {
                    outln(i + " " + j);
                    arr[i] = -1;
                    arr[j] = -1;
                    break;
                }
            }
        }
        outln(-1);
    }
    
    // ---------------------------------- \
    //#region
    static boolean ONLINE_JUDGE = isOnlineJudge();
    static boolean isOnlineJudge() {
        boolean ans = true;
        for (String s : System.getProperty("sun.java.command", "").split(" ")) {
            if (s.equals("-DCP_DEBUG")) {
                ans = false;
                break;
            }
        }
        return ans;
    }
    public static void main(String[] args) {
        if (!ONLINE_JUDGE)
            startTime();
        new Main().main();
        boolean endsWithEnter = TO_BE_PRINTED.length() == 0 || TO_BE_PRINTED.charAt(TO_BE_PRINTED.length() - 1) == '\n';
        flush();
        if (ONLINE_JUDGE)
            return;
        if (!endsWithEnter)
            log('\n');
        logTime();
        logMem();
    }
    static Random RAND = new Random();
    static int random(int from, int to) {
        return RAND.nextInt(to-from+1)+from;
    }
    static void logTime() {
        log("Time: " + getTime() + "ms");
    }
    static void logMem() {
        log("Memory (End): " + (int) (Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory()) / 1024 + " KB");
    }
    static long ll() {
        return Long.parseLong(next());
    }
    static int num() {
        return Integer.parseInt(next());
    }
    static void generateInputMode() throws Exception {
        System.setOut(new PrintStream(new FileOutputStream("/mnt/Data/PROGRAMMING/input.txt")));
    }
    static String line() {
        if (!tokenize())
            return null;
        INPUT_STREAM.setLength(0);
        if (STRING_TOKENIZER.hasMoreTokens())
            INPUT_STREAM.append(STRING_TOKENIZER.nextToken());
        while (STRING_TOKENIZER.hasMoreTokens())
            INPUT_STREAM.append(' ').append(STRING_TOKENIZER.nextToken());
        return INPUT_STREAM.length() == 0 ? null : INPUT_STREAM.toString();
    }
    static void startTime() {
        TIME_COMPLEXITY = System.currentTimeMillis();
    }
    static long getTime() {
        return System.currentTimeMillis() - TIME_COMPLEXITY;
    }
    static void flush() {
        System.out.print(TO_BE_PRINTED.toString());
        TO_BE_PRINTED.setLength(0);
    }
    static void out(Object o) {
        TO_BE_PRINTED.append(o);
        if (AUTO_FLUSH)
            flush();
    }
    static void _log(String s) {
        System.err.print(s);
    }
    static void _logln(String s) {
        System.err.println(s);
    }
    static void _logln() {
        System.err.println();
    }
    static void outln(Object o) {
        out(o);
        outln();
    }
    static void outln() {
        out("\n");
    }
    static class Pair implements Comparable<Pair> {
        public int a, b;
        public Pair(int a, int b) {
            this.a = a;
            this.b = b;
        }
        public static Pair of(int a, int b) {
            return new Pair(a, b);
        }
        @Override
        public int compareTo(Pair p) {
            if (a == p.a)
                return Integer.compare(b, p.b);
            return Integer.compare(a, p.a);
        }
        @Override
        public String toString() {
            return "[" + a + "," + b + "]";
        }
        public boolean equals(Pair p) {
            return p.a == a && p.b == b;
        }
    }
    static void logArr(Object val) {
        if (ONLINE_JUDGE)
            return;
        Class<?> valKlass = val.getClass();
        Object[] outputArray = null;
        for(Class<?> arrKlass : new Class<?>[] { int[].class, float[].class, double[].class, boolean[].class, 
            byte[].class, short[].class, long[].class, char[].class }) {
            if (valKlass.isAssignableFrom(arrKlass)) {
                int arrlength = Array.getLength(val);
                outputArray = new Object[arrlength];
                for(int i = 0; i < arrlength; ++i)
                    outputArray[i] = Array.get(val, i);
                break;
            }
        }
        if(outputArray == null)
            outputArray = (Object[])val;
        logArr0(outputArray);
    }
    static void logArr0(Object[] objs) {
        if (ONLINE_JUDGE)
            return;
        if (objs.length == 0) {
            _log("* \n");
            return;
        }
        _log("* " + objs[0]);
        for (int i = 1; i < objs.length; i++)
            _log(objs[i].toString().equals("\n") ? "\n>" : (" " + objs[i]));
        _logln();
    }
    static void log(Object... objs) {
        if (ONLINE_JUDGE)
            return;
        logArr0(objs);
    }
    static String next() {
        return tokenize() ? STRING_TOKENIZER.nextToken() : null;
    }
    static boolean tokenize() {
        if (STRING_TOKENIZER == null || !STRING_TOKENIZER.hasMoreTokens()) {
            try {
                STRING_TOKENIZER = new StringTokenizer(STREAM_READER.readLine());
            } catch (Exception _e) {
                return false;
            }
        }
        return true;
    }
    static long TIME_COMPLEXITY;
    static BufferedReader STREAM_READER = new BufferedReader(new InputStreamReader(System.in), 32768);
    static StringTokenizer STRING_TOKENIZER;
    static StringBuilder INPUT_STREAM = new StringBuilder(), TO_BE_PRINTED = new StringBuilder();
    //#endregion
}