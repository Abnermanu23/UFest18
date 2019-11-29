
// C++ implementation of search and insert 
// operations on Trie 
#include <bits/stdc++.h> 
using namespace std; 
  
const int ALPHABET_SIZE = 10; 
  
// trie node 
struct TrieNode 
{ 
    struct TrieNode *children[ALPHABET_SIZE]; 
  
    // isEndOfWord is true if the node represents 
    // end of a word 
    bool isEndOfWord; 
}; 
  
// Returns new trie node (initialized to NULLs) 
struct TrieNode *getNode(void) 
{ 
    struct TrieNode *pNode =  new TrieNode; 
  
    pNode->isEndOfWord = false; 
  
    for (int i = 0; i < ALPHABET_SIZE; i++) 
        pNode->children[i] = NULL; 
  
    return pNode; 
} 
  
// If not present, inserts key into trie 
// If the key is prefix of trie node, just 
// marks leaf node 
void insert(struct TrieNode *root, string key) 
{ 
    struct TrieNode *pCrawl = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - '0'; 
        //printf("%d\n", index);
        if (!pCrawl->children[index]) 
            pCrawl->children[index] = getNode(); 
  
        pCrawl = pCrawl->children[index]; 
    } 
  
    // mark last node as leaf 
    pCrawl->isEndOfWord = true; 
} 
  
// Returns true if key presents in trie, else 
// false 
bool search(struct TrieNode *root, string key) 
{ 
    struct TrieNode *pCrawl = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - '0'; 
        //printf("search index: %d\n", index);
        if (!pCrawl->children[index]) 
            return false; 
  
        pCrawl = pCrawl->children[index]; 
    } 
  
    return (pCrawl != NULL && pCrawl->isEndOfWord); 
} 
  
// Driver 
int main() 
{ 
    // Input keys (use only 'a' through 'z' 
    // and lower case) 
    // string keys[] = {"5555555555", "5548484290", "2323458987", 
    //                 "1234567890", "1010101010", "7777777777", 
    //                  "7777777373", "0000000000" }; 

    vector<string> keys;

    keys.push_back("5555555555"); 
    keys.push_back("5548484290"); 
    keys.push_back("2323458987"); 
    keys.push_back("1234567890"); 
    keys.push_back("1010101010"); 
    keys.push_back("7777777777"); 
    keys.push_back("7777777373");
    keys.push_back("0000000000");
     

    //int n = sizeof(keys)/sizeof(keys[0]); 
    // printf("%ld\n", sizeof(keys));
    // printf("%ld\n", sizeof(keys[0]));
    // printf("%d\n", n);

    int n = keys.size(); 

    printf("%d\n", n);
 
    struct TrieNode *root = getNode(); 
  
    // Construct trie 
    for (int i = 0; i < n; i++) 
        insert(root, keys[i]); 
  
    // Search for different keys 
    search(root, "5555555555")? cout << "Yes\n" : 
                         cout << "No\n"; 
    search(root, "1010101010")? cout << "Yes\n" : 
                           cout << "No\n"; 
    search(root, "1234567890")? cout << "Yes\n" : 
                           cout << "No\n"; 
    search(root, "1234867890")? cout << "Yes\n" : 
                           cout << "No\n"; 

    return 0; 
} 
