class Solution
{
private:
	int order;
	int addres;
public:

	Solution () :order (0) , addres (0){}

	void updateSum (ListNode* cur1 , ListNode* cur2)
	{
		addres = order;
		if ( cur1 != NULL )
			addres += cur1->val;
		if ( cur2 != NULL )
			addres += cur2->val;
		if ( addres >= 10 )
		{
			addres -= 10;
			order = 1;
		}
		else
			order = 0;
	}

	ListNode* insertList (ListNode* cur , int val)
	{
		ListNode* tmp = cur;
		cur = new ListNode (val);
		tmp->next = cur;
		return cur;
	}

	ListNode* addTwoNumbers (ListNode* l1 , ListNode* l2)
	{
		ListNode* r, *p, *q, *head;
		updateSum (l1 , l2);
		r = new ListNode (addres);

		head = r;

		p = l1->next , q = l2->next;
		for ( ; p != NULL || q != NULL; p = p == NULL ? p: p->next , q =q==NULL?q: q->next )
		{
			updateSum (p , q);
			r = insertList (r , addres);
		}
		if ( order != 0 )
		{
			r = insertList (r , 1);
		}
		return head;
	}
};