/*!
 * \file  include/TFEL/Math/Forward/stensor.hxx
 * \brief This file introduces some forward declaration relative to
 * the stensor class.
 * \author Thomas Helfer
 * \brief 19 sept. 2011
 * \copyright Copyright (C) 2006-2018 CEA/DEN, EDF R&D. All rights
 * reserved.
 * This project is publicly released under either the GNU GPL Licence
 * or the CECILL-A licence. A copy of thoses licences are delivered
 * with the sources of TFEL. CEA or EDF may also distribute this
 * project under specific licensing conditions.
 */

#ifndef LIB_TFEL_MATH_FORWARD_STENSOR_HXX
#define LIB_TFEL_MATH_FORWARD_STENSOR_HXX

#include "TFEL/Math/General/MathObjectTraits.hxx"

namespace tfel::math {

  /*!
   * \class stensor
   * \brief symmetric tensor.
   * \tparam N: the spatial dimension, see StensorDimeToSize for details.
   * \tparam T: numerical type used, by default, double
   * \pre   This class is only defined for N=1u,2u and 3u.
   * \see   StensorDimeToSize and StensorSizeToDime.
   */
  template <unsigned short N, typename T = double>
  struct stensor;

  /*!
   * \brief partial specialisation of the `MathObjectTraits` class.
   * \tparam N: space dimension
   * \tparam T: numeric type
   */
  template <unsigned short N, typename T>
  struct MathObjectTraits<stensor<N, T>> {
    //! \brief numeric type
    using NumType = T;
    //! \brief index type
    using IndexType = unsigned short;
    //! \brief space dimension
    static constexpr unsigned short dime = N;
  }; // end of MathObjectTraits

}  // end of namespace tfel::math

#endif /* LIB_TFEL_MATH_FORWARD_STENSOR_HXX */
