/*!
 * \file   mfront/include/MFront/CMaterialPropertyInterface.hxx
 * \brief  This file declares the CMaterialPropertyInterface class
 * \author Helfer Thomas
 * \date   06 mai 2008
 * \copyright Copyright (C) 2006-2014 CEA/DEN, EDF R&D. All rights 
 * reserved. 
 * This project is publicly released under either the GNU GPL Licence 
 * or the CECILL-A licence. A copy of thoses licences are delivered 
 * with the sources of TFEL. CEA or EDF may also distribute this 
 * project under specific licensing conditions. 
 */

#ifndef LIB_CMATERIALPROPERTYINTERFACE_H_
#define LIB_CMATERIALPROPERTYINTERFACE_H_ 

#include"MFront/CMaterialPropertyInterfaceBase.hxx"

namespace mfront{

  struct CMaterialPropertyInterface
    : public CMaterialPropertyInterfaceBase
  {
    static std::string 
    getName(void);
    
    CMaterialPropertyInterface();
    /*!
     * \brief : fill the target descripton
     * \param[out] d   : target description
     * \param[in]  mpd : material property description
     */
    virtual void getTargetsDescription(TargetsDescription&,
				       const MaterialPropertyDescription&) override;
    //! destructor
    virtual ~CMaterialPropertyInterface();
        
  protected:

    /*!
     * \return the name of the generated library
     * \param[in] l: library name (given by the `@Library` keyword)
     * \param[in] m: material name (given by the `@Material` keyword)
     */
    virtual std::string
    getGeneratedLibraryName(const std::string&,
			    const std::string&) const;

    virtual void
    writeBeginHeaderNamespace(void) override;

    virtual void
    writeEndHeaderNamespace(void) override;

    virtual void
    writeBeginSrcNamespace(void) override;

    virtual void
    writeEndSrcNamespace(void) override;
    /*!
     * \param[in] m: material name
     * \param[in] c: class name
     */
    virtual std::string
    getHeaderFileName(const std::string&,
		      const std::string&) const override;
    /*!
     * \param[in] m: material name
     * \param[in] c: class name
     */
    virtual std::string
    getSrcFileName(const std::string&,
		   const std::string&) const override;
    /*!
     * \param[in] m: material name
     * \param[in] c: class name
     */
    virtual std::string
    getFunctionName(const std::string&,
		    const std::string&) const override;

    /*!
     * \param[in] m: material name
     * \param[in] c: class name
     */
    virtual std::string
    getCheckBoundsFunctionName(const std::string&,
			       const std::string&) const override;
    /*!
     * \return true if a check bounds function is required
     */
    virtual bool
    requiresCheckBoundsFunction(void) const override;
  }; // end of CMaterialPropertyInterface

} // end of namespace mfront

#endif /* LIB_CMATERIALPROPERTYINTERFACE_H_ */
