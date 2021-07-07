#ifndef _TABLE_H
#define _TABLE_H
namespace MS{

typedef enum{CLASS1=1, CLASS2, CLASS3, CLASS4, CLASS5, CLASS6,CLASS7} Classes;
struct Pair{ 
	Classes L;
	float V;
};

const Pair Table[7]={{CLASS1,1.0}, {CLASS2,1.6}, {CLASS3, 2.05}, {CLASS4,2.55},{CLASS5, 3.00},{CLASS6,3.40},{CLASS7,3.90}};
//si potrebbe fare con la libreria standard
}
#endif
