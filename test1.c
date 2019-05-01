//删除链表中所有值为val的节点
//代码片段
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
typedef struct ListNode Node;

struct ListNode* removeElements(struct ListNode* head, int val) {
	if (head == NULL) {
		return NULL;
	}
	Node* pCur = head;
	Node* pPre = NULL;
	while (pCur) {
		if (pCur->val == val) {
			if (pPre == NULL) {
				head = pCur->next;
				free(pCur);
				pCur = head;
			}
			else {
				pPre->next = pCur->next;
				free(pCur);
				pCur = pPre->next;
			}
		}
		else {
			pPre = pCur;
			pCur = pCur->next;
		}
	}
	return head;
}

