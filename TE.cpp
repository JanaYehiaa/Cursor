#include <iostream>
#include <string> //for use of strings
using namespace std;

class Stack { //Stack ADT implemented using an array
    enum { Max = 100 };
private:
    char Items[Max];
    int top;
public:
    Stack() {
        top = -1;
    }
    bool isEmpty() const {
        return (top == -1);
    }
    bool push(const char& c) {
        if (top == (Max - 1)) return false;
        top++;
        Items[top] = c;
        return true;

    }
    bool pop(char& c) {
        if (isEmpty()) return false;
        c = Items[top];
        top--;
        return true;
    }
};

class TextEditor
{
private:
    Stack Left; //elements to left of cursor, a stack with letters of a word in reverse
    Stack Right; //elements to right of cursor, a stack with letters of a word in the correct order
    Stack temp; //a temporary stack to store characters
public:
    void insert(char c) {
        // insert value to the left of cursor
        Left.push(c);
    }
    void remove() {
        //remove to the left of cursor if exists
        if (!Left.isEmpty()) {
            char d;
            Left.pop(d);
        }
    }
    void left() {
        //if left stack is not empty, remove element from it and add it to right stack
        if (!Left.isEmpty()) {
            char m;
            Left.pop(m);
            Right.push(m);
        }
    }
    void right() {
        //if right stack is not empty, remove element from it and add it to left stack
        if (!Right.isEmpty()) {
            char m;
            Right.pop(m);
            Left.push(m);
        }
    }
    void getText() {

        char a;
        //handling left stack if exists
        if (!Left.isEmpty()) {
            while (!Left.isEmpty()) {
                Left.pop(a);
                temp.push(a);
            }
            while (!temp.isEmpty()) {
                temp.pop(a);
                cout << a;
                Left.push(a);
            }
        }
        //handling right stack if exists
        if (!Right.isEmpty()) {
            while (!Right.isEmpty()) {
                Right.pop(a);
                cout << a;
                temp.push(a);
            }
            while (!temp.isEmpty()) {
                temp.pop(a);
                Right.push(a);
            }
        }
        cout << '\n';
    }

};


int main() {
    TextEditor editor;

    // Insert characters
    editor.insert('H');     // H
    editor.insert('e');     // He
    editor.insert('l');     // Hel
    editor.insert('l');     // Hell
    editor.insert('o');     // Hello

    editor.getText();       // Should Print: Hello

    // Move the cursor left
    editor.left();
    editor.left();

    // Insert character at cursor
    editor.insert(',');     // Hel,lo

    editor.getText();       // Should Print: Hel,lo


    // Remove character before cursor
    editor.remove();        // Hello

    editor.getText();       // Should Print: Hello

    // Move cursor to the beginning
    editor.left();
    editor.left();
    editor.left();
    editor.left();

    // Attempt to remove from the beginning
    editor.remove();

    editor.getText();       // Should Print: Hello

    // Attempt to move cursor further left
    editor.left();

    editor.getText();       // Should Print: Hello

    // Move cursor to the end
    editor.right();
    editor.right();
    editor.right();
    editor.right();
    editor.right();

    // Remove character at the end
    editor.remove();        // Hell

    editor.getText();       // Should Print: Hell

    // Attempt to move cursor further right
    editor.right();

    // Print final text
    editor.getText();       // Should Print:  Hell

    editor.insert('o');     // Hello

    editor.getText();       // Should Print:  Hello
    
    return 0;
}

