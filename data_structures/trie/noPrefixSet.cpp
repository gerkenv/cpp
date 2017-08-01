#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

class Node {
    map<char,Node*> chars;

    public:
    
    bool add( string word, int index ) {
        if ( index >= word.length() ) { return false; }
        map<char,Node*>::iterator it = chars.find( word[index] );
        if ( chars.end() == it )
        { 
            chars[word[index]] = new Node(); 
            return chars[word[index]]->add( word, index+1 );
        }
        else
        {
            return (*it).second->isPrefix( word, index+1 );
        }
    }
    
    bool isPrefix( string word, int index ) {
        if ( index == word.length() ) {
            return true;
        }
        else {
            if (chars.size() == 0) return true;
        }
        return add( word, index );
    }
    
};


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int quantity;
    cin >> quantity;
    Node *origin = new Node();
    string input;
    for ( int i = 0; i < quantity; i++ )
    {
        cin >> input;
        if ( true == origin->add( input, 0 ) )
        {
            cout << "BAD SET\n" << input;
            return 0;
        }
    }
    cout << "GOOD SET";
    return 0;
}
