#include <vector>
#include <iostream>

#ifdef WITHGPERFTOOLS
#include <gperftools/profiler.h>
#endif

using namespace std;

int foo(vector<int> v) {
    int result = 0;
    for(auto x: v) {
        result += x;
    }
    return result % 1000;
}

int main() {
#ifdef WITHGPERFTOOLS
    ProfilerStart("profile.log");
#endif
    vector<int> v;
    v.push_back(1);
    
    int result = 0;
    for (int i=0; i<10000; i++) {
        result = foo(v);
        v.push_back(result);
    }
#ifdef WITHGPERFTOOLS
    ProfilerStop();
#endif
    cout << result << "\n";
    return 1;
}