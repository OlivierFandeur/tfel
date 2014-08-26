/*! 
 * \file  AsterTangentOperator.cxx
 * \brief
 * \author Helfer Thomas
 * \brief 07 févr. 2013
 */

#include<cmath>
#include<algorithm>

#include"TFEL/Math/t2tost2.hxx"
#include"TFEL/Math/st2tost2.hxx"
#include"MFront/Aster/AsterTangentOperator.hxx"

namespace aster
{

  static inline unsigned short
  getRowIndex(const unsigned short i)
  {
    switch(i){
    case 0:
      return 0;
    case 1:
      return 1;
    case 2:
      return 2;
    case 3:
      return 0;
    case 4:
      return 1;
    case 5:
      return 0;
    case 6:
      return 2;
    case 7:
      return 1;
    case 8:
      return 2;
    }
    return 0;
  }
  
  static inline unsigned short
  getColumnIndex(const unsigned short j)
  {
    switch(j){
    case 0:
      return 0;
    case 1:
      return 1;
    case 2:
      return 2;
    case 3:
      return 1;
    case 4:
      return 0;
    case 5:
      return 2;
    case 6:
      return 0;
    case 7:
      return 2;
    case 8:
      return 1;
    }
    return 0;
  }

  void
  AsterTangentOperator::normalize(tfel::math::t2tost2<1u,AsterReal>& Dt)
  {
    using namespace std;
    using namespace tfel::math;
    t2tost2<1u,AsterReal> k(Dt);
    const unsigned short n1 = 3u; // stensor size
    const unsigned short n2 = 3u; // tensor  size
    // values as a continous array
    AsterReal *v = Dt.begin();
    // initializing v to 0
    // we explicitely don't use the size member, but the size of real
    // underlying array provided by Aster
    fill(v,v+54/* 6*3*3*/,real(0));
    for(unsigned short i=0;i!=n1;++i){    // boucle sur tau
      for(unsigned short j=0;j!=n2;++j){  // boucle sur F
	const unsigned short mi = getRowIndex(j);
	const unsigned short mj = getColumnIndex(j);
	v[i+n1*(mi+3*mj)] = k(i,j);
      }
    }
  } // end of AsterTangentOperator::normalize
  
  void
  AsterTangentOperator::normalize(tfel::math::t2tost2<2u,AsterReal>& Dt)
  {
    using namespace std;
    using namespace tfel::math;
    t2tost2<2u,AsterReal> k(Dt);
    const unsigned short n1 = 4u; // stensor size
    const unsigned short n2 = 5u; // tensor  size
    // values as a continous array
    AsterReal *v = Dt.begin();
    // initializing v to 0
    // we explicitely don't use the size member, but the size of real
    // underlying array provided by Aster
    fill(v,v+54/*6*3*3*/,real(0));
    for(unsigned short i=0;i!=n1;++i){    // boucle sur tau
      for(unsigned short j=0;j!=n2;++j){  // boucle sur F
	const unsigned short mi = getRowIndex(j);
	const unsigned short mj = getColumnIndex(j);
	v[i+n1*(mi+3*mj)] = k(i,j);
      }
    }
  } // end of AsterTangentOperator::normalize
  
  void
  AsterTangentOperator::normalize(tfel::math::t2tost2<3u,AsterReal>& Dt)
  {
    using namespace tfel::math;
    t2tost2<3u,AsterReal> k(Dt);
    const unsigned short n1 = 6u; // stensor size
    const unsigned short n2 = 9u; // tensor  size
    // values as a continous array
    AsterReal *v = Dt.begin();
    for(unsigned short i=0;i!=n1;++i){    // boucle sur tau
      for(unsigned short j=0;j!=n2;++j){  // boucle sur F
	const unsigned short mi = getRowIndex(j);
	const unsigned short mj = getColumnIndex(j);
	v[i+n1*(mi+3*mj)] = k(i,j);
      }
    }
  } // end of struct AsterTangentOperator

  void
  AsterTangentOperator::transpose(tfel::math::t2tost2<1u,AsterReal>&)
  {}

  void
  AsterTangentOperator::transpose(tfel::math::t2tost2<2u,AsterReal>&)
  {}

  void
  AsterTangentOperator::transpose(tfel::math::t2tost2<3u,AsterReal>&)
  {}

  void
  AsterTangentOperator::normalize(tfel::math::st2tost2<1u,AsterReal>&)
  {} // end of AsterTangentOperator::normalize

  void
  AsterTangentOperator::normalize(tfel::math::st2tost2<2u,AsterReal>& Dt)
  {
    using namespace std;
    static const AsterReal inv_sqrt2 = 1./std::sqrt(AsterReal(2));
    Dt(0,3) *= inv_sqrt2;
    Dt(1,3) *= inv_sqrt2;
    Dt(2,3) *= inv_sqrt2;
    Dt(3,0) *= inv_sqrt2;
    Dt(3,1) *= inv_sqrt2;
    Dt(3,2) *= inv_sqrt2;
    Dt(3,3) *= 0.5;
  } // end of AsterTangentOperator::normalize
  
