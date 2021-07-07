#include "conto_ordinario.h"
namespace MS{
	float ordinario::calcolo_spese()const{
		int n=m/numeroCosto;
		return n*costo;
	}
}
