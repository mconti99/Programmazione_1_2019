#ifndef _MOBILE_H
#define _MOBILE_H
#include "utenza.h"
#include "eccezione.h"
#define L1 "rete 4G con scatto alla risposta"
#define L2 "rete 5G con minuti e SMS illimitati"
namespace MS{
	class Mobile : public Utenza{
		friend ostream & operator<<(ostream &, const Mobile &);
		private:
			string profilo;
		protected:
			virtual ostream & print(ostream &)const;
		public:
			Mobile(): Utenza(), profilo(""){}
			Mobile(const char * s1, const char * s2, const char * s3, const string & p): Utenza(s1,s2,s3), profilo(p){}
			virtual bool apply()const;
			bool check_n()const throw(Eccezione &);
	};
}
#endif
