/*!
 * \file   mfront/include/MFront/MFrontVirtualParser.hxx
 * \brief  
 * 
 * \author Helfer Thomas
 * \date   09 nov 2006
 * \copyright Copyright (C) 2006-2014 CEA/DEN, EDF R&D. All rights 
 * reserved. 
 * This project is publicly released under either the GNU GPL Licence 
 * or the CECILL-A licence. A copy of thoses licences are delivered 
 * with the sources of TFEL. CEA or EDF may also distribute this 
 * project under specific licensing conditions. 
 */

#ifndef _LIB_MFRONTVIRTUALPARSER_HXX_
#define _LIB_MFRONTVIRTUALPARSER_HXX_ 

#include<string>
#include<map>
#include<set>
#include<vector>

#include"TFEL/Config/TFELConfig.hxx"

namespace mfront{

  struct TFEL_VISIBILITY_EXPORT MFrontVirtualParser
  {

    virtual void treatFile(const std::string&,
			   const std::vector<std::string>&) = 0;

    virtual std::map<std::string,std::vector<std::string> >
    getGlobalIncludes(void) = 0;

    virtual std::map<std::string,std::vector<std::string> >
    getGlobalDependencies(void) = 0;

    virtual std::map<std::string,std::vector<std::string> >
    getGeneratedSources(void) = 0;

    virtual std::vector<std::string>
    getGeneratedIncludes(void) = 0;

    virtual std::map<std::string,std::vector<std::string> >
    getLibrariesDependencies(void) = 0;

    virtual std::map<std::string,
		     std::pair<std::vector<std::string>,
			       std::vector<std::string> > >
    getSpecificTargets(void) = 0;

    virtual void
    setInterfaces(const std::set<std::string>&) = 0;

    virtual void
    setAnalysers(const std::set<std::string>&) = 0;

    /*!
     * \brief return the list of keywords usable with this parser
     * \param[out] k : the list of keywords registred for this parser
     */
    virtual void
    getKeywordsList(std::vector<std::string>&) const = 0;

    virtual ~MFrontVirtualParser();
  };

} // end of namespace mfront

#endif /* _LIB_MFRONTVIRTUALPARSER_HXX */
