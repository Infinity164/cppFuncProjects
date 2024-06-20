#include <iostream>
#include <vector>
using namespace std;

class HTMLelement;
class XMLelement;

class Visitor {
public:
	virtual ~Visitor() = default;
	virtual void visit(HTMLelement* element) = 0;
	virtual void visit(XMLelement* element) = 0;
};

class Element {
public:
	virtual ~Element() = default;
	virtual void accept(Visitor* visitor) = 0;
};

class HTMLelement : public Element {
public:
	void accept(Visitor* visitor) { visitor->visit(this); }
	string getHTML() { return "<html><body>Hello, world!<body><html>"; }
};

class XMLelement : public Element {
public:
	void accept(Visitor* visitor) { visitor->visit(this); }
	string getXML() { return "<xml><message>Hello, world!<message><xml>"; }
};

class PrintVisitor : public Visitor {
public:
	void visit(HTMLelement* element) { cout << "HTML Content: " << element->getHTML() << endl; }
	void visit(XMLelement* element) { cout << "XML Content: " << element->getXML() << endl; }
};

class Document {
private:
	vector<Element*> elements;
public:
	~Document() { for (auto element : elements) delete element; }
	void addElement(Element* element) { elements.push_back(element); }
	void accept(Visitor* visitor) { for (auto element : elements) element->accept(visitor); }
};
int main()
{
	Document doc1;
	doc1.addElement(new XMLelement);
	doc1.addElement(new HTMLelement);

	PrintVisitor pv;
	doc1.accept(&pv);
}