  void
  AsterTangentOperator::normalize(tfel::math::st2tost2<3u,AsterReal>& Dt)
  {
    using namespace std;
    static const AsterReal inv_sqrt2 = 1./std::sqrt(AsterReal(2));
    Dt(0,3) *= inv_sqrt2;
    Dt(1,3) *= inv_sqrt2;
    Dt(2,3) *= inv_sqrt2;
    Dt(0,4) *= inv_sqrt2;
    Dt(1,4) *= inv_sqrt2;
    Dt(2,4) *= inv_sqrt2;
    Dt(0,5) *= inv_sqrt2;
    Dt(1,5) *= inv_sqrt2;
    Dt(2,5) *= inv_sqrt2;
    Dt(3,0) *= inv_sqrt2;
    Dt(3,1) *= inv_sqrt2;
    Dt(3,2) *= inv_sqrt2;
    Dt(4,0) *= inv_sqrt2;
    Dt(4,1) *= inv_sqrt2;
    Dt(4,2) *= inv_sqrt2;
    Dt(5,0) *= inv_sqrt2;
    Dt(5,1) *= inv_sqrt2;
    Dt(5,2) *= inv_sqrt2;
    Dt(3,3) *= 0.5;
    Dt(3,4) *= 0.5;
    Dt(3,5) *= 0.5;
    Dt(4,3) *= 0.5;
    Dt(4,4) *= 0.5;
    Dt(4,5) *= 0.5;
    Dt(5,3) *= 0.5;
    Dt(5,4) *= 0.5;
    Dt(5,5) *= 0.5;
  } // end of struct AsterTangentOperator

  void
  AsterTangentOperator::transpose(tfel::math::st2tost2<1u,AsterReal>& Dt)
  {
    std::swap(Dt(0,1),Dt(1,0));
    std::swap(Dt(0,2),Dt(2,0));
    std::swap(Dt(1,2),Dt(2,1));
  }

  void
  AsterTangentOperator::transpose(tfel::math::st2tost2<2u,AsterReal>& Dt)
  {
    std::swap(Dt(0,1),Dt(1,0));
    std::swap(Dt(0,2),Dt(2,0));
    std::swap(Dt(0,3),Dt(3,0));
    std::swap(Dt(1,2),Dt(2,1));
    std::swap(Dt(1,3),Dt(3,1));
    std::swap(Dt(2,3),Dt(3,2));
  }

  void
  AsterTangentOperator::transpose(tfel::math::st2tost2<3u,AsterReal>& Dt)
  {
    std::swap(Dt(0,1),Dt(1,0));
    std::swap(Dt(0,2),Dt(2,0));
    std::swap(Dt(0,3),Dt(3,0));
    std::swap(Dt(0,4),Dt(4,0));
    std::swap(Dt(0,5),Dt(5,0));
    std::swap(Dt(1,2),Dt(2,1));
    std::swap(Dt(1,3),Dt(3,1));
    std::swap(Dt(1,4),Dt(4,1));
    std::swap(Dt(1,5),Dt(5,1));
    std::swap(Dt(2,3),Dt(3,2));
    std::swap(Dt(2,4),Dt(4,2));
    std::swap(Dt(2,5),Dt(5,2));
    std::swap(Dt(3,4),Dt(4,3));
    std::swap(Dt(3,5),Dt(5,3));
    std::swap(Dt(4,5),Dt(5,4));
  }

  void
  AsterTangentOperator::normalize(tfel::math::tmatrix<1u,1u,AsterReal>&)
  {} // end of AsterTangentOperator::normalize

  void
  AsterTangentOperator::normalize(tfel::math::tmatrix<2u,2u,AsterReal>&)
  {} // end of AsterTangentOperator::normalize
  
  void
  AsterTangentOperator::normalize(tfel::math::tmatrix<3u,3u,AsterReal>&)
  {} // end of struct AsterTangentOperator

  void
  AsterTangentOperator::transpose(tfel::math::tmatrix<1u,1u,AsterReal>&)
  {}

  void
  AsterTangentOperator::transpose(tfel::math::tmatrix<2u,2u,AsterReal>& Dt)
  {
    std::swap(Dt(0,1),Dt(1,0));
  }

  void
  AsterTangentOperator::transpose(tfel::math::tmatrix<3u,3u,AsterReal>& Dt)
  {
    std::swap(Dt(0,1),Dt(1,0));
    std::swap(Dt(0,2),Dt(2,0));
    std::swap(Dt(0,3),Dt(3,0));
  }
  
} // end of namespace aster
