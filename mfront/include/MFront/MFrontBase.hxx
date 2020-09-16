/*!
 * \file  MFrontBase.hxx
 * \brief
 * \author Thomas Helfer
 * \date   04 mars 2015
 * \copyright Copyright (C) 2006-2018 CEA/DEN, EDF R&D. All rights
 * reserved.
 * This project is publicly released under either the GNU GPL Licence
 * or the CECILL-A licence. A copy of thoses licences are delivered
 * with the sources of TFEL. CEA or EDF may also distribute this
 * project under specific licensing conditions.
 */

#ifndef LIB_MFRONT_MFRONTBASE_HXX
#define LIB_MFRONT_MFRONTBASE_HXX

#include <set>
#include <string>
#include <vector>
#include <memory>

#include "TFEL/Utilities/ArgumentParserBase.hxx"
#include "MFront/MFrontConfig.hxx"
#include "MFront/TargetsDescription.hxx"

namespace mfront {

  // forward declaration
  struct AbstractDSL;

  /*!
   * \brief Base class for the MFront and MFrontQuery classes
   */
  struct MFRONT_VISIBILITY_EXPORT MFrontBase {
    /*!
     * \param[in] f : file name
     * \return an abstract dsl that will handle the file
     */
    static std::shared_ptr<AbstractDSL> getDSL(const std::string&);
    //! constructor
    MFrontBase();
    //! add a new interaface
    void setInterface(const std::string&);
    //! desctructor
    virtual ~MFrontBase();

   protected:
    //! \return the current Argument
    virtual const tfel::utilities::Argument& getCurrentCommandLineArgument()
        const = 0;
    virtual bool treatUnknownArgumentBase();
    //! \brief method that must be called once all the arguments have been
    //! parsed
    virtual void finalizeArgumentsParsing();
    //! \brief treat the `--verbose` command line option
    virtual void treatVerbose();
    //! \brief treat the `--unicode-output` command line option
    virtual void treatUnicodeOutput();
    //! \brief treat the `--search-path` command line option
    virtual void treatSearchPath();
    /*!
     * \brief treat the `--intall-path` (or `--install-prefix`) command line
     * option
     */
    virtual void treatInstallPath();
    //! \brief treat the `--warning` command line option
    virtual void treatWarning();
    //! \brief treat the `--debug` command line option
    virtual void treatDebug();
    //! \brief treat the `--pedantic` command line option
    virtual void treatPedantic();
    //! \brief treat the `--interface` command line option
    virtual void treatInterface();
    //! \brief treat the `--material-identifier` command line option
    virtual void treatMaterialIdentifier();
    //! \brief treat the `--material-property-identifier` command line option
    virtual void treatMaterialPropertyIdentifier();
    //! \brief treat the `--behaviour-identifier` command line option
    virtual void treatBehaviourIdentifier();
    //! \brief treat the `--model-identifier` command line option
    virtual void treatModelIdentifier();
    /*!
     * \brief external commands specificed on the command line through
     * an `--@XXX` option. Those external commends are applied to
     * all input files.
     */
    std::vector<std::string> ecmds;
    /*!
     * \brief substitutions specificed on the command line through an
     * `--@XXX@=YYY` option: every occurrence of `XXX` in the input
     * files will be replaced by `YYY`
     */
    std::map<std::string, std::string> substitutions;
    //! \brief material identifier for the next input file
    std::string material_identifier;
    //! \brief material property identifier for the next input file
    std::string material_property_identifier;
    //! \brief behaviour identifier for the next input file
    std::string behaviour_identifier;
    //! \brief model identifier for the next input file
    std::string model_identifier;
    //! \brief list of all input files
    std::set<std::string> inputs;
    /*!
     * \brief list of interfaces declared on the command line or explicitely
     * added through the set interface method.
     */
    std::set<std::string> interfaces;
  };  // end of struct MFrontBase

  /*!
   * \return the paths to `MFront` implementations matching the given
   * pattern in the given file. Standard `MFront` files only contains one
   * implementations. `Madnex` files may contain several implementations.
   * \param[in] f: file name
   * \param[in] material_identifier: identifier of the material (may be empty).
   * \param[in] behaviour_identifier: identifier for material properties.
   * \param[in] behaviour_identifier: identifier for behaviours.
   * \param[in] model_identifier: identifier for behaviours.
   */
  MFRONT_VISIBILITY_EXPORT std::vector<std::string>
  getMFrontImplementationsPaths(const std::string&,
                                const std::string&,
                                const std::string&,
                                const std::string&,
                                const std::string&);

}  // end of namespace mfront

#endif /* LIB_MFRONT_MFRONTBASE_HXX */
