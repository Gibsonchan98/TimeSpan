//
// Timespan Created by Melanie Palomino on 01/16/2020.
//

#include "timespan.h"
#include <cassert>
#include <sstream>

using namespace std;

// testing constructor
void test1() {
    TimeSpan ts(1, 20, 30);
    stringstream ss;
    ss << ts;
    cout << ts << endl; //special tester
    assert(ss.str() == "1:20:30");

    TimeSpan ts2(4, -20, -90);
    ss.str("");
    ss << ts2;
    cout << ts2 << endl; //special tester
    assert(ss.str() == "3:38:30");

    TimeSpan ts3(1.5, 30.5,-90);
    ss.str("");
    ss << ts3;
    cout << ts3 << endl; //special tester
    assert(ss.str() == "1:59:00");

    TimeSpan ts4(0, 0.07, 0);
    ss.str("");
    ss << ts4;
    cout << ts4 << endl; //special tester
    assert(ss.str() == "0:00:04");

    TimeSpan ts5(1,-2.5, 6);
    ss.str("");
    ss << ts5;
    cout << ts5 << endl; //special tester
    assert(ss.str() == "0:57:36");

    TimeSpan ts6(6.08,-5.5, -10);
    ss.str("");
    ss << ts6;
    cout << ts6 << endl; //special tester
    assert(ss.str() == "5:59:08");
}

// testing equality, addition, subtraction, multiplication
void test2() {
    TimeSpan ts(1, 20, 30);
    TimeSpan ts2(1, 20, 30);
    TimeSpan ts3(0, 0, 0);
    assert(ts == ts2);
    //testing w/ cout
    cout << ts << " == " << ts2 << endl;
    //end of test
    assert(!(ts != ts2));
    //testing w/ cout
    cout << ts << " != " << ts2 << endl;
    //end of test
    assert(ts != ts3);
    //testing w/ cout
    cout << ts << " != " << ts3 << endl;
    //end of test
    assert((ts + ts + ts) == (ts2 * 3));
    //testing w/ cout
    cout << ts + ts + ts << endl;
    cout << ts2 * 3 << endl ;
    //end of test
    assert((ts * 5) == (ts2 * 4) + ts2);
    //testing w/ cout
    cout << ts * 5 << " == ";
    cout <<((ts2 * 4) + ts2) << endl ;
    //end of test
    assert((ts * 5) == ((ts2 * 6) - ts2));
    //testing w/ cout
    cout << ts * 5 << " == ";
    cout <<((ts2 * 6)) - ts2 << endl ;
    //end of test
    assert((ts + ts - ts) == ((ts2 * 2) - ts));
    //testing w/ cout
    cout << ts + ts - ts << " == ";
    cout <<((ts2 * 2) - ts) << endl ;
    //end of test
    assert((ts - ts2) == ts3);
    //testing w/ cout
    cout << ts - ts2 << " == ";
    cout << ts3 << endl ;
    //end of test
    assert((ts3 * 5) == ts3);
    //testing w/ cout
    cout << ts3 * 5 << " == ";
    cout << ts3 << endl ;
    //end of test
}
//testing subtration from lower value
void test3() {
    TimeSpan ts0(0, 0, 0);
    TimeSpan ts1(0, 0, 1);
    TimeSpan ts2 = ts0 - ts1;
    stringstream ss;
    ss << ts2;
    cout << ts2 << endl; //special tester
    assert(ss.str() == "-0:00:01");

    TimeSpan tsI(0, 20, 0);
    TimeSpan tsII(5, 20, 3);
    TimeSpan tsIII = tsI - tsII;
    stringstream ssI;
    ssI << tsIII;
    cout << tsIII << endl; //special tester
    assert(ssI.str() == "-5:00:03");
}
//testing greater than or equal to, less than or equal to, +=, and -=
void test4(){
    TimeSpan ts(1, 15, 30);
    TimeSpan ts2(1, 3.4, -75);
    TimeSpan ts3(1, 1, 1);
    assert(ts >= ts2);
    //testing w/ cout
    cout << ts << " >= " << ts2 << endl;
    //end of test
    assert(!(ts <= ts2));
    //testing w/ cout
    cout << "!(" << ts << " <= ";
    cout << ts2 << ")" << endl;
    //end of test
    assert(ts != (ts2 += ts3));
    //testing w/ cout
    cout << ts << " != " << (ts2+=ts3) << endl;
    //end of test
    assert(ts >= (ts -= ts3));
    //testing w/ cout
    cout << ts << " >= " << (ts -= ts3 ) << endl;
    //end of test
    assert(ts > (ts3 - ts2));
    //testing w/ cout
    cout << ts << " > " << (ts3 - ts2 ) << endl;
    //end of test
    assert(!((ts - ts2)*2 < ts2));
    //testing w/ cout
    cout <<"!(" << (ts - ts2) *2;
    cout << " < " << (ts2) << ")"<<endl;
    //end of test
}
void testAll() {
    test1();
    test2();
    test3();
    test4();
}

int main() {
    testAll();
    cout << "Passed all tests. Done." << std::endl;
    return 0;
}
