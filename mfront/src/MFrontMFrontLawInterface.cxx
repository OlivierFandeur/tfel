/*!
 * \file   mfront/src/MFrontMFrontLawInterface.cxx
 * \brief    
 * \author Helfer Thomas
 * \date   06 mai 2008
 * \copyright Copyright (C) 2006-2014 CEA/DEN, EDF R&D. All rights 
 * reserved. 
 * This project is publicly released under either the GNU GPL Licence 
 * or the CECILL-A licence. A copy of thoses licences are delivered 
 * with the sources of TFEL. CEA or EDF may also distribute this 
 * project under specific licensing conditions. 
 */

#include<sstream>
#include<stdexcept>

#include"MFront/ParserUtilities.hxx"
#include"MFront/MFrontHeader.hxx"
#include"MFront/MFrontMFrontLawInterface.hxx"

namespace mfront
{

  std::string
  MFrontMFrontLawInterface::getName(void)
  {
    return "mfront";
  }

  MFrontMFrontLawInterface::MFrontMFrontLawInterface()
    : MFrontCLawInterfaceBase()
  {}

  std::map<std::string,std::vector<std::string> >
  MFrontMFrontLawInterface::getGlobalDependencies(const std::string&,
						  const std::string&,
						  const std::string&)
  {
    using namespace std;
    map<string,vector<string> > libs;
    libs["libMFrontMaterialLaw"].push_back("-lm");
    return libs;
  } // end of MFrontMFrontLawInterface::getGeneratedSources

  std::map<std::string,std::vector<std::string> >
  MFrontMFrontLawInterface::getGlobalIncludes(const std::string&,
					      const std::string&,
					      const std::string&)
  {
    using namespace std;
    return map<string,vector<string> >();
  } // end of MFrontMFrontLawInterface::getGeneratedSources

  std::map<std::string,std::vector<std::string> >
  MFrontMFrontLawInterface::getGeneratedSources(const std::string&,
						const std::string& material,
						const std::string& className)
  {
    using namespace std;
    map<string,vector<string> > src;
    string name = this->getSrcFileName(material,className);
    src["libMFrontMaterialLaw"].push_back(name+".cxx");
    return src;
  } // end of MFrontMFrontLawInterface::getGeneratedSources

  std::vector<std::string>
  MFrontMFrontLawInterface::getGeneratedIncludes(const std::string&,
						 const std::string& material,
						 const std::string& className)
  {
    using namespace std;
    vector<string> incs;
    string header = this->getHeaderFileName(material,className);
    if(!header.empty()){
      incs.push_back(header+".hxx");
    }
    return incs;
  } // end of MFrontMFrontLawInterface::getGeneratedIncludes

  std::map<std::string,std::vector<std::string> >
  MFrontMFrontLawInterface::getLibrariesDependencies(const std::string&,
						     const std::string&,
						     const std::string&)
  {
    using namespace std;
    map<string,vector<string> > libs;
    libs["libMFrontMaterialLaw"].push_back("-lm");
    return libs;
  } // end of MFrontMFrontLawInterface::getLibrariesDependencies()

  std::map<std::string,
	   std::pair<std::vector<std::string>,
		     std::vector<std::string> > >
  MFrontMFrontLawInterface::getSpecificTargets(const std::string&,
					       const std::string&,
					       const std::string&,
					       const std::vector<std::string>&)
  {
    using namespace std;
    return map<string,pair<vector<string>,vector<string> > >();
  } // end of MFrontMFrontLawInterface::getSpecificTargets

  std::string
  MFrontMFrontLawInterface::getHeaderFileName(const std::string& material,
					      const std::string& className)
  {
    if(material.empty()){
      return className+"-mfront";
    }
    return material+"_"+className+"-mfront";
  } // end of MFrontMFrontLawInterface::getHeaderFileName

  std::string
  MFrontMFrontLawInterface::getSrcFileName(const std::string& material,
					   const std::string& className)
  {
    if(material.empty()){
      return className+"-mfront";
    }
    return material+"_"+className+"-mfront";
  } // end of MFrontMFrontLawInterface::getSrcFileName
  
  void
  MFrontMFrontLawInterface::writeHeaderPreprocessorDirectives(const std::string&,
							      const std::string&)
  {
    writeExportDirectives(this->headerFile);
  } // end of MFrontMFrontLawInterface::writePreprocessorDirectives

  void
  MFrontMFrontLawInterface::writeSrcPreprocessorDirectives(const std::string&,
							   const std::string&)
  {} // end of MFrontMFrontLawInterface::writeSrcPreprocessorDirectives

  void
  MFrontMFrontLawInterface::writeBeginHeaderNamespace(void)
  {
    this->headerFile << "namespace mfront{\n";
  } // end of MFrontMFrontLawInterface::writeBeginHeaderNamespace
  
  void
  MFrontMFrontLawInterface::writeEndHeaderNamespace(void)
  {
    this->headerFile << "} // end of namespace mfront\n";
  } // end of MFrontMFrontLawInterface::writeEndHeaderNamespace(void)

  void
  MFrontMFrontLawInterface::writeBeginSrcNamespace(void)
  {
    this->srcFile << "namespace mfront{\n";
  } // end of MFrontMFrontLawInterface::writeBeginSrcNamespace
  
  void
  MFrontMFrontLawInterface::writeEndSrcNamespace(void)
  {
    this->srcFile << "} // end of namespace mfront\n";
  } // end of MFrontMFrontLawInterface::writeEndSrcNamespace(void)

  std::string
  MFrontMFrontLawInterface::getFunctionDeclaration(const std::string& material,
						   const std::string& law)
  {
    return "MFRONT_SHAREDOBJ double MFRONT_CALLING_CONVENTION\n"+this->getFunctionName(material,law);
  } // end of MFrontMFrontLawInterface::getFunctionDeclaration

  std::string
  MFrontMFrontLawInterface::getFunctionName(const std::string& material,
					    const std::string& law) const
  {
    if(material.empty()){
      return law;
    }
    return material+'_'+law;
  }
  
  bool
  MFrontMFrontLawInterface::requiresCheckBoundsFunction(void) const
  {
    return true;
  }

  std::string
  MFrontMFrontLawInterface::getCheckBoundsFunctionDeclaration(const std::string& material,
							      const std::string& className)
  {
    if(material.empty()){
      return  "MFRONT_SHAREDOBJ int MFRONT_CALLING_CONVENTION\n"+className+"_checkBounds";
    }
    return  "MFRONT_SHAREDOBJ int MFRONT_CALLING_CONVENTION\n"+material+"_"+className+"_checkBounds";
  } // end of MFrontMFrontLawInterface::getCheckBoundsFunctionDeclaration
  
  MFrontMFrontLawInterface::~MFrontMFrontLawInterface()
  {} // end of MFrontMFrontLawInterface::~MFrontMFrontLawInterface

} // end of namespace mfront