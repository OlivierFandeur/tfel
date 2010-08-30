/*!
 * \file   TestResult.cxx
 * \author Helfer Thomas <helferthomas@free.fr>
 * \date   10 Apr 10
 * \brief  
 */

#include"TFEL/Tests/TestResult.hxx"

namespace tfel
{

  namespace tests
  {

    TestResult::TestResult()
      : d(),
	s(true)
    {} // end of TestResult::TestResult

    TestResult::TestResult(const bool b)
      : d(),
	s(b)
    {} // end of TestResult::TestResult

    TestResult::TestResult(const bool b,
			   const char * const c)
      : d(c),
	s(b)
    {} // end of TestResult::TestResult
    
    TestResult::TestResult(const bool b,
			   const std::string& c)
      : d(c),
	s(b)
    {} // end of TestResult::TestResult
    
    TestResult::TestResult(const TestResult& src)
      : std::vector<TestResult>(src),
	d(src.d),
	s(src.s)
    {} // end of TestResult::TestResult

    TestResult&
    TestResult::operator = (const TestResult& src)
    {
      using namespace std;
      if(&src!=this){
	this->d = src.d;
	this->s = src.s;
	vector<TestResult>::operator=(src);
      }
      return *this;
    } // end of TestResult::operator = 

    bool
    TestResult::success() const
    {
     return this->s;
    } // end of TestResult::succees

    const std::string&
    TestResult::details() const
    {
     return this->d;
    } // end of TestResult::succees

    TestResult::const_iterator
    TestResult::begin() const
    {
      using namespace std;
      return vector<TestResult>::begin();
    } // end of TestResult::begin()

    TestResult::const_iterator
    TestResult::end() const
    {
      using namespace std;
      return vector<TestResult>::end();
    } // end of TestResult::end()

    void
    TestResult::append(const TestResult& r)
    {
      using namespace std;
      if(!r.success()){
	this->s = false;
      }
      vector<TestResult>::push_back(r);
    } // end of TestResult::end()

    std::ostream&
    operator << (std::ostream& os,const TestResult& r)
    {
      using namespace std;
      TestResult::const_iterator p;
      os << "Result : ";
      if(r.success()){
	os << "SUCCESS";
      } else {
	os << "FAILED";
      }
      os << endl;
      os << "Details : " << r.details() << endl;
      for(p=r.begin();p!=r.end();++p){
	os << *p << endl;
      }
      return os;
    } // end of operator <<  

  } // end of namespace tests

} // end of namespace tfel
