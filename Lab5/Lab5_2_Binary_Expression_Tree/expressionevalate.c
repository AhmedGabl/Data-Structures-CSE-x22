#include <stdio.h>
#include <stdlib.h>

typedef struct operand operand;

struct operand
{
    struct operand *left;
    struct operand *right;
    char operand;
};

operand *add_node(char a)
{
    operand *node = (operand *)malloc(sizeof(operand));
    if (node == NULL)
    {
        exit(1);
    }
    node->operand = a;
    node->left = NULL;
    node->right = NULL;
    return node;
}

operand *add_left(operand *parent, char a)
{
    parent->left = add_node(a);
    return parent->left;
}

operand *add_right(operand *parent, char a)
{
    parent->right = add_node(a);
    return parent->right;
}

void postorder(operand *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%c", root->operand);
    }
}

int main()
{
    char t;
    char in[100000];

    scanf(" %s", in);
    int i = 0;

    operand *temp = NULL, *temp0 = NULL, *c_t= NULL , *c_t0 = NULL , *c = NULL ,*cc=NULL;

    while((*(in + i)) != '\0')
    {
        if (*(in + i) == '+' || *(in + i) == '-')
        {
            if (temp )//&& (temp0->operand == '*' || temp0->operand == '/' || temp0->operand == '%'))
            {
                if(temp->operand=='+'|| temp->operand=='-')
                {
                 
                c=add_node(*(in+i));
                c->left =  temp;
                add_right(temp0,t);
                //temp0->operand = *(in+i);
                temp = c;
                temp0 = c;
            }
            else
            
            {
                
                c=add_node((temp0->operand));
                c->left =  temp0->left;
                add_right(c,t);
                temp0->operand = *(in+i);
                temp0->left = c;
            }
            }
            else if (!temp)
            {
                temp = add_node(*(in + i));
                add_left(temp, t);
                temp0 = temp;
            }
            else
            {
                temp0 = add_right(temp0, *(in + i));
                add_left(temp0, t);
            }
        }
        else if (*(in + i) == '/' || *(in + i) == '*' || *(in + i) == '%')
        {
            if (!temp)
            {
                temp = add_node(*(in + i));
                add_left(temp, t);
                temp0 = temp;
            }
            else
            {
                temp0 = add_right(temp0, *(in + i));
                add_left(temp0, t);
            }
        }
        else if (*(in + i) == '(')
        {
            c_t0 = temp0;
            c_t = temp;
            temp0 = NULL;
            temp = temp0;
        }
        else if (*(in + i) == ')')
        {
            add_right(temp0,t);
            if(*(in+i+1) != '\0'&&c_t0 !=NULL)
            {
                cc=add_node(c_t0->operand);
                cc->left= c_t0->left;
                cc->right = temp;
                c_t0->operand = *(in+i+1);
                i++;
                c_t0->left = cc;

            }
            else if(c_t0 != NULL)
            {
                c_t0->right= temp;
                //printf("\nt ->%c \nt0 ->%c       %c\n",temp->operand,temp0->operand, c_t0->operand);

            }
            else
            {
                c_t = add_node(*(in+i+1));
                i++;
                c_t->left= temp;
                c_t0 = c_t;
            }
                
                temp = c_t;
                temp0 = c_t0;
            }

        else
        {
                t = *(in + i);
          //    printf("==>here%c\n",t);

            if (*(in + i + 1) == '\0'&& *(in+i) != ')' )//|| (*(in + i + 1) == ')' && *(in + i + 2) == '\0'))
            {
                add_right(temp0, t);
            }
        }
        i++;
    }

    postorder(temp);
    return 0;
}