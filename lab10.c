#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Trie structure
struct Trie
{
    int count;
    struct Trie*children[26];	
};

// Inserts the word to the trie structure
void insert(struct Trie **pTrie, char *word)
{
	struct Trie *recent = *pTrie;
    if (recent == NULL) {
        recent = (struct Trie *) malloc(sizeof(struct Trie));
        recent->count = 0;
        for (int i = 0; i < 26; i++) {
            recent->children[i] = NULL;
        }
        *pTrie = recent;
    }
    for (int i = 0; i < strlen(word); i++) {
        int index = word[i] - 'a';
        if (recent->children[index] == NULL) {
            recent->children[index] = (struct Trie *) malloc(sizeof(struct Trie));
            recent->children[index]->count = 0;
            for (int j = 0; j < 26; j++) {
                recent->children[index]->children[j] = NULL;
            }
        }
        recent = recent->children[index];
    }
    recent->count++;
}


int numberOfOccurances(struct Trie *pTrie, char *word) {
    if (pTrie == NULL) {
        return 0;
    }
    struct Trie *new = pTrie;
    for (int i = 0; i < strlen(word); i++) {
        int index = word[i] - 'a';
        if (new->children[index] == NULL) {
            return 0;
        }
        new = new->children[index];
    }
    return new->count;
}

// computes the number of occurances of the word
int numberOfOccurances(struct Trie *pTrie, char *word)
{
	if (pTrie == NULL) {
        return 0;
    }
    struct Trie *recent = pTrie;
    for (int i = 0; i < strlen(word); i++) {
        int index = word[i] - 'a';
        if (recent->children[index] == NULL) {
            return 0;
        }
        recent = recent->children[index];
    }
    return recent->count;

}

// deallocate the trie structure
struct Trie *deallocateTrie(struct Trie *pTrie)
{
	if (pTrie == NULL) {
        return NULL;
    }
    for (int i = 0; i < 26; i++) {
        pTrie->children[i] = deallocateTrie(pTrie->children[i]);
    }
    free(pTrie);
    return NULL;
}

// Initializes a trie structure
struct Trie *createTrie()
{
	int count;
	struct Trie*createTrie();
}

// this function will return number of words in the dictionary,
// and read all the words in the dictionary to the structure words
int readDictionary(char *filename, char **pInWords)
{
	int n;
	scanf("%d", &n);
	return n;
}

int main(void)
{
	char *inWords[256];
	
	//read the number of the words in the dictionary
	int numWords = readDictionary("dictionary.txt", inWords);
	for (int i=0;i<numWords;++i)
	{
		printf("%s\n",inWords[i]);
	}
	
	struct Trie *pTrie = createTrie();
	for (int i=0;i<numWords;i++)
	{
		insert(pTrie, inWords[i]);
	}
	// parse lineby line, and insert each word to the trie data structure
	char *pWords[] = {"notaword", "ucf", "no", "note", "corg"};
	for (int i=0;i<5;i++)
	{
		printf("\t%s : %d\n", pWords[i], numberOfOccurances(pTrie, pWords[i]));
	}
	pTrie = deallocateTrie(pTrie);
	if (pTrie != NULL)
		printf("There is an error in this program\n");
	return 0;
}