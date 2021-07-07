public class Solution {
    public bool IsNumber (string s) {
        s = s.Trim ();
        if (s.Contains ("Infinity") || s.Contains ("infinity")) return false;

        string[] arr = s.Split (new char[] { 'e', 'E' });
        string newPart1 = arr[0];
        if (newPart1.IndexOf (" ", StringComparison.Ordinal) >= 0)
            return false;
        bool isPart1Double = double.TryParse (newPart1, out var part1);
        string newPart2 = arr.ElementAtOrDefault (1);
        if (newPart2 == String.Empty) // handle test case like: "0e"
            return false;

        if (newPart2 != String.Empty && newPart2 != null) {
            char ch = newPart2[0];
            if (ch == '.' || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) 
                return false; /* 检测类似 69e.60, 3.31ec250这样的数字。字母检查也可使用Char.IsLetter(char) */
        }

        if (newPart2 != null) {
            foreach (char ch in newPart2) {
                if (ch == '0')
                    newPart2 = newPart2.Substring (1);
            }
        }

        bool isPart2Int = Int64.TryParse (newPart2, out var part2);
        if (arr.Length == 1) {
            if (isPart1Double)
                return true;
        }

        if (arr.Length == 2) {
            if (isPart1Double && newPart2 == String.Empty)
                return true;
            if (isPart1Double && isPart2Int)
                return true;
        }

        return false;
    }
}

void test () {
    var sol = new Solution ();

    var input = "2e00";
    Console.WriteLine (sol.IsNumber (input));

    input = "69e.60";
    Console.WriteLine (sol.IsNumber (input));

    input = "3.31ec250";
    Console.WriteLine (sol.IsNumber (input));

    input = "infinity";
    Console.WriteLine (sol.IsNumber (input));
}

test ();