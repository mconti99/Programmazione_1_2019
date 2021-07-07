#ifndef _FISSO_H
#define _FISSO_H
#include "utenza.h"
#include "indirizzo.h"
namespace MS{
	class Fisso : public Utenza{
		friend ostream & operator<<(ostream &, const Fisso &);
		private:
			char * destinazione;
			Indirizzo i;
		protected:
			virtual ostream & print(ostream &)const;
		public:
			Fisso(): Utenza(), destinazione(new char[1]){strcpy(destinazione,"");}
			Fisso(const char * s1, const char * s2, const char * s3, const char * s4, const Indirizzo & d): Utenza(s1,s2,s3), i(d), destinazione(new char[strlen(s4)+1]){strcpy(destinazione, s4);}
			virtual ~Fisso(){delete [] destinazione;}
			Fisso(const Fisso &);
			const Fisso & operator=(const Fisso &);
			virtual bool apply()const;
	};
}
#endif
