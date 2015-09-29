/*!
 * \file   mfront/src/DSLUtilities.cxx
 * \brief  
 * 
 * \author Helfer Thomas
 * \date   23 oct 2008
 * \copyright Copyright (C) 2006-2014 CEA/DEN, EDF R&D. All rights 
 * reserved. 
 * This project is publicly released under either the GNU GPL Licence 
 * or the CECILL-A licence. A copy of thoses licences are delivered 
 * with the sources of TFEL. CEA or EDF may also distribute this 
 * project under specific licensing conditions. 
 */

#include<stdexcept>
#include<fstream>
#include<sstream>

#include"TFEL/Config/TFELConfig.hxx"
#include"TFEL/Glossary/GlossaryEntry.hxx"
#include"MFront/MFrontDebugMode.hxx"
#include"MFront/DSLUtilities.hxx"

#ifndef _MSC_VER
static const char * const constexpr_c = "constexpr";
#else
static const char * const constexpr_c = "const";
#endif

namespace mfront
{

  void
  writeMaterialLaws(const std::string&,
		    std::ofstream& srcFile,
		    const std::vector<std::string>& materialLaws)
  {
    using namespace std;
    vector<string>::const_iterator p;
    for(p=materialLaws.begin();p!=materialLaws.end();++p){
      srcFile << "using mfront::" << *p << ";" << endl;
      srcFile << "using mfront::" << *p << "_checkBounds;" << endl;
    }
  } // end of writeMaterialLaws

  void
  writeStaticVariables(const std::string& method,
		       std::ofstream& srcFile,
		       const StaticVariableDescriptionContainer& staticVars,
		       const std::string& file)
  {
    using namespace std;
    StaticVariableDescriptionContainer::const_iterator p;
    // static variables
    if(!staticVars.empty()){
      for(p=staticVars.begin();p!=staticVars.end();++p){
	if(getDebugMode()){
	  srcFile << "#line " << p->lineNumber << " \"" 
		  << file << "\"\n";
	}
	if(p->type=="short"){
	  srcFile << "static " << constexpr_c << "  short " << p->name 
		  << " = " << static_cast<short>(p->value) << ";" << endl;
	} else if(p->type=="ushort"){
	  srcFile << "static " << constexpr_c << "  unsigned short "  << p->name 
		  << " = " << static_cast<unsigned short>(p->value) << ";" << endl;
	} else if(p->type=="int"){
	  srcFile << "static " << constexpr_c << "  int " << p->name 
		  << " = " << static_cast<int>(p->value) << ";" << endl;
	} else if(p->type=="uint"){
	  srcFile << "static " << constexpr_c << "  unsigned int " << p->name 
		  << " = " << static_cast<unsigned int>(p->value) << ";" << endl;
	} else if(p->type=="long"){
	  srcFile << "static " << constexpr_c << "  long " << p->name 
		  << " = " << static_cast<long>(p->value) << ";" << endl;
	} else if(p->type=="ulong"){
	  srcFile << "static " << constexpr_c << "  unsigned long " << p->name 
		  << " = " << static_cast<unsigned long>(p->value) << ";" << endl;
	} else if(p->type=="float"){
	  srcFile << "static " << constexpr_c << "  float " << p->name 
		  << " = " << static_cast<float>(p->value) << ";" << endl;
	} else if((p->type=="double")||(p->type=="real")){
	  srcFile << "static " << constexpr_c << "  double " << p->name 
		  << " = " << static_cast<double>(p->value) << ";" << endl;
	} else if(p->type=="ldouble"){
	  srcFile << "static " << constexpr_c << "  long double " << p->name 
		  << " = " << static_cast<long double>(p->value) << ";" << endl;
	} else {
	  ostringstream msg;
	  msg << method << "type '" + p->type 
	      << "' is not a supported type for a static variable."
	      << "Supported types are short, ushort, int, uint, long, ulong,"
	      << "float, double and ldouble.\n"
	      << "Error at line " << p->lineNumber << ".";
	  throw(runtime_error(msg.str()));
	}
      }
      srcFile << endl;
    }

  } // end of writeStaticVariables(std::ofstream&,const StaticVariableDescriptionContainer&)

