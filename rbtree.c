#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define BLACK 1
#define RED 0
#define MAX 1000


typedef struct rbnode{
    struct rbnode *right;
    struct rbnode *left;
    struct rbnode *parent;
    int value;
    int color;  //1 = black, o = red
}rbnode;

typedef struct rbroot{
    struct rbnode *root;
    struct rbnode *nil;  //NIL node
}rbroot;

void rb_insert(struct rbroot *rbtree, struct rbnode *new);
int print_tree(struct rbnode *rbroot, struct rbnode *nil);          
int rb_insert_fixup(struct rbroot *rbtree, struct rbnode *new);
void left_rotate(struct rbroot *rbtree, struct rbnode *new);
void right_rotate(struct rbroot *rbtree, struct rbnode *new);
struct rbnode *rb_search(struct rbroot *rbtree, int key);
struct rbnode *rb_delete(struct rbroot *rbtree, struct rbnode *delete_node);
struct rbnode *tree_successor(struct rbroot *rbtree, struct rbnode *node);
void rb_delete_fixup(struct rbroot *rbtree, struct rbnode *del_nod);


int main(void)
{
    int node_value[MAX];
    int i = 0, tmp;
    struct rbroot *rbtree = NULL;
    struct rbnode *new;
    int key;
    rbtree = malloc(sizeof(struct rbroot));
    rbtree->nil = malloc(sizeof(struct rbnode));
    rbtree->nil->color = BLACK;
    rbtree->nil->left = rbtree->nil->right = rbtree->nil->parent = rbtree->nil;
    rbtree->nil->value = 0;
    rbtree->root = rbtree->nil;
    while(scanf("%d", &tmp) != EOF)
    {
//        printf("tmp = %d\n", tmp);
        //insert into the rbtree
        new = malloc(sizeof(struct rbnode));
        new->value = tmp;
        new->left = new->right =new->parent = rbtree->nil;
        rb_insert(rbtree, new);

    }
    printf("tree: root: %d\n", rbtree->root->value);
    print_tree(rbtree->root, rbtree->nil);
    printf("search value:");
    while(scanf("%d", &key) != EOF)
    {
        new = rb_search(rbtree, key);
        if (new != rbtree->nil)
        {
            printf("we find it\n");
            rb_delete(rbtree, new);  
            printf("tree: root:%d\n", rbtree->root->value);
            print_tree(rbtree->root, rbtree->nil);
        }   
        else
            printf("we don't find it\n");
    }
    return 0;
}

struct rbnode *rb_search(struct rbroot *rbtree, int key)
{
    struct rbnode *node;
    node = rbtree->root;
    while(node != rbtree->nil && node->value != key)
    {
    //    printf("node->valu=%d, key=%d\n", node->value, key);
        if (node->value > key)
            node = node->left;
        else
            node = node->right;
    }
    return node;
}




void rb_insert(struct rbroot *rbtree, struct rbnode *new)
{
    struct rbnode *xnode = rbtree->root;
    struct rbnode *ynode = rbtree->nil;
    int tmp = new->value;
    //first insert the node into a suitable place in the tree
    while(xnode != rbtree->nil)
    {
        ynode = xnode;
        if (xnode->value < tmp)
            xnode = xnode->right;
        else
            xnode = xnode->left;
    }
    new->parent = ynode;
    if(ynode == rbtree->nil)
        rbtree->root = new;
    else
    {
        if (ynode->value < tmp)
            ynode->right = new;
        else
            ynode->left = new;
    }
    new->color = RED;
 //   if (new->parent != NULL)
    printf("%d's parent = %d\n",new->value, new->parent->value);
    rb_insert_fixup(rbtree, new);
}

int rb_insert_fixup(struct rbroot *rbtree, struct rbnode *new)
{
    struct rbnode *parent = new->parent;
    struct rbnode *grandparent = new->parent->parent;
    while (new->parent->color == RED)
    {
        if (new->parent == new->parent->parent->left)
        {
            if (new->parent->parent->right->color == RED)
            {
                new->parent->color = BLACK;
                new->parent->parent->color = RED;
                new->parent->parent->right->color = BLACK;
                new = new->parent->parent;
            }
            else
            {
                if (new == new->parent->right)
                {
                    new = new->parent;
                    left_rotate(rbtree, new);
                }
                new->parent->color = BLACK;
                new->parent->parent->color = RED;
                right_rotate(rbtree, new->parent->parent);
            }   
        }
        else if(new->parent == new->parent->parent->right)
        {
            if (new->parent->parent->left->color == RED)
            {
                new->parent->color = BLACK;
                new->parent->parent->color = RED;
                new->parent->parent->left->color = BLACK;
                new = new->parent->parent;
            }
            else
            {
                if (new == new->parent->left)
                {
                    new = new->parent;
                    right_rotate(rbtree, new);
                }
                new->parent->color = BLACK;
                new->parent->parent->color = RED;
                left_rotate(rbtree, new->parent->parent);
            }
        }
    }
    rbtree->root->color = BLACK;
    return 0;
}

