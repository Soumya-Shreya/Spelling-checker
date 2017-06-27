#include"dictionary.h"
#include<fstream>
#include<string>
#include<iostream>
using namespace std;

void tries::add(string s)
{
    tries* trav = this;
    for(int i = 0; i<s.length(); i++)
    {
        int pos = tolower(s[i]-'a');
        if(trav->pointers[pos]==NULL)
            trav->pointers[pos] = new tries;
        trav = trav->pointers[pos];
    }

    trav->value = true;
}

bool tries::searchtries(string word, int i)
{
    if(i==word.length())
        return value;
    if(pointers[tolower(word[i])-'a']==NULL)
        return false;
    return pointers[tolower(word[i])-'a']->searchtries(word,i+1);
}

void tries::deletetries()
{
    for(int i = 0; i<26; i++)
    {
        if(pointers[i]!=NULL)
            pointers[i]->deletetries();
    }
    delete this;
}

bool dictionary::load()
{
    fstream f;
    f.open(dict,ios::in);
    if(!f.is_open())
    {
        return false;
    }

    root = new tries;
    string str;

    while(!f.eof())
    {
        f>>str;
        root->add(str);
    }

    f.close();
    return true;
}

bool dictionary::check(string word)
{
    return root->searchtries(word,0);
}


void dictionary::unload(void)
{
    root->deletetries();
}