  std::string
  getMaterialLawLibraryNameBase(const std::string& library,
				const std::string& material)
  {
    using namespace std;
    if(library.empty()){
      if(material.empty()){
	return "MaterialLaw";
      }
      return material;
    }
    return library;
  } // end of getLibraryNameBase

  void
  writeF77FUNCMacros(std::ostream& f)
  {
    auto def = [&f](void){
    f << "#ifndef F77_FUNC\n"
      << "#define F77_FUNC(X,Y) X##_\n"
      << "#endif\n"
      << "#ifndef F77_FUNC_\n"
      << "#define F77_FUNC_(X,Y) X##_\n"
      << "#endif\n";
    };
    f << "#if (defined GNU_FORTRAN_COMPILER)\n";
    def();
    f << "#elif (defined INTEL_FORTRAN_COMPILER)\n";
    f << "#ifdef _WIN32\n";
    f << "#ifndef F77_FUNC\n"
      << "#define F77_FUNC(X,Y) Y\n"
      << "#endif\n"
      << "#ifndef F77_FUNC_\n"
      << "#define F77_FUNC_(X,Y) Y\n"
      << "#endif\n";
    f << "#else\n";
    def();
    f << "#endif /* _WIN32 */\n";
    f << "#else\n";
    def();
    f << "#endif\n\n";
  } // end of writeF77FuncMacros
  
  void
  writeExportDirectives(std::ostream& file)
  {
    file << "#ifdef _WIN32\n";
    file << "#ifndef NOMINMAX\n";
    file << "#define NOMINMAX\n";
    file << "#endif /* NOMINMAX */\n";
    file << "#include <windows.h>\n";
    file << "#ifndef MFRONT_SHAREDOBJ\n";
    file << "#ifdef  MFRONT_COMPILING\n";
    file << "#define MFRONT_SHAREDOBJ __declspec(dllexport)\n"; 
    file << "#else /* MFRONT_COMPILING */\n";
    file << "#define MFRONT_SHAREDOBJ __declspec(dllimport)\n"; 
    file << "#endif /* MFRONT_COMPILING */\n";
    file << "#endif /* MFRONT_SHAREDOBJ */\n"; 
    file << "#else\n";
    file << "#ifndef MFRONT_SHAREDOBJ\n";
    file << "#ifdef __GNUC__\n";
    file << "#define MFRONT_SHAREDOBJ __attribute__((visibility(\"default\")))\n";
    file << "#else\n";
    file << "#define MFRONT_SHAREDOBJ\n";
    file << "#endif /* __GNUC__ */\n";
    file << "#endif /* MFRONT_SHAREDOBJ */\n"; 
    file << "#endif /* _WIN32 */\n\n";
  } // end of writeExportDirectives

  std::string 
  makeUpperCase(const std::string& n)
  {
    using namespace std;
    string s(n);
    string::const_iterator p;
    string::iterator p2;
    for(p=n.begin(),p2=s.begin();p!=n.end();++p,++p2){
      *p2 = static_cast<char>(toupper(*p));
    }
    return s;
  } // end of makeUpperCase

  std::string 
  makeLowerCase(const std::string& n)
  {
    using namespace std;
    string s(n);
    string::const_iterator p;
    string::iterator p2;
    for(p=n.begin(),p2=s.begin();p!=n.end();++p,++p2){
      *p2 = static_cast<char>(tolower(*p));
    }
    return s;
  } // end of makeLowerCase

  void
  displayGlossaryEntryCompleteDescription(std::ostream& os,
					  const tfel::glossary::GlossaryEntry& e)
  {
    using namespace std;
    const auto& k = e.getKey();
    const auto& n = e.getNames();
    const auto& sd = e.getShortDescription();
    const auto& d = e.getDescription();
    if((!sd.empty())||(!d.empty())){
      os << endl
	 << "For your information, the description of the glossary entry '" << k << "' is:" << endl;
      if(!n.empty()){
	os << k << ":" ;
	for(const auto & elem : n){
	  os << " '" << elem << "'";
	}
	os << endl;
      }
      if(!sd.empty()){
	os << sd << endl;
      }
      if(!d.empty()){
	for(const auto & elem : d){
	  os << elem << endl;
	}
      }
    }
  } // end of displayGlossaryEntryCompleteDescription

} // end of namespace mfront