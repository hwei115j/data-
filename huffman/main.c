#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "huffman.h"

#if 0
int main()
{
    uint32_t stati[UNIT];
    uint32_t code[UNIT];
    node *root;

    file_in(stati);
    root = set_tree(stati);
    coding(root, code);
    file_out(root, code);

    return 0;
}
#endif
void test(node *top)
{
    printf("node = %p p = %011p l = %011p r = %011p data = %d\n"\
            , top, top->parent, top->child_l, top->child_r, top->data);
    if(top->child_l != NULL)
        test(top->child_l);
    if(top->child_r != NULL)
        test(top->child_r);
}
int main()
{
    uint32_t dic[UNIT] = {};
    uint32_t dic_1[UNIT] = {};
    uint32_t stati[UNIT] = {};
    char reg[UNIT] = {};

    node *root;

    file_in(stati);
    memcpy(dic, stati, sizeof(stati));
    memcpy(dic_1, stati, sizeof(stati));
    //mcp(dic, stati)
    root = set_root(stati);
    //test(root);
    coding(root, dic, dic_1, &reg[1]);
    for(int i = 'a'; i <= 'z'; i++)
        printf("%c = %d\n", i, dic_1[i]);
    //file_out(root, code);

    return 0;
}
