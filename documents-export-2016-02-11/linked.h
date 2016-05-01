struct linked_node{
	int data;
	struct linked_node *next;
};


struct linked_node * create_list(void);
int addnode(int data, struct linked_node **head);
void showlist(struct linked_node *head);
int addnodetail(int data, struct linked_node **head);
int addnodeinplace(int data, struct linked_node **head);
int deletelist(int data, struct linked_node **head);
int removenode(struct linked_node **head, int *val);