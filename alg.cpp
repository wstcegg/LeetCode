#include <cstdlib>
#include <time.h>

#include <windows.h>

#include <vector>
#include <stack>
#include <queue>
#include <string>

#include <functional>
#include <utility>
#include <map>
#include <set>
#include <unordered_map>

#include <iostream>
#include <sstream>
#include <algorithm>


using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head)
	{
		if (!head) return NULL;

		ListNode H(-1);
		H.next = head;

		ListNode *p1, *p2;
		p1 = p2 = &H;
		int preVal = head->val + 1;
		while (p2->next)
		{
			if ( (p2->next->val != preVal))
			{
				if (p1 != p2) p1->next = p2->next;
				preVal = p2->next->val;
			}
			else
			{
				p2 = p2->next;
			}

		}
		return H.next;
	}
};


int main()
{
	Solution s;
	return 0;
}




//for (int i = 0; i < 100; ++i)
//{
//	srand(time(NULL));
//	vector<int> nums_backup;
//	set<int> vals;
//	while (vals.size() < i) vals.insert(rand() % (10 * i));
//	for (int v : vals) nums_backup.push_back(v);
//
//	for (int j = 0; j < i; ++j)
//	{
//		vector<int> nums(nums_backup);
//		fill(nums.begin(), nums.begin() + j, nums[j]);
//
//		int res = s.search_right(nums, nums[j]);
//		printf("searching for %d at position: %d\t", nums[j], j);
//		if (res == j)
//			printf("[succeed!]\n");
//		else
//			printf("bin search res %d at position: %d\n", nums[res], res);
//	}
//
//	//for (int j = i - 1; j >= 0; --j)
//	//{
//	//	vector<int> nums(nums_backup);
//	//	fill(nums.begin()+j, nums.end(), nums[j]);
//
//	//	int res = s.search_left(nums, nums[j]);
//	//	printf("searching for %d at position: %d\t", nums[j], j);
//	//	if (res == j)
//	//		printf("[succeed!]\n");
//	//	else
//	//		printf("bin search res %d at position: %d\n", nums[res], res);
//	//}
//}