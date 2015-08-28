/*!
 * \file   include/TFEL/System/System.hxx
 * \brief  This file declares the System class
 * \author Helfer Thomas
 * \date   06 Nov 2007
 * \copyright Copyright (C) 2006-2014 CEA/DEN, EDF R&D. All rights 
 * reserved. 
 * This project is publicly released under either the GNU GPL Licence 
 * or the CECILL-A licence. A copy of thoses licences are delivered 
 * with the sources of TFEL. CEA or EDF may also distribute this 
 * project under specific licensing conditions. 
 */

#ifndef LIB_TFEL_SYSTEM_HXX_
#define LIB_TFEL_SYSTEM_HXX_ 

#include<vector>
#include<string>

#include<sys/types.h>
#include<sys/stat.h>
#if !((defined _WIN32) || (defined _WIN64))
#include<unistd.h>
#else
#ifdef _MSC_VER
using mode_t = int;
#endif
#endif

#include"TFEL/Config/TFELConfig.hxx"
#include"TFEL/System/SystemError.hxx"

namespace tfel
{

  namespace system
  {

    /*!
     * \return the directory separator
     */
    TFELSYSTEM_VISIBILITY_EXPORT
    char dirSeparator(void);
    
    /*!
     * \return the directory separator as a string
     */
    TFELSYSTEM_VISIBILITY_EXPORT
    const std::string&
    dirStringSeparator(void);

    /*!
     * This structure contains C++ wrapping over many
     * posix system call.
     */
    struct TFELSYSTEM_VISIBILITY_EXPORT systemCall
    {

      /*
       * An helper function to convert errno values to C++ exceptions.
       * \param const std::string&, a description of the error.
       * \param const int, value of errno.
       */
      TFEL_NORETURN static void
      throwSystemError(const std::string&,
		       const int);

      /*
       * create one or more directories.
       * This command is equivalent to the shell command 'mkdir -p'.
       * \param const std::string&, path to be created.
       * \param const mode_t, opening mode.
       */
#if defined _WIN32 || defined _WIN64
      static void
      mkdir(const std::string&);
#else 
      static void
      mkdir(const std::string&,const mode_t = S_IRWXU|S_IRWXG);
#endif /* LIB_TFEL_SYSTEM_HXX_ */

      /*!
       * \param f : file to unlink
       */
      static void
      unlink(const std::string&);

      /*!
       * \param d : directory to remove
       */
      static void
      rmdir(const std::string&);

      static void
      write(const int,const void* const,size_t);

      /*
       * copy a file or a directory.
       * This command is equivalent to the shell command 'cp -R'.
       * \param const std::string&, src.
       * \param const std::string&, destination.
       */
      static void
      copy(const std::string&,const std::string&);

      // change the current working directory
      // (little wrapper of ::chdir)
      static void
      changeCurrentWorkingDirectory(const std::string&);

      // get the current working directory
      // (little wrapper of ::getwd)
      static std::string
      getCurrentWorkingDirectory(void);

      // get the current working directory
      // (little wrapper of ::getlogin_r)
      static std::string
      getUserName(void);

      // get the current working directory
      // (little wrapper of ::gethostname)
      static std::string
      getHostName(void);

    private:

      // copy a directory
      TFEL_VISIBILITY_LOCAL
      static void
      copyDirectory(const std::string&,
		    const std::string&,
		    const bool);

      // copy a file to a file
      TFEL_VISIBILITY_LOCAL
      static void
      copyFile(const std::string&,const std::string&);

      // return the type of a file
      // the mode_t shall be given by a call to stat
      TFEL_VISIBILITY_LOCAL 
      static std::string
      fileType(const mode_t);

      // an helper function
      TFEL_VISIBILITY_LOCAL 
      static std::vector<std::string>
      tokenize(const std::string&,const char);

      // an helper function
      TFEL_VISIBILITY_LOCAL 
      static std::vector<std::string>
      tokenize(const std::string&,const std::string&);

    }; // end of struct systemCall
  
  } // end of namespace system

} // end of namespace tfel

#endif /* LIB_TFEL_SYSTEM_HXX_ */

