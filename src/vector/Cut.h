#ifndef CUT_H_
#define CUT_H_

#include <fstream>
#include <iostream>
#include "boost/format.hpp"

#include "Primitives.h"

#ifndef VECTOR_POWER_DEFAULT
#define VECTOR_POWER_DEFAULT (80)
#endif

class Cut {
public:
	VecPolyline polylines;
	LstEdge freeEdges;
	MapVertex vertices;

	void createEdge(Vertex *start, Vertex *end, int power);
	void removeEdge(Edge *e, bool detach);
	LstEdge::iterator removeEdge(LstEdge::iterator it_e, bool detach);
	void load(const string &filename);
	Vertex* mapVertex(Vertex* p);

	bool wasClipped() const {
		return this->clipped;
	}
	void xml(std::string s);
	// Print debug info
	void print(ostream &stream);
	friend ostream& operator <<(ostream &os, Cut &cut);
	Cut() : clipped(false) {}
private:
	bool clipped;
	virtual ~Cut() {}
};


#endif
