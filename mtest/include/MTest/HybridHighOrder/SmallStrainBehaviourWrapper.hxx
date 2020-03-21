/*!
 * \file   mtest/include/MTest/HybridHighOrder/SmallStrainBehaviourWrapper.hxx
 * \brief    
 * \author Thomas Helfer
 * \date   19/03/2020
 * \copyright Copyright (C) 2006-2018 CEA/DEN, EDF R&D. All rights
 * reserved.
 * This project is publicly released under either the GNU GPL Licence
 * or the CECILL-A licence. A copy of thoses licences are delivered
 * with the sources of TFEL. CEA or EDF may also distribute this
 * project under specific licensing conditions.
 */

#ifndef LIB_MTEST_HYBRIDHIGHORDER_SMALLSTRAINBEHAVIOURWRAPPER_HXX
#define LIB_MTEST_HYBRIDHIGHORDER_SMALLSTRAINBEHAVIOURWRAPPER_HXX

#include "MTest/HybridHighOrder/BehaviourWrapperBase.hxx"

namespace mtest{

  namespace hho {

    /*!
     * \brief behaviour wrapper for small strain behaviours
     */
    struct SmallStrainBehaviourWrapper : BehaviourWrapperBase {
      /*!
       * \brief constructor
       * \param[in] b: mtest behaviour
       */
      SmallStrainBehaviourWrapper(const mtest::Behaviour&);

      ::hho::element::Behaviour::BehaviourType get_behaviour_type()
          const override;

      ::hho::element::Behaviour::Kinematic get_behaviour_kinematic()
          const override;

      //! \brief destructor
      ~SmallStrainBehaviourWrapper() noexcept;

    };  // end of struct SmallStrainBehaviour

  }  // end of namespace hho

} // end of namespace mtest

#endif /* LIB_MTEST_HYBRIDHIGHORDER_SMALLSTRAINBEHAVIOURWRAPPER_HXX */
