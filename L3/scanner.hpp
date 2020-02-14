#ifndef __EECS_SCANNER_HPP
#define __EECS_SCANNER_HPP

#if !defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

#include "grammar.hh"

#include <istream>
#include <ostream>
#include <fstream>
using namespace std;
namespace EECS{
	class Scanner : yyFlexLexer{
		public:
			Scanner(std::istream * in) : yyFlexLexer(in){
			lineNum = 0;
			charNum = 0;
			}

			virtual ~Scanner(){}

			virtual int yylex(EECS::Parser::semantic_type * lval);

			void warn(int lineNum, int charNum, std::string msg)
			{
				cerr << "Lex problem at line: " << lineNum << ", " << charNum << "***WARNING***: " << msg << '\n';
			}
			void error(int lineNum, int charNum, std::string msg)
			{
				cerr << "Lex problem at line: " << lineNum << ", " << charNum << "***ERROR***: " << msg << '\n';
			}
		private:
			EECS::Parser::semantic_type *yylval = nullptr;
			size_t lineNum;
			size_t charNum;
		}; /*end class*/
}/*end namespace*/
#endif
