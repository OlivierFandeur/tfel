/*!
 * \file   mfront/src/MFrontDefaultParser.cxx
 * \brief  
 * \author Helfer Thomas
 * \date   08 nov 2006
 * \copyright Copyright (C) 2006-2014 CEA/DEN, EDF R&D. All rights 
 * reserved. 
 * This project is publicly released under either the GNU GPL Licence 
 * or the CECILL-A licence. A copy of thoses licences are delivered 
 * with the sources of TFEL. CEA or EDF may also distribute this 
 * project under specific licensing conditions. 
 */

#include<string>
#include<fstream>
#include<stdexcept>

#include"MFront/MFrontBehaviourVirtualInterface.hxx"
#include"MFront/MFrontBehaviourInterfaceFactory.hxx"
#include"MFront/MFrontDefaultParser.hxx"

namespace mfront{

  MFrontDefaultParser::MFrontDefaultParser()
    : MFrontDefaultParserBase()
  {
    this->registerVariable("eto",false);
    this->registerVariable("deto",false);
    this->registerVariable("sig",false);
    this->registerNewCallBack("@RequireStiffnessTensor",
			      &MFrontDefaultParser::treatRequireStiffnessOperator);
    this->mb.declareAsASmallStrainStandardBehaviour();
  }

  std::string
  MFrontDefaultParser::getDescription(void)
  {
    return "this parser is the most generic one as it does not make any restriction "
           "on the behaviour or the integration method that may be used";
  } // end of MFrontDefaultParser::getDescription
  
  std::string
  MFrontDefaultParser::getName(void)
  {
    return "DefaultParser";
  }

  MFrontDefaultParser::~MFrontDefaultParser()
  {} // end of MFrontDefaultParser::~MFrontDefaultParser

} // end of namespace mfront  