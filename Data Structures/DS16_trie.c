#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//implementing a trie with insert, search and delete word functions

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0]) // Alphabet size (# of symbols)
#define ALPHABET_SIZE (26) // Converts key current character into index 
#define CHAR_TO_INDEX(c) ((int)c - (int)'a') // use only 'a' through 'z' and lower case
// trie node
struct TrieNode{
    struct TrieNode *children[ALPHABET_SIZE];
    // isEndOfWord is true if the node represents
    // end of a word
    bool isEndOfWord;
};

bool isLeafNode(struct TrieNode* root){
    return root->isEndOfWord != false;
}

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void){
    struct TrieNode *pNode = NULL;
    pNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    if (pNode){
        int i;
        pNode->isEndOfWord = false;
        for (i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;
    }
    return pNode;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just marks leaf node
void insert(struct TrieNode *root, const char *key){
    int level;
    int length = strlen(key);
    int index;
    struct TrieNode *pCrawl = root;
    for (level = 0; level < length; level++){
        index = CHAR_TO_INDEX(key[level]);
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
        pCrawl = pCrawl->children[index];
    }
    // mark last node as leaf
    pCrawl->isEndOfWord = true;
}

// Returns true if key presents in trie, else false
bool search(struct TrieNode *root, const char *key){
    int level;
    int length = strlen(key);
    int index;
    struct TrieNode *pCrawl = root;
    for (level = 0; level < length; level++){
        index = CHAR_TO_INDEX(key[level]);
        if (!pCrawl->children[index])
            return false;
        pCrawl = pCrawl->children[index];
    }
    return (pCrawl != NULL && pCrawl->isEndOfWord);
}

bool isEmpty(struct TrieNode* root)
{
    int i;
    for (i = 0; i < ALPHABET_SIZE; i++){
        if (root->children[i])
            return false; }
    return true;
}

void display(struct TrieNode* root, char str[], int level){
    if (isLeafNode(root)){
        str[level] = '\0';
        printf("%s\n",str);
    }
    
    int i;
    for (i = 0; i < ALPHABET_SIZE; i++){
        if (root->children[i]){
            str[level] = i + 'a';
            display(root->children[i], str, level + 1);
        }
    }
}

struct TrieNode* delete(struct TrieNode* root, char* key, int depth)
{
    if (!root) // If tree is empty
        return NULL;
    
    // If last character of key is being processed         
    if (depth == strlen(key)) {
        // This node is no more end of word after removal of given key
        if (root->isEndOfWord)
            root->isEndOfWord = false;
            
        if (isEmpty(root)) {
            free(root);
            root = NULL;
        }
        
        return root;
    }
    
    // If not last character, recur for the child obtained using ASCII value
    int index = key[depth] - 'a';
    root->children[index] = delete(root->children[index], key, depth + 1);
    
    // If root does not have any child (its only child got deleted), and it is not end of another word
    if (isEmpty(root) && root->isEndOfWord == false) {
        free(root);
        root = NULL;
    }
    return root;
}

int main()
{
    char output[][32] = {"Not present in trie", "Present in trie"};
    struct TrieNode *root = getNode();
    char a[20], s[20], d[20];
    int f=1;
    while(f){
        printf("Enter the option\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        int c;
        scanf("%d", &c);
        switch(c){
            case 1:
                scanf("%s",a);
                insert(root,a);
                break;
            case 2:
                scanf("%s",s);
                printf("%s --- %s\n", s, output[search(root, s)] );
                break;
            case 3:
                scanf("%s",d);
                delete(root, d, 0);
                break;
            case 4:
                display(root,a,0);
                break;
            default: 
                f=0;
        }
    }
    return 0;
}
