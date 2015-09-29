/*!
 * \file   mfront/include/MFront/FortranMaterialPropertyInterface.hxx
 * \brief  This file declares the FortranMaterialPropertyInterface class
 * \author Helfer Thomas
 * \date   1 décembre 2008
 * \copyright Copyright (C) 2006-2014 CEA/DEN, EDF R&D. All rights 
 * reserved. 
 * This project is publicly released under either the GNU GPL Licence 
 * or the CECILL-A licence. A copy of thoses licences are delivered 
 * with the sources of TFEL. CEA or EDF may also distribute this 
 * project under specific licensing conditions. 
 */

#ifndef LIB_MFRONTFORTRANLAWINTERFACE_H_
#define LIB_MFRONTFORTRANLAWINTERFACE_H_ 

#include"MFront/CMaterialPropertyInterfaceBase.hxx"

namespace mfront{

  struct FortranMaterialPropertyInterface
    : public CMaterialPropertyInterfaceBase
  {
    static std::string 
    getName(void);
    
    FortranMaterialPropertyInterface();
    /*!
     * \brief : fill the target descripton
     * \param[out] d   : target description
     * \param[in]  mpd : material property description
     */
    virtual void getTargetsDescription(TargetsDescription&,
				       const MaterialPropertyDescription&) override;
    //! destructor
    virtual ~FortranMaterialPropertyInterface();
        
  private:

    virtual void
    writeParameterList(std::ostream&,
		       const VariableDescriptionContainer&) override;

    virtual void
    writeInterfaceSpecificVariables(const VariableDescriptionContainer&) override;

    virtual void
    writeSrcPreprocessorDirectives(const MaterialPropertyDescription&) override;

    virtual void
    writeBeginHeaderNamespace(void) override;

    virtual void
    writeEndHeaderNamespace(void) override;

    virtual void
    writeBeginSrcNamespace(void) override;

    virtual void
    writeEndSrcNamespace(void) override;

    /*!
     * \param const std::string&, name of the material
     * \param const std::string&, name of the class
     */
    virtual std::string
    getHeaderFileName(const std::string&,
		      const std::string&) const override;

    /*!
     * \param const std::string&, name of the material
     * \param const std::string&, name of the class
     */
    virtual std::string
    getSrcFileName(const std::string&,
		   const std::string&) const override;

    /*!
     * \param const std::string&, name of the material
     * \param const std::string&, name of the class
     */
    virtual std::string
    getFunctionName(const std::string&,
		    const std::string&) const override;

    /*!
     * \param const std::string&, name of the material
     * \param const std::string&, name of the class
     */
    virtual std::string
    getCheckBoundsFunctionName(const std::string&,
			       const std::string&) const override;

    virtual bool
    requiresCheckBoundsFunction(void) const override;

  }; // end of MfrontFortranMaterialPropertyInterface

} // end of namespace mfront

#endif /* LIB_MFRONTFORTRANLAWINTERFACE_H_ */
