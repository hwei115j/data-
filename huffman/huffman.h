#ifndef __HUFF_H_
#define __HUFF_H_
#define UNIT 256

typedef struct node
{
    int data;
    struct node *parent, *child_l, *child_r;
    struct node *next;
}node;

void coding(node *, uint32_t *, char (*)[10]);
node *set_root(uint32_t *);
node *sort_node(node *);
node *init_list(uint32_t *, size_t);
node *new_node(void);
node *add_node(node *, node *);
node *insert_list(node *);
void file_in(uint32_t *);
void file_out(char (*)[10]);
void turn(char (*)[10]);
#endif
