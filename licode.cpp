#include <iostream>
#include <vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution2
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *l = new ListNode(0);
        ListNode *p = l1;
        ListNode *q = l2;
        ListNode *r = l;
        bool up = false;
        while (p != NULL || q != NULL)
        {
            int i = p->val + q->val + up;
            r->val = i % 10;
            up = (i >= 10);
            p = p->next;
            q = q->next;

            if (p != NULL || q != NULL || up)
            {
                if (p == NULL)
                    p = new ListNode();
                if (q == NULL)
                    q = new ListNode();
                r->next = new ListNode(1);
                r = r->next;
            }
        }
        return l;
    }
};
class Solution259
{
public:
    int distMoney(int money, int children)
    {
        if (money < children)
        {
            return -1;
        }
        money -= children;
        for (int i = 1; i <= children; i++)
        {
            money -= 7;
            if (money == 3 && i == children - 1)
            {
                return i - 1;
            }
            if (money < 0)
            {
                return i - 1;
            }
            if (money == 0)
            {
                return i;
            }
            if (money > 0 && i == children)
            {
                return children - 1;
            }
        }

        return -1;
    }
};
class Solution234
{
public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *h = head;
        int len = 0;
        char *c = new char[100];
        while (h != NULL)
        {
            len++;
            c[len - 1] = h->val;
            h = h->next;
        }
        for (int i = 0; i <= len / 2; i++)
        {
            if (c[i] != c[len - 1 - i])
            {
                return false;
            }
        }
        return true;
    }
};
class Solution21
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *p = list1;
        ListNode *q = list2;
        ListNode *l = new ListNode();
        while (p != NULL || q != NULL)
        {
            if ((p == NULL && q != NULL) || p->val >= q->val)
            {
                l->next = new ListNode(q->val);
                if (q->next != NULL)
                    q = q->next;
            }
            if ((q == NULL && p != NULL) || q->val >= p->val)
            {
                l->next = new ListNode(p->val);
                if (p->next != NULL)
                    p = p->next;
            }
        }
        return l;
    }
};
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == nums[i + 1])
            {
                nums.erase(nums[i + 1]);
            }
        }
    }
};
class Solution66
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            int count = 1;
            int sum = digits[i] + count;

            digits[i] = sum % 10;
            if (sum >= 10)
            {
                count = 1;
                if (i == 0)
                {
                    digits.insert(digits.begin(), 1);
                }
            }
            else
            {
                count = 0;
                break;
            }
        }
        return digits;
    }
};
//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution144
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> alist;
        if (root != NULL)
        {
            alist.push_back(root->val);
            // 递归遍历左子树，并将结果合并到数组中
            vector<int> left_list = preorderTraversal(root->left);
            alist.insert(alist.end(), left_list.begin(), left_list.end());

            // 递归遍历右子树，并将结果合并到数组中
            vector<int> right_list = preorderTraversal(root->right);
            alist.insert(alist.end(), right_list.begin(), right_list.end());
        }
        return alist;
    }
};
class Solution145
{
public:
    void order(TreeNode *root, vector<int> &list)
    {
        if (root == NULL)
        {
            return;
        }
        order(root->left, list);
        order(root->right, list);
        list.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> list;
        order(root, list);
        return list;
    }
};
class Solution94
{
public:
    void order(TreeNode *root, vector<int> &list)
    {
        if (root == NULL)
        {
            return;
        }
        order(root->left, list);
        list.push_back(root->val);
        order(root->right, list);
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> list;
        order(root, list);
        return list;
    }
};
class Solution100
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q == nullptr)
        {
            return true;
        }
        else if (p == nullptr || q == nullptr)
        {
            return false;
        }
        else if (p->val != q->val)
        {
            return false;
        }
        else
        {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
    }
};
class Solution101
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q == nullptr)
        {
            return true;
        }
        else if (p == nullptr || q == nullptr)
        {
            return false;
        }
        else if (p->val != q->val)
        {
            return false;
        }
        else
        {
            return isSameTree(p->left, q->right) && isSameTree(p->right, q->left);
        }
    }
    bool isSymmetric(TreeNode *root)
    {
        return isSameTree(root->left, root->right);
    }
};
class Solution83
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {

        ListNode *q = head;

        if (head != NULL)
        {
            int a = q->val;
            ListNode *p = head->next;
            while (p != NULL)
            {
                if (p->val != a)
                {
                    a = p->val;
                    q->next = p;
                    q = p;
                }
                p = p->next;
            }
            q->next = NULL;
        }

        return head;
    }
};
class Solution27
{
public:
    class Solution
    {
    public:
        int removeElement(vector<int> &nums, int val)
        {
            int left = 0, right = nums.size();
            while (left < right)
            {
                if (nums[left] == val)
                {
                    nums[left] = nums[right - 1];
                    right--;
                }
                else
                {
                    left++;
                }
            }
            return left;
        }
    };
};
class Solution104
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
class Solution206
{
public:
    // 迭代
    ListNode *reverseList(ListNode *head)
    {
        ListNode *pre = NULL;
        ListNode *cur = head;
        ListNode *next;
        while (cur)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }

    // 递归法
    class Solution
    {
    public:
        ListNode *reverseList(ListNode *head)
        {
            if (!head || !head->next)
            {
                return head;
            }
            // 通过递归获取最后一个节点（也就是反转后的头节点）
            ListNode *newHead = reverseList(head->next);
            head->next->next = head;
            head->next = nullptr;
            return newHead;
        }
    };
};
class Solution88
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int p = 0, q = 0;
        int sorted[m + n];
        int i = 0;
        while (p < m || q < n)
        {
            if (p ==m )
            {
                sorted[i] = nums2[q];
                q++;
            }
            else if (q== n){
                sorted[i] = nums1[p];
                p++;
            }
            else if (nums1[p]<= nums2[q]){
                sorted[i] = nums1[p];
                p++;
            }
            else if (nums1[p] > nums2[q])
            {
                sorted[i] = nums2[q];
                q++;
            }
            i++;
        }
        for (int i = 0; i != m + n; ++i)
        {
            nums1[i] = sorted[i];
        }
    }
};