void left_rotate(struct rbroot *rbtree, struct rbnode *new)
{
    struct rbnode *x = new;
    struct rbnode *y = new->right;
    x->right = y->left;
    if (y->left != rbtree->nil)
        y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == rbtree->nil) //x is the root
        rbtree->root = y;
    else
        if (x == x->parent->left) //x is left node
            x->parent->left = y;  //change x's parent point
        else
            x->parent->right = y;
    y->left = x;
    x->parent = y;
}

void right_rotate(struct rbroot *rbtree, struct rbnode *new)
{
    struct rbnode *x = new;
    struct rbnode *y = new->left;
    x->left = y->right;
    if (y->right != rbtree->nil)
        y->right->parent = x;
    y->parent = x ->parent;
    if (x->parent == rbtree->nil)
        rbtree->root = y;
    else
        if (x->parent->right == x)
            x->parent->right = y;
        else
            x->parent->left = y;
    y->right = x;
    x->parent = y;
}

struct rbnode *rb_delete(struct rbroot *rbtree, struct rbnode *delete_node)
{
    struct rbnode *tmp;
    struct rbnode *del_nod;
    if (delete_node->right == rbtree->nil || delete_node->left == rbtree->nil)
        del_nod = delete_node;
    else
        del_nod = tree_successor(rbtree, delete_node);
    if (del_nod->left != rbtree->nil)
        tmp = del_nod->left;
    else
        tmp = del_nod->right;
    tmp->parent = del_nod->parent;
    if (del_nod->parent == rbtree->nil)
        rbtree->root = tmp;
    else
        if (del_nod->parent->left == del_nod)
            del_nod->parent->left = tmp;
        else
            del_nod->parent->right = tmp;
    if (del_nod != delete_node)
        delete_node->value = del_nod->value;
    if (del_nod->color == BLACK)
    {
        printf("del_nod %d %d\n", del_nod->value, del_nod->color);
        rb_delete_fixup(rbtree, tmp);
    }
    return del_nod;
}

struct rbnode *tree_successor(struct rbroot *rbtree, struct rbnode *node)
{
    struct rbnode *tmp;
    if (node->right != rbtree->nil)
    {
        tmp = node->right;
        while(tmp->left != rbtree->nil)
            tmp = tmp->left;
        return tmp;
    }
    tmp = node->parent;
    while (tmp != rbtree->nil && node == tmp->right)
    {
        node = tmp;
        tmp = tmp->parent;
    }
    return tmp;
}

void rb_delete_fixup(struct rbroot *rbtree, struct rbnode *del_nod)
{
    struct rbnode *sibling;
    while (del_nod != rbtree->root && del_nod->color == BLACK)
    {
        if (del_nod->parent->left == del_nod)
        {
            printf("if left\n");
            sibling = del_nod->parent->right;
            if (sibling->color == RED)
            {
                sibling->color = BLACK;
                sibling->parent->color = RED;
                left_rotate(rbtree, sibling->parent);
                sibling = del_nod->parent->right;
            }
            if (sibling->right->color == BLACK && sibling->left->color == BLACK)
            {
                sibling->color = RED;
                del_nod = del_nod->parent;
            }
            else
            {
                if (sibling->right->color == BLACK)
                {
                    sibling->left->color = BLACK;
                    sibling->color = RED;
                    right_rotate(rbtree, sibling);
                    sibling = sibling->parent;
                }
                //right child is RED
                sibling->color = del_nod->parent->color;
                del_nod->parent->color = BLACK;
                sibling->right->color = BLACK;
                left_rotate(rbtree, del_nod->parent);
                del_nod = rbtree->root;
            }
        }
        else
        {
            printf("else right\n");
            sibling = del_nod->parent->left;
            printf("sibling %d %d\n",sibling->value, sibling->color);
            if (sibling->color == RED)
            {
                sibling->color = BLACK;
                sibling->parent->color = RED;
                right_rotate(rbtree, sibling->parent);
                sibling = del_nod->parent->left;
            }
            if (sibling->left->color == BLACK && sibling->right->color == BLACK)
            {
                sibling->color = RED;
                del_nod = del_nod->parent;
            }
            else
            {
                if (sibling->left->color == BLACK)
                {
                    sibling->right->color = BLACK;
                    sibling->color = RED;
                    left_rotate(rbtree, sibling);
                    sibling = sibling->parent;
                }
                printf("sibling:%d %d\n",sibling->value, sibling->color);
                sibling->color = del_nod->parent->color;
                del_nod->parent->color = BLACK;
                sibling->left->color = BLACK;
                right_rotate(rbtree, del_nod->parent);
                del_nod = rbtree->root;
            }
        }
    }
    del_nod->color = BLACK;  
}




int print_tree(struct rbnode *rbroot, struct rbnode *nil)
{
    struct rbnode *left = rbroot -> left;
    struct rbnode *right = rbroot -> right;
   // printf("%d %d\n", rbroot->value, rbroot->color);
    if (left != nil)
        print_tree(left, nil);
    printf("%d %d parent:%d\n", rbroot->value, rbroot->color,rbroot->parent->value);
    if (right != nil)
        print_tree(right, nil);
    return 0;
}



