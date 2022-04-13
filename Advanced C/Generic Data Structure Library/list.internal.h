
/********************FunctionSignatures*******************/

static void PushNode(Node *_node, Node *_next);
static void PopNode(Node *_node);

/***********************structNode**********************/

struct Node
{
void* m_data;
struct Node *m_next;
struct Node *m_prev;
};

/***********************structList**********************/

struct List
{
Node m_head;
Node m_tail;
};


