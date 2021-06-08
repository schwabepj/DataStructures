#ifndef CIRCLELIST_H
#define CIRCLELIST_H

template <typename Object>
class CircleList {
public:
	CircleList();
	~CircleList();
	bool empty() const;
	const Object& front() const;
	const Object& back() const;
	void advance();
	void Add(const Object& e);
	void remove();

private:
	struct CNode {
		Object elem;
		CNode* next;
	};

	CNode* cursor;
};

#endif
