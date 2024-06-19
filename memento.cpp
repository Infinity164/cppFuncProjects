#include <iostream>
#include <stack>
using namespace std;

class Memento {
private:
    string state;
public:
    Memento(string state) : state(state){}
    string getState() { return state; }
};

class TextEditor {
private:
    string text;
public:
    void setText(string newtext) { text = newtext; }
    string getText() { return text; }
    Memento save() { return Memento(text); }
    void restore(Memento memento) { text = memento.getState(); }
};

class Caretaker {
private:
    stack<Memento> history;
public:
    void save(const Memento& memento) { history.push(memento); }
    Memento undo() {
        if (history.empty()) throw out_of_range("No states to undo!");
        Memento memento = history.top();
        history.pop();
        return memento;
    }
};

int main()
{
    TextEditor editor;
    Caretaker caretaker;
    editor.setText("First bebra");
    caretaker.save(editor.save());
}