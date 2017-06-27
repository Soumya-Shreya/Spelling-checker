#include<string>
using namespace std;

/*
class implementing the tries data structure
*/

class tries
{
    bool value;     //marker to indicate leaf node
    tries* pointers[26];    //pointers to the various characters of english alphabet

public:
    tries()
    {
        //initialises all pointers as null
        value = 0;
        for(int i =0 ; i<26; i++)
            pointers[i] = NULL;
    }

    //This function adds a word to the trie
    void add(string s);

    //This function searches a word in the trie
    bool searchtries(string word, int i);

    //This function deletes a word from the trie
    void deletetries();

};

//A class representing dictionary
class dictionary
{
public:
    char* dict; //contains the file name for text file containing the dictionary words
    tries* root;    //a pointer to the trie
    dictionary(char* file)
    {
        dict = file;
        root = NULL;
    }

    //This is used to load the words from the file to memory. Returns true if the operation is successful, else false
    bool load();

    //This is used to free the memory used by the trie data structure
    void unload();

    //This checks the given word in the dictionary file and returns true if present else false;
    bool check(string word);
};
