#include "conto_apacchetto.h"
namespace MS{
	float base::calcolo_spese()const{
	if(!franchigia || m<=gratis) return canone;
	else{
		int n=(m-gratis)/numeroCosto;
		return canone + costo*n;
	}
	}
}
