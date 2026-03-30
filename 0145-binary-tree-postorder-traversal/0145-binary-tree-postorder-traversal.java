/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
List<Integer> ans = new ArrayList<>();
    public List <Integer> postorderTraversal(TreeNode root){
        solve(root);
        return ans;
    }
    public void solve (TreeNode node){
        if (node==null) return;
        

        solve(node.left);
        solve(node.right);
        ans.add(node.val);
    }
}