#include <kdemacros.h>
extern "C" int kdemain(int argc, char* argv[]);
extern "C" KDE_EXPORT int tdeinitmain(int argc, char* argv[]) { return kdemain(argc,argv); }
