using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Leetcode226_Invert_binary_tree
{
    class Program
    {
        // Definition for a binary tree node.
        //public class TreeNode
        //{
        //    public int val;
        //    public TreeNode left;
        //    public TreeNode right;
        //    public TreeNode(int x) { val = x; }
        //}
        public class Solution
        {
            public TreeNode InvertTree(TreeNode root)
            {
                TreeNode p;
                p = root.left;                
                root.left = root.right;
                root.right = p;

                TreeNode left = InvertTree(root.left);
                TreeNode right = InvertTree(root.right);
                return root;
            }
        }

        static void Main(string[] args)
        {
        }
    }
}
