/**
A simple spell checker

Soumya Shreya

Change the macro definition of DICTIONARY as the filename in which you have saved your words
*/

#include <iostream>
#include "dictionary.h"
#include <fstream>
#include <cstdlib>
#include <conio.h>
#define DICTIONARY "dictionary.txt"     //put the name of file representing the dictionary here

using namespace std;

/*
This function asks the user for a file name and checks that file for misspelled words
*/

void checkfile()
{
    system("cls");

    //loading the dictionary from file in the memory
    dictionary d(DICTIONARY);

    if(!d.load())
    {
        cout<<"could not load dictionary";
        return;
    }


    char text[80];  //stores the name of the file to be checked

    cout<<"Enter the name of file ";
    cin>>text;

    fstream f;
    f.open(text,ios::in);

    if(!f.is_open())
    {
        cout<<"could not open file";
        //free up memory acquired by the dictionary words if the file does not exist
        d.unload();
        return;
    }

    cout<<"MISSPELLED WORDS: ";

    string word;
    f>>word;

    while(!f.eof())
    {
        //Each word is checked against the set of words stored in dictionary and wrong words are printed out
        bool misspelled = !d.check(word);
        if(misspelled)
            cout<<word<<endl;
        f>>word;
    }

    f.close();
    getch();
}

/*
This function saves the file typed by user. User signals the end of file by typing EXITTYPING
*/

void writefile()
{
    system("cls");
    char filename[80];  //stores the name of the file to be saved


    fstream f;
    char flag = 'y';

    //take the name of file from user and if that file already exists ask if he/she wants to replace it
    do
    {
        flag = 'y';
        cout<<"save as filename(spaces not allowed):\t";
        cin>>filename;

        f.open(filename,ios::in);
        if(f.is_open())
        {
            cout<<"File already exists\nDo you want to replace it?(y/n)\t";
            cin>>flag;
            f.close();
        }
    }while(flag=='n');

    f.open(filename,ios::out);
    if(!f.is_open())
    {
        cout<<"could not open file";
        return;
    }
    cout<<"Enter text, type EXITTYPING and press enter to end file\n";

    //taking the words from console and printing it in the file
    string word;
    cin>>word;
    while(word.compare("EXITTYPING"))
    {
        f<<word<<" ";
        cin>>word;
    }
    f.close();
    cout<<"File saved!";
    getch();
}

/*
This funciton adds a word to the dictionary
*/

void addword()
{
    system("cls");
    cout<<"Enter the word you wish to add\n";
    string word;
    cin>>word;

    ofstream f;
    f.open(DICTIONARY,ios::app);
    if(!f.is_open())
        cout<<"could not open"<<DICTIONARY;
    f<<word<<"\n";

    cout<<"Added!";
    getch();
}

int main()
{
    /*The program gives a menu to user where he/she can choose either to
      check an existing file,
      create a new file or
      to add a word in the dictionary
    */
    while(1)
    {
        system("cls");
        cout<<"Enter your choice\n";
        cout<<"1. Check a file\n2. Write a file\n3. Add word to dictionary\n4. Exit\n";

        char  choice;

        choice = getch();
        switch(choice)
        {
        case '1':
            checkfile();
            break;
        case '2':
            writefile();
            break;
        case '3':
            addword();
            break;
        case '4':
            return 0;
        }
    }

    return 0;
}
