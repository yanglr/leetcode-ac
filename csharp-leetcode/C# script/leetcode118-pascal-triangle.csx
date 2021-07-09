#r "nuget: NUnit, 3.12.0"
#r "nuget: NUnitLite, 3.12.0"
using NUnit.Framework;
using NUnitLite;

class Solution {
    public IList<IList<int>> Generate (int numRows) {
        var results = new List<IList<int>> (numRows);
        if (numRows > 0)
            results.Add(new [] { 1 });

        for (int i = 1; i < numRows; i++) {
            var preRow = results[i - 1];
            var row = new int[i + 1];

            results.Add (row);
            row[0] = row[i] = 1;
            for (int j = 1; j < row.Length - 1; j++) {
                row[j] = preRow[j - 1] + preRow[j];
            }
        }
        return results;
    }
}

public class MyTests {
    [Test]
    public void Test()
    {
        Solution sol = new Solution();
        sol.Generate (3);
    }
}

new AutoRun().Execute (Args.ToArray ());