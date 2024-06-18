#include <iostream>
#include <vector>
using namespace std;

class Observer {
public:
	virtual ~Observer() = default;
	virtual void update(string magazineIssue) = 0;
};

class Subject {
public:
	virtual ~Subject() = default;
	virtual void addObserver(Observer* observer) = 0;
	virtual void removeObserver(Observer* observer) = 0;
	virtual void notifyObservers() = 0;
};

class MagazinePublisher : public Subject {
private:
	vector<Observer*> observers;
	string latestIssue;
public:
	void addObserver(Observer* observer) override { observers.push_back(observer); }
	void removeObserver(Observer* observer) override { observers.erase(remove(observers.begin(), observers.end(), observer), observers.end()); }
	void notifyObservers() override { for (auto observer : observers) observer->update(latestIssue); }
	void releaseNewIssue(string issue) {
		latestIssue = issue;
		notifyObservers();
	}
};

class Subscriber : public Observer {
private:
	string name;
public:
	Subscriber(string name) : name(name) {}
	void update(string magazineIssue) { cout << "Subscriber " << name << " recive new magazine issue: " << magazineIssue << endl; }
};

int main()
{
	Subscriber* s1 = new Subscriber("John"); 
	Subscriber* s2 = new Subscriber("Martha");
	Subscriber* s3 = new Subscriber("Donald");

	MagazinePublisher m1;

	m1.addObserver(s1);
	m1.addObserver(s2);
	m1.addObserver(s3);

	m1.releaseNewIssue("Hello, world!");
}